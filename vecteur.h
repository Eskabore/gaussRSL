#pragma once

typedef double T;

typedef struct
{
    int taille;  // Taille du vecteur
    T *vec; // Pointeur vers les éléments du vecteur
} vecteur;

// Prototypes des fonctions de manipulation des vecteurs

extern vecteur vecteurNul(int taille);

extern T getV(const vecteur v, int i);
extern void echangerElementsV(vecteur *v, const int i, const int j);
extern void setV(vecteur *v, int index, const T valeur);
extern void ecrireVecteur(const vecteur v);
extern void lireVecteur(vecteur *v, const char *nomFichier);
extern int getTaille(const vecteur v);
extern void libererVecteur(vecteur *v);
extern void initVecteur(vecteur *v, int taille);