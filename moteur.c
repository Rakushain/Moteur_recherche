#include <stdio.h>
#include <stdlib.h>

#include "moteur.h"


int compare(char *c1, char *c2, int n){
    for(int i = 0; i < n; i++){
        if(c1[i] != c2[i] || strlen(c1) != strlen(c2)){
            return 0;
        }
    }
    return 1;
}

int count_occ(char *nom, char *mot)
// Fonction qui compte le nombre de fois où le mot *mot est présent dans le fichier *nom
{
    FILE *fichier;
    char c;
    int occ, taille;
    char x[30]; // On dira que la taille max d'un mot est de 30

    occ = 0;

    fichier = fopen(nom, "r");
    if(fichier == NULL){
        printf("Ouverture du fichier %s impossible\n", nom);
        exit(1);
    }
    
    // Lit le fichier mot par mot
    while (fscanf(fichier, "%s", x) == 1) {
        printf("%s\n", x);
        if (compare(x, mot, strlen(mot)) == 1){
            occ++;
        }
    }
    return occ;
}
