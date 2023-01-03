#include <stdio.h>
#include <stdlib.h>

#include "moteur.h"


int count_occ(char *nom, char *mot)
// Fonction qui compte le nombre de fois où le mot *mot est présent dans le fichier *nom
{
    FILE *fichier;
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

void classify_files(char *mot){
    // Fonction qui permet de compter le nombres d'occurences dans tout les fichiers
    char *fich = "fichier_";
    char *ext = ".CRI";

    char **liste_fichiers = malloc(30 * sizeof(char*)); // tableau de string qui garde les noms des differents fichiers
    

    for(int i = 1; i <= 3; i++){
        char chiffre = i + '0'; 
        char *pchiffre = malloc(2*sizeof(char));
        pchiffre[0] = chiffre;
        pchiffre[1] = '\0';    // conversion du int en char * pour utiliser strcat et strcopy
        char *fullString = (char *)malloc(sizeof(strlen(fich) + strlen(ext) + strlen(pchiffre)) + 3); // +3 car 3 chaines donc 3 /0
        strcpy(fullString, fich);
        strcat(fullString, pchiffre);
        strcat(fullString, ext);

        liste_fichiers[i-1] = malloc(30 * sizeof(int));

        strcpy(liste_fichiers[i-1], fullString);
        free(pchiffre);
        free(fullString);
    }

    char *liste_occurences = malloc(3 * sizeof(int )); // stocke tout le nombre d'occurences pour chaque fichier
    for(int i = 0; i < 3; i++){
        liste_occurences[i] = count_occ(liste_fichiers[i], mot);
        printf("%s, ", liste_fichiers[i]);
    }


}
