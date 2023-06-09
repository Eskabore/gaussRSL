#include "liste.h"

typedef double T;

// Structure pour une matrice creuse
typedef struct
{
    int nbl;   // Nombre de lignes
    int nbc;   // Nombre de colonnes
    Liste mat; // Liste liée des triplets (ligne, colonne, valeur)

} matrice_creuse;


// Fonction pour créer une matrice creuse nulle de taille m x n
extern matrice_creuse matriceCreuseNulle(const int m, const int n);

// Fonction pour obtenir l'élément à la position (i, j) de la matrice creuse m
extern T getM_Creuse(const matrice_creuse m, const int i, const int j);

// Fonction pour définir l'élément à la position (i, j) de la matrice creuse m à la valeur x
extern void setM_Creuse(matrice_creuse *m, const int i, const int j, const T x);

// Fonction pour échanger les lignes i et j de la matrice creuse m
extern void echangerLignesM_Creuse(matrice_creuse *m, const int i, const int j);

// Fonction pour écrire la matrice creuse m sur la sortie standard
extern void ecrireMatrice_Creuse(const matrice_creuse m);

// Fonction pour libérer la mémoire allouée pour la matrice creuse m
extern void libererMatrice_Creuse(matrice_creuse *m);

// libere liste
extern void libererListe(Liste *l);