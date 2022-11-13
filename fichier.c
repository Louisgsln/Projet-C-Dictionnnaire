#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "fichier.h"
#define TAILLE_MAX 1000



int trouver_arbre(char * mots){
    //printf("%s\n", mots);
    int pos3_mot=0;
    char type_mot[TAILLE_MAX];
    char type_Nom[4] = { 'N', 'o', 'm', '\0' };
    char type_Ver[4] = { 'V', 'e', 'r', '\0' };
    char type_Adj[4] = { 'A', 'd', 'j', '\0' };
    char type_Adv[4] = { 'A', 'd', 'v', '\0' };
    while(mots[pos3_mot] != ':'){
        type_mot[pos3_mot] = mots[pos3_mot];
        pos3_mot++;
    }
    type_mot[pos3_mot]='\0';
    //printf("%s\n", type_mot);

    if(strcmp(type_mot,type_Nom) == 0){
        printf("dans arbre nom\n");
        return 1;
    }
    if(strcmp(type_mot,type_Ver) == 0){
        printf("dans arbre verbe\n");
        return 2;
    }
    if(strcmp(type_mot,type_Adj) == 0){
        printf("dans arbre adjectif\n");
        return 3;
    }
    if(strcmp(type_mot,type_Adv) == 0){
        printf("dans arbre adverbe\n");
        return 4;
    }

}

