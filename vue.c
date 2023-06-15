#include <stdio.h>
#include <stdlib.h>
#include "vue.h"
#include "data.h"
#include "callbacks.h"

#define TAILLEZONEAFFICHAGEL 300
#define TAILLEZONEAFFICHAGEH 100

Widget textBoxMatrice; // la zone d’affichage
Widget textBoxVecteur;
Widget ZoneResultat; // la zone d’affichage

/* Rôle: création et assemblage des widgets */
void init_display(int argc, char *argv[], void *d)
{
    Widget MenuA = MakeMenu("Charger un fichier");
    MakeMenuItem(MenuA, "Matrice A", ChargerMatrice, d);
    MakeMenuItem(MenuA, "Vecteur B", ChargerVecteur, d);

    Widget BQuit;    // le bouton Quit pour terminer le programme
    Widget BResolve; // le bouton pour faire la resolution par pivot de gauss
    Widget BFichierMatrice;
    Widget BFichierVecteur;

    textBoxMatrice = MakeTextWidget("Matrice", 0, 0, TAILLEZONEAFFICHAGEL, TAILLEZONEAFFICHAGEH);
    textBoxVecteur = MakeTextWidget("Vecteur", 0, 0, 100, TAILLEZONEAFFICHAGEH);
    ZoneResultat = MakeTextWidget("Solution", 0, 0, TAILLEZONEAFFICHAGEL, TAILLEZONEAFFICHAGEH);

    // créer les composants graphiques
    BQuit = MakeButton(" Quit ", quit, NULL);
    BFichierMatrice = MakeButton(" Fichier Matrice ", ChargerMatrice, d);
    BFichierVecteur = MakeButton(" Fichier Vecteur ", ChargerVecteur, d);
    BResolve = MakeButton("Resoudre", SolutionSysteme, d);

    // Placement des boutons dans la fenêtre graphique
    SetWidgetPos(BResolve, PLACE_RIGHT, BFichierMatrice, NO_CARE, NULL);

    SetWidgetPos(textBoxMatrice, PLACE_UNDER, BFichierMatrice, NO_CARE, NULL);
    SetWidgetPos(textBoxVecteur, PLACE_UNDER, BFichierMatrice, PLACE_RIGHT, textBoxMatrice);
    SetWidgetPos(ZoneResultat, PLACE_RIGHT, BFichierMatrice, NO_CARE, NULL);
    SetWidgetPos(BFichierVecteur, PLACE_RIGHT, BFichierMatrice, NO_CARE, NULL);

    AttachEdge(BQuit, BOTTOM_EDGE, ATTACH_BOTTOM);
    // pour gérer les couleurs
    GetStandardColors();

    // pour afficher l’interface
    ShowDisplay();
}
