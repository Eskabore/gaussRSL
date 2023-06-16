#pragma once

typedef double T;

typedef struct
{
    int taille;  // Taille du vecteur
    T *vec; // Pointeur vers les éléments du vecteur
} vecteur;

// Renvoie l’élément v(i)
extern T getV(const vecteur v, int i);

// Permute les éléments i et j du vecteur v
extern void echangerElementsV(vecteur *v, const int i, const int j);

// v(i) = x
extern void setV(vecteur *v, int index, const T valeur);

// Ecrit le vecteur v sur la sortie standard
extern void ecrireVecteur(const vecteur v);

// Initialise le vecteur v à partir du fichier de nom f
extern void lireVecteur(vecteur *v, const char *nomFichier);

// Renvoie la taille du vecteur v
extern int getTaille(const vecteur v);

// Libere la memoire allouee au vecteur v
extern void libererVecteur(vecteur *v);

// Initialise le vecteur v à la taille taille
extern void initVecteur(vecteur *v, int taille);