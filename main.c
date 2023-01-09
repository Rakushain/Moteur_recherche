#include <stdio.h>
#include <stdlib.h>
#include "moteur.h"


int main(int argc, char **argv)
{   
    if(argc == 1){
        printf("Veuillez renseigner un mot a chercher dans les fichiers\n");
        exit(1);
    }
    else if(argc > 2){
        printf("Erreur : Trop d'arguments en entree\n");
        exit(1);
    }

    CRI *liste_indexee;
    char *nom = "fichier_17.txt";
    classify_files(argv[1]);
    liste_indexee = indexation(nom);
    
    free_liste_indexee(liste_indexee, nb_mots(nom));
    return 0;
}