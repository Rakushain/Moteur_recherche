#ifndef MOTEUR_H
#define MOTEUR_H
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct {
    char *mot; // mot le plus long = 45 lettres
    int nb_occ;
} CRI;


int count_occ(char *nom, char *mot);

void classify_files(char *mot);

void swap(int* x, int* y);
void swap_string(char* x, char* y);
void selection_sort(int *arr, char **liste_fichiers, int fichier_debut, int fichier_fin);
void print(int *liste_occurences, char **liste_fichiers, char *mot, int fichier_debut, int fichier_fin);

CRI* indexation(char *nom);
int nb_mots(char *nom);
void affiche_liste_indexee(CRI *liste_indexee, int n);


#endif