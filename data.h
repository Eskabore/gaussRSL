#ifndef DATA_H
#define DATA_H

#include "matrice.h"
#include "vecteur.h"
#include "data.c"

typedef struct
{
    matrice A;
    vecteur B;
    vecteur X;
} equation;

#endif

