#include <stdio.h>
#include <stdlib.h>

#include "moteur.h"


int count_occ(char *nom, char *mot)
// Fonction qui compte le nombre de fois où le mot *mot est présent dans le fichier *nom
{
    FILE *fichier;
    char c;
    int occ = 0;
    char x[30]; // On dira que la taille max d'un mot est de 30

    fichier = fopen(nom, "r");
    if(fichier == NULL){
        printf("Ouverture du fichier %s impossible\n", nom);
        exit(1);
    }
    
    // Lit le fichier mot par mot
    while (fscanf(fichier, "%s", x) == 1) {
        printf("%s\n", x);
        if (strcmp(x, mot) == 0){
            occ++;
        }
    }
    fclose(fichier);
    return occ;
}
