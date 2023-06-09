#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "matriceC.h"

// Renvoie une matrice creuse nulle de taille m x n
matrice_creuse matriceCreuseNulle(const int m, const int n)
{
    matrice_creuse mc;
    mc.nbl = m;
    mc.nbc = n;
    mc.mat = NULL; // Initialise la liste à NULL
    return mc;
}

// Renvoie l'élément à la position (i, j) de la matrice creuse m
T getM_Creuse(const matrice_creuse m, const int i, const int j)
{
    assert(i >= 0 && i < m.nbl);
    assert(j >= 0 && j < m.nbc);

    Liste elements = m.mat;
    while (elements != NULL)
    {
        Triplet *e = (Triplet *)elements->elt;
        if (e->ligne == i && e->colonne == j)
        {
            return ((Triplet *)e)->valeur;
        }
        elements = elements->suivant;
    }
    return 0; // Valeur par défaut pour les éléments non trouvés
}

// Définit l'élément à la position (i, j) de la matrice creuse m à la valeur x
void setM_Creuse(matrice_creuse *m, const int i, const int j, const T x)
{
    assert(i >= 0 && i < m->nbl);
    assert(j >= 0 && j < m->nbc);

    Liste elements = m->mat;
    while (elements != NULL)
    {
        Triplet *e = (Triplet *)elements->elt;
        if (e->ligne == i && e->colonne == j)
        {
            ((Triplet *)e)->valeur = x;
            return;
        }
        elements = elements->suivant;
    }

    // Si l'élément n'existe pas encore, l'ajouter à la liste
    Triplet *nouveauTriplet = malloc(sizeof(Triplet));
    nouveauTriplet->ligne = i;
    nouveauTriplet->colonne = j;
    nouveauTriplet->valeur = x;
    inserer(&m->mat, longueur(m->mat) + 1, nouveauTriplet);
}

// Permute les lignes i et j de la matrice creuse m
void echangerLignesM_Creuse(matrice_creuse *m, const int i, const int j)
{
    Liste elements = m->mat;
    while (elements != NULL)
    {
        Triplet *e = (Triplet *)elements->elt;
        if (e->ligne == i || e->ligne == j)
        {
            int temp = e->ligne;
            e->ligne = (e->ligne == i) ? j : i;
            e->colonne = temp;
        }
        elements = elements->suivant;
    }
}

// Écrit la matrice creuse m sur la sortie standard
void ecrireMatrice_Creuse(const matrice_creuse m)
{
    for (int i = 0; i < m.nbl; i++)
    {
        for (int j = 0; j < m.nbc; j++)
        {
            printf("%.2f ", getM_Creuse(m, i, j));
        }
        printf("\n");
    }
}

// Libère la mémoire allouée pour la matrice creuse m
void libererMatrice_Creuse(matrice_creuse *m)
{
    libererListe(&(m->mat));
}

// Libère la mémoire allouée pour une liste
void libererListe(Liste *l)
{
    struct noeud *temp;
    while (*l != NULL)
    {
        temp = *l;
        *l = (*l)->suivant;
        free(temp->elt); // Supposant que elt est un pointeur
        free(temp);
    }
}
