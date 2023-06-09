#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"

// Renvoie un vecteur de taille n initialisé à 0
vecteur vecteurNul(const int n)
{
    vecteur v;
    v.taille = n;
    v.vec = (double *)calloc(n, sizeof(double));

    if (v.vec == NULL)
    {
        fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour le vecteur.\n");
        exit(EXIT_FAILURE);
    }

    return v;
}

// Renvoie l’élément v(i)
double getV(const vecteur v, const int i)
{
    return v.vec[i];
}

// v(i) = x
void setV(vecteur *v, const int i, const double x)
{
    if (i >= v->taille)
    {
        fprintf(stderr, "Error: Index out of bounds. The vector size is %d but you tried to access index %d\n", v->taille, i);
        return;
    }

    v->vec[i] = x;
}

// Permute les éléments i et j du vecteur v
void echangerElementsV(vecteur *v, const int i, const int j)
{
    double temp = getV(*v, i);
    setV(v, i, getV(*v, j));
    setV(v, j, temp);
}

// Ecrit le vecteur v sur la sortie standard
void ecrireVecteur(const vecteur v)
{
    for (int i = 0; i < v.taille; i++)
    {
        printf("%.2f ", getV(v, i));
    }
    printf("\n");
}

// Initialise le vecteur v à partir du fichier de nom f
void lireVecteur(vecteur *v, const char *f)
{
    FILE *file = fopen(f, "r");
    if (file)
    {
        fscanf(file, "%d", &(v->taille));
        v->vec = (double *)malloc(v->taille * sizeof(double));
        for (int i = 0; i < v->taille; i++)
        {
            fscanf(file, "%lf", &(v->vec[i])); // Le format de fscanf devrait être %lf pour un double
        }
        fclose(file);
    }
}

// Renvoie la taille du vecteur v
int getTaille(const vecteur v)
{
    return v.taille;
}

// Libére mémoire allouée
void libererVecteur(vecteur *v)
{
    free(v->vec);
}

/*
 * Initialise le vecteur v à partir d'un tableau de taille taille
 * Encapsulation / Coherence / Validation des parametres
 */
void initVecteur(vecteur *v, int taille)
{
    v->taille = taille;
    v->vec = (double *)malloc(taille * sizeof(double));
    if (v->vec == NULL)
    {
        fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour le vecteur.\n");
        exit(EXIT_FAILURE);
    }
}