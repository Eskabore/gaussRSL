#pragma once

#include "matrice.h"
#include "matriceC.h"
#include "vecteur.h"

// Structure qui contient les données de l'application.
typedef struct
{
    matrice_creuse A;
    vecteur B;
    vecteur X;
} equation;

// Mettre un vecteur sous forme de chaine de caractere.
extern char *VecteurEnChaine(vecteur v);

// Mettre une matrice creuse sous forme de chaine de caractere.
extern char *MatriceCreuseEnChaine(matrice_creuse *mc);

// Charger un vecteur depuis un fichier.
extern vecteur ChargerVecteurDepuisFichier(char *cheminFichier);

// Charger une matrice creuse depuis un fichier.
extern matrice_creuse ChargerMatriceDepuisFichier(char *cheminFichier);

// Resolution du systeme d'equation par pivot de gauss et affichage de la matrice et du vecteur.
void SolutionEtAffichage(Widget w, void *d);
