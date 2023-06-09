#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "matrice.h"
#include "matriceC.h" // Pour la matrice creuse
#include "vecteur.h"
#include "liste.h"
#include "data.h"



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
    FILE *fichier = fopen(cheminFichier, "r");
    if (fichier == NULL)
    {
        fprintf(stderr, "Erreur : échec de l'ouverture du fichier %s.\\n", cheminFichier);
        exit(EXIT_FAILURE);
    }
    lireVecteur(&v, fichier);
    fclose(fichier);
    return v;
}

matrice_creuse ChargerMatriceDepuisFichier(char *cheminFichier)
{
    matrice m;
    FILE *fichier = fopen(cheminFichier, "r");
    if (fichier == NULL)
    {
        fprintf(stderr, "Erreur : échec de l'ouverture du fichier %s.\\n", cheminFichier);
        exit(EXIT_FAILURE);
    }
    lireMatrice(&m, fichier);
    fclose(fichier);

    // Convertir la matrice dense en une matrice creuse.
    matrice_creuse mc = convertirDenseVersCreuse(m);

    libererMatrice(&m); // Libérer la matrice dense

    return mc;
}

char *MatriceEnChaine(matrice_creuse m)
{
    int nbl = m.nbl, nbc = m.nbc;

    // Remplis la chaîne avec les valeurs de la matrice
    char *chaine;
    for (int i = 0; i < nbl; i++)
    {
        for (int j = 0; j < nbc; j++)
        {
            double valeur = getM_Creuse(m, i, j);
            char *valeurChaine = FloatEnChaine(valeur);
            strcat(chaine, valeurChaine);
            free(valeurChaine); // Libère la mémoire allouée pour la chaîne de valeur
        }
        strcat(chaine, "\\n"); // Ajoute une nouvelle ligne
    }

    return chaine;
}

char *VecteurEnChaine(vecteur v)
{
    int taille = v.taille;
    // Remplis la chaîne avec les valeurs du vecteur
    char *chaine;
    for (int i = 0; i < taille; i++)
    {
        double valeur = getV(v, i);
        char *valeurChaine = FloatEnChaine(valeur);
        strcat(chaine, valeurChaine);
        free(valeurChaine);    // Libère la mémoire allouée pour la chaîne de valeur
        strcat(chaine, "\\n"); // Ajoute une nouvelle ligne
        return chaine;
    }

}