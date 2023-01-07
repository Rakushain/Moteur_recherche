#include <stdio.h>
#include <stdlib.h>
#include "moteur.h"


int main(int argc, char **argv)
{   
    CRI *liste_indexee;
    char *nom = "fichier_17.txt";
    int nb = nb_mots(nom);
    printf("Nombre d'occurences de %s dans %s : %d\n", argv[1], nom, count_occ(nom, argv[1]));
    classify_files(argv[1]);
    liste_indexee = indexation("fichier_17.txt");
    affiche_liste_indexee(liste_indexee, nb);
    free(liste_indexee);
    return 0;
}