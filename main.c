#include <stdio.h>
#include <math.h>
#include <libsx.h>
#include "matrice.h"
#include "matriceC.h"
#include "vecteur.h"
#include "callbacks.h"
#include "data.h"
#include "vue.h"


void GaussRSL(matrice A, vecteur B, vecteur *X);

int main(int argc, char *argv[])
{
    // accéder au serveur graphique
    if (OpenDisplay(argc, argv) == 0)
    {
        fprintf(stderr, "Can’t open display\n");
        return EXIT_FAILURE;
    }

    equation d;
    printf("Open display");
    // créer l’IG et l’afficher à l’écran
    init_display(argc, argv, &d); // vue.c
    MainLoop();
    return EXIT_SUCCESS;
}

void GaussRSL(matrice A, vecteur B, vecteur *X)
{
    int N = getNbLignes(A); // Nombre de lignes de la matrice A

    // Triangularisation de la matrice A
    for (int k = 0; k < N; k++)
    {
        // Recherche du pivot
        int pivot = k;
        for (int i = k + 1; i < N; i++)
        {
            if (fabs(getM(A, i, k)) > fabs(getM(A, pivot, k)))
            {
                pivot = i; // Stcokage de l'indice du pivot
            }
        }

        // Permutation des lignes si nécessaire
        if (pivot != k)
        {
            echangerLignesM(&A, k, pivot);
            echangerElementsV(&B, k, pivot);
        }

        // Normalisation de la ligne k de la matrice A et du vecteur B
        double pivotValue = getM(A, k, k);
        for (int j = k; j < N; j++)
        {
            setM(&A, k, j, getM(A, k, j) / pivotValue);
        }
        setV(&B, k, getV(B, k) / pivotValue);

        // Soustraction des lignes i de la matrice A et du vecteur B
        for (int i = k + 1; i < N; i++)
        {
            double factor = getM(A, i, k);
            for (int j = k; j < N; j++)
            {
                setM(&A, i, j, getM(A, i, j) - factor * getM(A, k, j));
            }
            setV(&B, i, getV(B, i) - factor * getV(B, k));
        }
    }

    // Calcul de la solution X
    for (int k = N - 1; k >= 0; k--)
    {
        double sol = getV(B, k);
        for (int i = k + 1; i < N; i++)
        {
            sol -= getM(A, k, i) * getV(*X, i);
        }
        setV(X, k, sol);
    }
}
