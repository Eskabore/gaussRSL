#pragma once

// Quitter l'application.
extern void quit(Widget w, void *d);

// Ouvrir le fichier qui contient la matrice A pour l'afficher.
extern void ChargerMatrice(Widget w, void *d);

// Ouvrir le fichier qui contient le vecteur B pour l'afficher.
extern void ChargerVecteur(Widget w, void *d);

// Resolution du systeme d'equation par pivot de gauss.
extern void SolutionSysteme(Widget w, void *d);

