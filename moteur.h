#ifndef MOTEUR_H
#define MOTEUR_H
#include <stdio.h>
#include <stdlib.h>
#include "string.h"


int count_occ(char *nom, char *mot);
int compare(char *c1, char *c2, int n);

void classify_files(char *mot);

void swap(int* x, int* y);
void swap_string(int* x, int* y);
void selection_sort(int *arr, char *liste_fichiers, int n);
void print(int *liste_occurences, char *liste_fichiers, char *mot, int n);

#endif