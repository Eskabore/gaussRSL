#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <libsx.h>
#include "liste.h"   // Definition du type Liste
#include "data.h"    // equation
#include "matrice.h" // matrice
#include "matriceC.h" // matrice_creuse
#include "vecteur.h" // vecteur"
#include "vue.h"


static void GaussRSL(matrice A, vecteur B, vecteur *X)
{
    int N = getNbLignes(A); // Nombre de lignes de la matrice A

    // Triangularisation de la matrice A
    for (int k = 0; k < N; k++)
    {
        // Recherche du pivot
        int pivot = k;
        for (int i = k + 1; i < N; i++)
        {
            if (fabs(getM(A, i, k)) > fabs(getM(A, pivot, k)))
            {
                pivot = i; // Stcokage de l'indice du pivot
            }
        }

        // Permutation des lignes si nécessaire
        if (pivot != k)
        {
            echangerLignesM(&A, k, pivot);
            echangerElementsV(&B, k, pivot);
        }

        // Normalisation de la ligne k de la matrice A et du vecteur B
        double pivotValue = getM(A, k, k);
        for (int j = k; j < N; j++)
        {
            setM(&A, k, j, getM(A, k, j) / pivotValue);
        }
        setV(&B, k, getV(B, k) / pivotValue);

        // Soustraction des lignes i de la matrice A et du vecteur B
        for (int i = k + 1; i < N; i++)
        {
            double factor = getM(A, i, k);
            for (int j = k; j < N; j++)
            {
                setM(&A, i, j, getM(A, i, j) - factor * getM(A, k, j));
            }
            setV(&B, i, getV(B, i) - factor * getV(B, k));
        }
    }

    // Calcul de la solution X
    for (int k = N - 1; k >= 0; k--)
    {
        double sol = getV(B, k);
        for (int i = k + 1; i < N; i++)
        {
            sol -= getM(A, k, i) * getV(*X, i);
        }
        setV(X, k, sol);
    }
}

char *FloatEnChaine(double valeur)
{
    int tailleMax = 20; // Taille maximale d'un nombre
    char *chaine = malloc(tailleMax + 1);
    if (chaine == NULL)
    {
        fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour la chaîne.\\n");
        exit(EXIT_FAILURE);
    }
    snprintf(chaine, tailleMax, "%f ", valeur); // Ajoute la valeur à la chaîne
    return chaine;
}

vecteur ChargerVecteurDepuisFichier(char *cheminFichier)
{
    vecteur v;
    lireVecteur(&v, cheminFichier);
    return v;
}

matrice convertirCreuseVersDense(matrice_creuse mc) {
    // Créer une matrice dense vide de la même taille que la matrice creuse
    matrice m = matriceNulle(getNbLignes_Creuse(mc), getNbCols_Creuse(mc));

    // Parcourez chaque élément non nul de la matrice creuse
    for (int i = 0; i < getNbLignes_Creuse(mc); i++) {
        for (int j = 0; j < getNbCols_Creuse(mc); j++) {
            T element = getM_Creuse(&mc, i, j);

            // Si l'élément est non nul, ajoutez-le à la matrice dense
            if (element != 0) {
                setM(&m, i, j, element);
            }
        }
    }

    return m;
}


matrice_creuse convertirDenseVersCreuse(matrice m)
{
    matrice_creuse mc;
    mc = matriceCreuseNulle(getNbLignes(m), getNbCols(m));

    // Parcourez chaque élément de m
    for (int i = 0; i < getNbLignes(m); i++)
    {
        for (int j = 0; j < getNbCols(m); j++)
        {
            T element = getM(m, i, j);

            // Si l'élément est non nul, ajoutez-le à mc
            if (element != 0)
            {
                setM_Creuse(&mc, i, j, element); // Utilisez setM_Creuse pour ajouter un élément
            }
        }
    }

    return mc;
}

matrice_creuse ChargerMatriceDepuisFichier(char *cheminFichier)
{
    matrice m;
    lireMatrice(&m, cheminFichier);

    // Convertir la matrice dense en une matrice creuse.
    matrice_creuse mc = convertirDenseVersCreuse(m);

    libererMatrice(&m); // Libérer la matrice dense

    return mc;
}

