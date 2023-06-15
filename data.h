#pragma once

#include "matrice.h"
#include "matriceC.h"
#include "vecteur.h"

typedef struct
{
    matrice_creuse A;
    vecteur B;
    vecteur X;
} equation;

extern char *VecteurEnChaine(vecteur v);
extern char *MatriceCreuseEnChaine(matrice_creuse *mc);
extern vecteur ChargerVecteurDepuisFichier(char *cheminFichier);
extern matrice_creuse ChargerMatriceDepuisFichier(char *cheminFichier);
void SolutionEtAffichage(Widget w, void *d);
extern matrice_creuse convertirDenseVersCreuse(matrice m); // Convertir une matrice dense en une matrice creuse.