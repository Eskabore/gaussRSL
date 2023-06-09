#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "matrice.h"

// Renvoie une matrice m × n initialisée à 0
matrice matriceNulle(const int m, const int n)
{
    matrice result;
    result.nbl = m;
    result.nbc = n;
    result.mat = (T *)calloc(m * n, sizeof(T));
    return result;
}

// Renvoie l’élément m(i,j)
T getM(const matrice m, const int i, const int j)
{
    assert(i >= 0 && i < m.nbl);
    assert(j >= 0 && j < m.nbc);
    return m.mat[i * m.nbc + j];
}

// m(i,j) = x
void setM(matrice *m, const int i, const int j, const T x)
{
    assert(i >= 0 && i < m->nbl);
    assert(j >= 0 && j < m->nbc);
    m->mat[i * m->nbc + j] = x;
}

// Permute les lignes i et j de la matrice m
void echangerLignesM(matrice *m, const int i, const int j)
{
    for (int k = 0; k < m->nbc; k++)
    {
        T temp = getM(*m, i, k);
        setM(m, i, k, getM(*m, j, k));
        setM(m, j, k, temp);
    }
}

// Ecrit la matrice m sur la sortie standard
void ecrireMatrice(const matrice m)
{
    for (int i = 0; i < m.nbl; i++)
    {
        for (int j = 0; j < m.nbc; j++)
        {
            printf("%.2f ", getM(m, i, j));
        }
        printf("\n");
    }
}

// Initialise la matrice m à partir du fichier de nom f
void lireMatrice(matrice *m, const char *f)
{
    FILE *file = fopen(f, "r");
    if (file)
    {
        fscanf(file, "%d %d", &(m->nbl), &(m->nbc));
        m->mat = (T *)malloc(m->nbl * m->nbc * sizeof(T));
        for (int i = 0; i < m->nbl; i++)
        {
            for (int j = 0; j < m->nbc; j++)
            {
                fscanf(file, "%lf", &(m->mat[i * m->nbc + j]));
            }
        }
        fclose(file);
    }
}

// Renvoie le nombre de lignes de la matrice m
int getNbLignes(const matrice m)
{
    return m.nbl;
}

// Renvoie le nombre de colonnes de la matrice M
int getNbCols(const matrice m)
{
    return m.nbc;
}

// Libère la mémoire allouée à la matrice m
void libererMatrice(matrice *m)
{
    free(m->mat);
}
