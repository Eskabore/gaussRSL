#pragma once

// Structure matrice
typedef double T;

typedef struct
{
    int nbl; // le nombre de lignes
    int nbc; // le nombre de colonnes
    T *mat;  // les éléments de la matrice
} matrice;

// Renvoie une matrice m × n initialisée à 0
extern matrice matriceNulle(const int m, const int n);

// Renvoie l'élément m(i, j)
extern T getM(const matrice m, const int i, const int j);

// Affecte la valeur x à m(i, j)
extern void setM(matrice *m, const int i, const int j, const T x);

// Permute les lignes i et j de la matrice m
extern void echangerLignesM(matrice *m, const int i, const int j);

// Écrit la matrice m sur la sortie standard
extern void ecrireMatrice(const matrice m);

// Initialise la matrice m à partir du fichier de nom f
extern void lireMatrice(matrice *m, const char *f);

// Renvoie le nombre de lignes de la matrice m
extern int getNbLignes(const matrice m);

// Renvoie le nombre de colonnes de la matrice m
extern int getNbCols(const matrice m);

// Libere la memoire allouee a la matrice m
extern void libererMatrice(matrice *m);