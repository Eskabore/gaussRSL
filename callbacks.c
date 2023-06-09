#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "vue.h"
#include "callbacks.h"

// Callback bouton quit. Rôle : terminer l’application
void quit(Widget w, void *d)
{
    equation *eq = (equation *)d;
    libererMatrice(&(eq->A));
    libererVecteur(&(eq->B));
    libererVecteur(&(eq->X));
    exit(EXIT_SUCCESS);
}



// Ouvrir le fichier qui contient la matrice A pour l'afficher.
void ChargerMatrice(Widget w, void *d)
{
    equation *eq = (equation *)d;
    char *fileNameM = GetFile("Choisir matrice A", ".", NULL, NULL); // Choisir un fichier.
    eq->A = ChargerMatriceDepuisFichier(fileNameM);
    AfficherMatriceDansFenetre(matrixLabel, &(eq->A));
}

// Ouvrir le fichier qui contient le vecteur B pour l'afficher.
void ChargerVecteur(Widget w, void *d)
{
    equation *eq = (equation *)d;
    char *fileNameM = GetFile("Choisir vecteur B", ".", NULL, NULL); // Choisir un fichier.
    eq->B = ChargerVecteurDepuisFichier(fileNameM);
    AfficherVecteurDansFenetre(vecteurLabel, &(eq->B));
}

// Résoudre le système et afficher la solution X.
void SolutionSysteme(Widget w, void *d)
{
    equation *eq = (equation *)d;

    // Initialiser le vecteur X
    initVecteur(&(eq->X), getNbLignes(eq->A));

    // Résoudre le système avec la méthode de Gauss et stocker le résultat dans eq->X
    GaussRSL(eq->A, eq->B, &(eq->X));

    // Affichez le vecteur solution dans l'interface utilisateur
    char *chaine = VecteurEnChaine(eq->X);
    SetLabel(solutionLabel, chaine);
    free(chaine); // Libérer la mémoire allouée pour la chaîne
}
