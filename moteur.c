#include <stdio.h>
#include <stdlib.h>

#include "moteur.h"


int count_occ(char *nom, char *mot)
/* Fonction qui compte le nombre de fois où le mot *mot est présent dans le fichier *nom */
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

void classify_files(char *mot)
{
    /* Fonction qui permet de compter le nombres d'occurences dans tout les fichiers */
    char *fich = "fichier_";
    char *extension = ".CRI.txt";

    char **liste_fichiers = malloc(30 * sizeof(char*)); // tableau de string qui garde les noms des differents fichiers
    

    for(int i = 1; i <= 3; i++){
        char chiffre = i + '0'; 
        char *pchiffre = malloc(2*sizeof(char));
        pchiffre[0] = chiffre;
        pchiffre[1] = '\0';    // conversion du int en char * pour utiliser strcat et strcopy

        char *fullString = (char *)malloc(sizeof(strlen(fich) + strlen(extension) + strlen(pchiffre)) + 3); // +3 car 3 chaines donc 3 /0
        strcpy(fullString, fich);
        strcat(fullString, pchiffre);
        strcat(fullString, extension);

        liste_fichiers[i-1] = malloc(30 * sizeof(int)); // on alloue de la mémoire pour copier la chaine précédente dans le tableau

        strcpy(liste_fichiers[i-1], fullString);
        free(pchiffre);
        free(fullString);
    }

    int *liste_occurences = malloc(3 * sizeof(int)); // stocke tout le nombre d'occurences pour chaque fichier
    for(int i = 0; i < 3; i++){
        liste_occurences[i] = count_occ(liste_fichiers[i], mot);
    }
    
    // on va chercher à trier le tableau des occurences pour savoir quel fichier contient le plus de fois le mot 
    selection_sort(liste_occurences, *liste_fichiers, 3);

    for(int i = 0; i < 3; i++){
        printf("%d ", liste_occurences[i]);
    }

    // On libere toute la memoire allouee
    for(int i = 0; i < 3; i++){
        free(liste_fichiers[i]);
    }

    free(liste_fichiers);
    free(liste_occurences);

}

 
void swap(int* x, int* y)
/* Fonction swap utilisee dans le tri par selection*/
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 

void selection_sort(int *arr, char *liste_fichiers, int n)
{
    /* Tri par selection pour trier le tableau d'occurences*/
    int i, j, min_idx;
 
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++){
            if (arr[j] > arr[min_idx]){
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}


char* maj_to_min (char* c)
{
    char c_ret[50];
    int i = 0;
    int cpt=0;
    while (c[i] != '\0')
    {
        if('A'<=c[i]<='Z')
        {
            c_ret[cpt]= c[i] + 32;
            cpt++;
        }        
        else if('a'<=c[i]<='z')
        {
            c_ret[cpt]= c[i];
            cpt++;
        }
        i++
    }
    c_ret[cpt]= '\0';
    if (c_ret[cpt-1]=='s'){
        c_ret[cpt-1]='\0';
    }
    
    return c_ret;
}

int compare(char *c1, char *c2, int n){
    char mot[strlen(C1)];

    for(int i = 0; i < n; i++)
        {
        if(c1[i] = "'")
        {
        i++;
        n++;
        }
        if(c1[i] = c2[i] || strlen(c1) != strlen(c2))
        {
            return 0;
        }
        if(c1[i+32] = c2[i] || strlen(c1) != strlen(c2))
        {
            return 0;
        }

    }
    return 1;
}