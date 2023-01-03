#include <stdio.h>
#include <stdlib.h>
#include "moteur.h"


int main(int argc, char **argv)
{
    char *nom = "fichier_1.CRI.txt";
    printf("Nombre d'occurences de %s dans %s : %d\n", argv[1], nom, count_occ(nom, argv[1]));
    return 0;
}