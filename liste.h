#ifndef LISTE_H
#define LISTE_H

// typedef void* T_liste;

typedef struct
{
    int ligne;
    int colonne;
    double valeur;
} Triplet;

// Alias pour un pointeur vers Triplet.
typedef Triplet *T_liste;

typedef struct noeud
{
    T_liste elt;
    struct noeud *suivant;
} *Liste;

extern Liste initListe(void);
extern int longueur(const Liste);
extern T_liste elementRang(const Liste, const int);
extern void inserer(Liste *l, const int r, const T_liste e);
extern void supprimer(Liste *, const int);
extern void supprimerEnQueue(Liste *);
extern void supprimerEnQueueBis(Liste *);

#endif /* LISTE_H */