char *MatriceEnChaine(matrice m)
{
    int nbl = m.nbl, nbc = m.nbc;
    int maxChaineSize = nbl * nbc * 20 + nbl; // Estime la taille maximale de la chaîne

    // Alloue de la mémoire pour la chaîne
    char *chaine = malloc(maxChaineSize);
    if (chaine == NULL)
    {
        fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour la chaîne.\\n");
        exit(EXIT_FAILURE);
    }

    // Remplis la chaîne avec les valeurs de la matrice dense
    for (int i = 0; i < nbl; i++)
    {
        for (int j = 0; j < nbc; j++)
        {
            double valeur = getM(m, i, j);
            char buffer[21]; // Buffer pour stocker la représentation en chaîne de la valeur
            snprintf(buffer, 21, "%f ", valeur);
            strcat(chaine, buffer); // Ajoute la valeur à la chaîne
        }
        strcat(chaine, "\\n"); // Ajoute une nouvelle ligne
    }

    return chaine;
}

char *MatriceCreuseEnChaine(matrice_creuse *mc)
{
    int nbl = mc->nbl;
    int nbc = mc->nbc;
    int maxChaineSize = nbl * nbc * 20 + nbl; // Estime la taille maximale de la chaîne

    // Alloue de la mémoire pour la chaîne
    char *chaine = malloc(maxChaineSize);
    if (chaine == NULL)
    {
        fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour la chaîne.\\n");
        exit(EXIT_FAILURE);
    }

    // Remplis la chaîne avec les valeurs de la matrice creuse
    for (int i = 0; i < nbl; i++)
    {
        for (int j = 0; j < nbc; j++)
        {
            double valeur = getM_Creuse(mc, i, j);
            char buffer[21]; // Buffer pour stocker la représentation en chaîne de la valeur
            snprintf(buffer, 21, "%f ", valeur);
            strcat(chaine, buffer); // Ajoute la valeur à la chaîne
        }
        strcat(chaine, "\\n"); // Ajoute une nouvelle ligne
    }

    return chaine;
}

char *VecteurEnChaine(vecteur v)
{
    int taille = v.taille;
    int maxChaineSize = taille * 20; // Estime la taille maximale de la chaîne

    // Alloue de la mémoire pour la chaîne
    char *chaine = malloc(maxChaineSize);
    if (chaine == NULL)
    {
        fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour la chaîne.\\n");
        exit(EXIT_FAILURE);
    }

    // Remplis la chaîne avec les valeurs du vecteur
    for (int i = 0; i < taille; i++)
    {
        double valeur = getV(v, i);
        char buffer[21]; // Buffer pour stocker la représentation en chaîne de la valeur
        snprintf(buffer, 21, "%f ", valeur);
        strcat(chaine, buffer); // Ajoute la valeur à la chaîne
    }
    return chaine;
}

vecteur ResoudreSysteme(matrice_creuse A, vecteur B)
{
    vecteur X;
    initVecteur(&X, getNbLignes_Creuse(A));  // Initialisation du vecteur solution X
    matrice m = convertirCreuseVersDense(A); // Convertir la matrice creuse en matrice dense
    GaussRSL(m, B, &X);                      // Appel de la fonction GaussRSL pour résoudre le système
    return X;                                // Retour du vecteur solution
}


// Résoudre le système et afficher la solution X.
void SolutionEtAffichage(Widget w, void *d)
{
    equation *eq = (equation *)d;

    // Initialiser le vecteur X
    initVecteur(&(eq->X), getNbLignes_Creuse(eq->A));

    // Résoudre le système avec la méthode de Gauss et stocker le résultat dans eq->X
    eq->X = ResoudreSysteme(eq->A, eq->B);

    // Convertir la matrice en chaîne de caractères et l'afficher
    char *chaine = malloc(1000); // alloue la mémoire pour la chaîne
    if (chaine == NULL)
    {
        printf("Erreur d'allocation de mémoire.\n");
        exit(1);
    }
    strcpy(chaine, MatriceCreuseEnChaine(&(eq->A)));
    SetLabel(ZoneResultat, chaine);
    free(chaine); // Libérer la mémoire allouée pour la chaîne

    // Affichez le vecteur solution dans l'interface utilisateur
    chaine = malloc(1000); // alloue la mémoire pour la chaîne
    if (chaine == NULL)
    {
        printf("Erreur d'allocation de mémoire.\n");
        exit(1);
    }
    strcpy(chaine, VecteurEnChaine(eq->X));
    SetLabel(ZoneResultat, chaine);
    free(chaine); // Libérer la mémoire allouée pour la chaîne
}

