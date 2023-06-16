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

// Renvoie une liste vide.
extern Liste initListe(void);

// Renvoie le nombre d'éléments de la liste.
extern int longueur(const Liste);

// Renvoie l'élément de rang r de la liste l.
extern T_liste elementRang(const Liste, const int);

// Crée un noeud avec l'élément e et renvoie un pointeur sur ce noeud.
extern void inserer(Liste *l, const int r, const T_liste e);

/* Les elements ci-dessous, ne sont pas utilises dans le projet courant */
extern void supprimer(Liste *, const int);
extern void supprimerEnQueue(Liste *);
extern void supprimerEnQueueBis(Liste *);

#endif /* LISTE_H */
