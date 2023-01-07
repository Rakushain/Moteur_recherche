#include <stdio.h>
#include <stdlib.h>

#include "moteur.h"

int count_occ(char *nom, char *mot)
/* Fonction qui compte le nombre de fois où le mot *mot est présent dans le fichier *nom */
{
    FILE *fichier;
    int occ = 0;
    char x[46]; // On dira que la taille max d'un mot est de 45 lettres

    fichier = fopen(nom, "r");
    if(fichier == NULL){
        printf("Ouverture du fichier %s impossible\n", nom);
        exit(1);
    }
    
    // Lit le fichier mot par mot
    while (fscanf(fichier, "%s", x) == 1) {
        // printf("%s\n", x);
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

    int fichier_debut = 17;
    int fichier_fin = 20;
    int nb_fich = 20;
    char *fich = "fichier_";
    char *extension = ".txt";

    char **liste_fichiers = malloc((nb_fich + 1) * sizeof(char*)); // tableau de string qui garde les noms des differents fichiers
    

    for(int i = fichier_debut; i <= fichier_fin; i++){
        // Boucle utilisee pour stocker tout les noms de fichier de la forme fichier_i.txt
        char *pchiffre = malloc(3*sizeof(char));
        sprintf(pchiffre, "%d", i);  // conversion du int i en char * pour utiliser strcat et strcopy
 
        char *fullString = (char *)malloc(sizeof(strlen(fich) + strlen(extension) + strlen(pchiffre)) + 3); // +3 car 3 chaines donc 3 /0
        strcpy(fullString, fich);
        strcat(fullString, pchiffre);
        strcat(fullString, extension);

        liste_fichiers[i] = malloc((nb_fich + 1) * sizeof(int)); // on alloue de la mémoire pour copier la chaine précédente dans le tableau
        strcpy(liste_fichiers[i], fullString);

        free(pchiffre);
        free(fullString);
    }

    int *liste_occurences = malloc((nb_fich + 1) * sizeof(int)); // stocke tout le nombre d'occurences pour chaque fichier
    for(int i = fichier_debut; i <= fichier_fin; i++){
        liste_occurences[i] = count_occ(liste_fichiers[i], mot);
    }
    
    // on va chercher à trier le tableau des occurences pour savoir quel fichier contient le plus de fois le mot 
    selection_sort(liste_occurences, liste_fichiers, fichier_debut, fichier_fin);

    print(liste_occurences, liste_fichiers, mot, fichier_debut, fichier_fin);

    // On libere toute la memoire allouee
    for(int i = fichier_debut; i <= fichier_fin; i++){
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

void swap_string(char* x, char* y)
/* Fonction swap_char utilisee dans le tri par selection*/
{
    char *temp = (char *)malloc((strlen(x) + 1) * sizeof(char));
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
    free(temp);
}
 

void selection_sort(int *arr, char **liste_fichiers, int fichier_debut, int fichier_fin)
{
    /* Tri par selection pour trier le tableau d'occurences*/
    int i, j, min_idx;
 
    for (i = fichier_debut; i <= fichier_fin - 1; i++) {
        min_idx = i;
        for (j = i + 1; j <= fichier_fin; j++){
            if (arr[j] > arr[min_idx]){
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
        // on swap la position des 2 tableaux pour garder l'ordre
        swap_string(liste_fichiers[min_idx], liste_fichiers[i]);
    }
}


void print(int *liste_occurences, char **liste_fichiers, char *mot, int fichier_debut, int fichier_fin){
    /* Fonction utilisee pour afficher le nombre d occurences du mot dans tout les fichiers*/
    for(int i = fichier_debut; i <= fichier_fin; i++){
        printf("%s nombre d’occurrences de %s = %d\n", liste_fichiers[i], mot, liste_occurences[i]);
    }
}


int nb_mots(char *nom){
    FILE *f;
    int nb = 0;
    char x[46];
    f = fopen(nom, "r");
    if(f == NULL){
        printf("Ouverture du fichier %s impossible.\n", nom);
        exit(1);
    }
    while(!(feof(f))){
        fscanf(f, "%s", x);
        nb++;
    }
    fclose(f);
    return nb;
}

CRI* indexation(char *nom){
    FILE *f;
    CRI *liste_indexee;
    int taille_max = 46;
    int i = 0;
    int nb = nb_mots(nom);
    char x[taille_max];  // mot le plus long = 45 lettres

    liste_indexee = (CRI*) malloc(nb * sizeof(CRI));
    f = fopen(nom, "r");
    if(f == NULL){
        printf("Ouverture du fichier %s impossible.\n", nom);
        exit(1);
    }
    while(!(feof(f))){
        CRI mot_indexe;
        mot_indexe.mot = (char *)malloc(taille_max * sizeof(char));
        fscanf(f, "%s", x);
        // for(int j = 0; j < i; j++){
        //     if (strcmp(liste_indexee[j].mot, mot_indexe.mot) == 1){
        //     }
        // }
        strcpy(mot_indexe.mot, x);
        mot_indexe.nb_occ = count_occ(nom, x);
        liste_indexee[i] = mot_indexe;
        i++;
    }
    fclose(f);
    return liste_indexee;
}

void affiche_liste_indexee(CRI *liste_indexee, int n){
    for(int i = 0; i < n; i++){
        printf("[%s %d]", liste_indexee[i].mot, liste_indexee[i].nb_occ);
        if(i == n-1)
            printf("\n");
        else
            printf(", ");
    }
}



// char* maj_to_min (char* c)
// {
//     char c_ret[50];
//     int i = 0;
//     int cpt=0;
//     while (c[i] != '\0')
//     {
//         if('A'<=c[i]<='Z')
//         {
//             c_ret[cpt]= c[i] + 32;
//             cpt++;
//         }        
//         else if('a'<=c[i]<='z')
//         {
//             c_ret[cpt]= c[i];
//             cpt++;
//         }
//         i++
//     }
//     c_ret[cpt]= '\0';
//     if (c_ret[cpt-1]=='s'){
//         c_ret[cpt-1]='\0';
//     }
    
//     return c_ret;
// }

// int compare(char *c1, char *c2, int n){
//     char mot[strlen(C1)];

//     for(int i = 0; i < n; i++)
//         {
//         if(c1[i] = "'")
//         {
//         i++;
//         n++;
//         }
//         if(c1[i] = c2[i] || strlen(c1) != strlen(c2))
//         {
//             return 0;
//         }
//         if(c1[i+32] = c2[i] || strlen(c1) != strlen(c2))
//         {
//             return 0;
//         }

//     }
//     return 1;
// }