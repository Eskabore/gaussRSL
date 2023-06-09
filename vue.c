#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"

#define TAILLEZONEAFFICHAGEL 300
#define TAILLEZONEAFFICHAGEH 100

Widget textBoxMatrice; // la zone d’affichage
Widget textBoxVecteur;
Widget ZoneResultat; // la zone d’affichage
Widget menu;

/* Rôle: création et assemblage des widgets */
void init_display(int argc, char *argv[], void *d)
{
    (void)argc;
    (void)argv;
    (void)d;

    Widget BQuit;    // le bouton Quit pour terminer le programme
    Widget BResolve; // le bouton pour faire la resolution par pivot de gauss

    // créer les composants graphiques
    BQuit = MakeButton(" Quit ", quit, NULL);
    BResolve = MakeButton("Resoudre", resolution, NULL);

    textBoxMatrice = MakeTextWidget(NULL, 0, 0, TAILLEZONEAFFICHAGEL, TAILLEZONEAFFICHAGEH); // Text/fichier ou nn/modifiable?/LARGEUR/hAUTEUR
    textBoxVecteur = MakeTextWidget(NULL, 0, 0, 100, TAILLEZONEAFFICHAGEH);
    ZoneResultat = MakeTextWidget(NULL, 0, 0, TAILLEZONEAFFICHAGEL, TAILLEZONEAFFICHAGEH);

    Widget labelEntre = MakeLabel("Systeme d'equation d'entrée");
    Widget labelSortie = MakeLabel("Systeme d'equation aprés resolution");
    // setWidgetFont(labelEntre,100);

    menu = MakeMenu("Option");
    MakeMenuItem(menu, "Import Matrice", importMatrice, NULL);
    MakeMenuItem(menu, "Import Vecteur", importVecteur, NULL);

    // Placement des boutons dans la fenêtre graphique
    SetWidgetPos(labelEntre, PLACE_UNDER, menu, NO_CARE, NULL);

    SetWidgetPos(BResolve, PLACE_RIGHT, menu, NO_CARE, NULL);
    SetWidgetPos(BQuit, PLACE_RIGHT, BResolve, NO_CARE, NULL);

    SetWidgetPos(textBoxMatrice, PLACE_UNDER, labelEntre, NO_CARE, NULL);
    SetWidgetPos(textBoxVecteur, PLACE_UNDER, labelEntre, PLACE_RIGHT, textBoxMatrice);
    SetWidgetPos(ZoneResultat, PLACE_UNDER, labelEntre, PLACE_RIGHT, textBoxVecteur);

    SetWidgetPos(labelSortie, PLACE_UNDER, menu, PLACE_RIGHT, labelEntre);

    // pour gérer les couleurs
    GetStandardColors();

    // pour afficher l’interface
    ShowDisplay();
}
