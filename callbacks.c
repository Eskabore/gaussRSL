#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "vue.h"
#include "callbacks.h"

int checkMat = 0;
int checkVect = 0;

// Callback bouton quit. Rôle : terminer l’application
void quit(Widget w, void *d)
{
    exit(EXIT_SUCCESS);
}

// Ouvrir le fichier qui contient la matrice A pour l'afficher.
void ChargerMatrice(Widget w, void *d)
{
    equation *eq = (equation *)d;
    char *fileNameM = GetFile("Choisir matrice A", ".", NULL, NULL); 
    eq->A = ChargerMatriceDepuisFichier(fileNameM);
    SetTextWidgetText(textBoxMatrice, fileNameM, 1);
    checkMat = 1;
}

// Ouvrir le fichier qui contient le vecteur B pour l'afficher.
void ChargerVecteur(Widget w, void *d)
{
    equation *eq = (equation *)d;
    char *fileNameM = GetFile("Choisir vecteur B", ".", NULL, NULL);
    eq->B = ChargerVecteurDepuisFichier(fileNameM);
    SetTextWidgetText(textBoxVecteur, fileNameM, 1);
    checkVect = 1;
}

// Resolution du systeme d'equation par pivot de gauss.
void SolutionSysteme(Widget w, void *d)
{
    equation *eq = (equation *)d;
    if (checkMat == 0 || checkVect == 0)
    {
        printf("Erreur : Veuillez d'abord choisir une matrice et un vecteur\n");
    }
    else
    {
        SolutionEtAffichage(w, d);
        SetTextWidgetText(ZoneResultat, VecteurEnChaine(eq->X), 0);
    }
}