
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
#include "bintree.h"

#define TAILLE_MAX 1000 // Tableau de taille 1000

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX

    fichier = fopen("C:\\Users\\ameli\\CLionProjects\\Dictionnaire\\dico_10_lignes.txt", "r");

    if (fichier != NULL) {
        fgets(chaine, TAILLE_MAX, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
        printf("%s", chaine); // On affiche la chaîne
        //while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
            //printf("%s", chaine); // On affiche la chaîne
        fclose(fichier);
    }

    //couper la  ligne
    char mots_coupes[3][TAILLE_MAX];
    char mot[TAILLE_MAX];
    int pos_chaine =0;
    int pos_mot =0;
    for (int numero_mot =0; numero_mot<3; numero_mot++) {
        while (isspace(chaine[pos_chaine])== 0) {
            mot[pos_mot] = chaine[pos_chaine];
            pos_mot++;
            pos_chaine++;
        }

        mot[pos_mot] = '\0';
        pos_mot = 0;
        strcpy(mots_coupes[numero_mot], mot);
        printf("'%s'\n", mot);

        while(isspace(chaine[pos_chaine])) {
            pos_chaine++;
        }
    }

    //trouver quel type d'arbre
    printf("%s\n", mots_coupes[2]);
    int pos3_mot=0;
    char type_mot[TAILLE_MAX];
    char type_Nom[4] = { 'N', 'o', 'm', '\0' };
    char type_Ver[4] = { 'V', 'e', 'r', '\0' };
    char type_Adj[4] = { 'A', 'd', 'j', '\0' };
    char type_Adv[4] = { 'A', 'd', 'v', '\0' };
    while(mots_coupes[2][pos3_mot] != ':'){
        type_mot[pos3_mot] = mots_coupes[2][pos3_mot];
        pos3_mot++;
    }
    type_mot[pos3_mot]='\0';
    printf("%s\n", type_mot);

    if(strcmp(type_mot,type_Nom) == 0){
        printf("dans arbre nom\n");
    }
    if(strcmp(type_mot,type_Ver) == 0){
        printf("dans arbre verbe\n");
    }
    if(strcmp(type_mot,type_Adj) == 0){
        printf("dans arbre adjectif\n");
    }
    if(strcmp(type_mot,type_Adv) == 0){
        printf("dans arbre adverbe\n");
    }



    LISTE L;
    p_node pn;
    t_tree t;
    t.root = createNode('/');
    L= t.root->children;
    p_children temp;
    temp = L;

    int pos2_mot = 0;
    //while(mots_coupes[1][pos2_mot]!= '\0') {
        //pn = createNode(mots_coupes[1][pos2_mot]);

        if (L == NULL) {
            while(mots_coupes[1][pos2_mot]!= '\0') {
                pn = createNode(mots_coupes[1][pos2_mot]);

                L = createChildren(pn);
                //printf("%u\n", __LINE__);
                printf("lettre enregistree dans enfants : %c\n", L->pn->value);
                pos2_mot++;
                L=L->next;


            }

        }
        printf("%u\n", __LINE__);
        printf("%c", L->pn->children->pn->value);
        printf("%u\n", __LINE__);

        //tant que la lettre existe dans les enfants on prend prohcaine lettre sinon on créer toutes le lettres à la suite




    return 0;
}
