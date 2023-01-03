#include <stdio.h>
#include <stdlib.h>

#include "moteur.h"


int compare(char *c1, char *c2, int n){
    for(int i = 0; i < n; i++){
        if(c1[i] != c2[i]){
            return 0;
        }
    }
    return 1;
}

int count_occ(char *nom, char *mot)
{
    FILE *fichier;
    char c;
    int occ, taille;
    char x[30]; // On dira que la taille max d'un mot est de 30

    occ = 0;
    taille = strlen(mot);

    fichier = fopen(nom, "r");
    if(fichier == NULL){
        printf("Ouverture du fichier %s impossible\n", nom);
        exit(1);
    }
    
    // Lit le fichier mot par mot
    while (fscanf(fichier, "%s", x) == 1) {
        if (compare(x, mot, taille) == 1){
            occ++;
        }
    }
    return occ;
}
