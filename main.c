#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
#include "bintree.h"
#include "fichier.h"


#define TAILLE_MAX 1000 // Tableau de taille 1000
//srand(time(NULL));
void remplis_mots_coupes(char mots_coupes[3][TAILLE_MAX], char *chaine)
{
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
        //printf("'%s'\n", mot);

        while(isspace(chaine[pos_chaine])) {
            pos_chaine++;
        }
    }
}

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    t_tree t_nom, t_verbe, t_adj, t_adv;
    t_nom.root = createNode('/');
    t_verbe.root = createNode('/');
    t_adv.root = createNode('/');
    t_adj.root = createNode('/');

    printf("Bonjour ! \nQuel modèle de phrases souhaitez-vous générer ? \n");
    printf("1 - Modèle n°1 : nom – adjectif – verbe – nom\n2 - Modèle n°2 : nom – ‘qui’ – verbe – verbe – nom – adjectif \n");
    int rep = 0;
    int i = 0;
    printf("Saisissez le numéro correspondant : ");
    scanf("%d",&rep);
    do{
        printf("Le numéro saisit ne correspond à aucune des propositions.\n");
        printf("1 - Modèle n°1 : nom – adjectif – verbe – nom\n2 - Modèle n°2 : nom – ‘qui’ – verbe – verbe – nom – adjectif \n3- Modèle n°3 : nom - verbe - nom - adverbe - verbe ");
        printf("Saisissez le numéro correspondant : ");
        scanf("%d",&rep);
    }while(rep!=1 & rep!=2 & rep!=3);
    if (rep==1){
        // ajouter fonction pour modèle 1
    }
    if (rep==2){
        // ajouter fonction pour modèle 2
    }
    if (rep==3){
        // ajouter fonction pour modèle 3
    }
    fichier = fopen("C:\\Users\\ameli\\CLionProjects\\Dictionnaire\\dico_10_lignes.txt", "r");

    if (fichier != NULL) {
        //fgets(chaine, TAILLE_MAX, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
        //printf("%s", chaine); // On affiche la chaîne
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) {
            printf("\n%s ", chaine); // On affiche la chaîne
            //couper la  ligne
            char mots_coupes[3][TAILLE_MAX];

            remplis_mots_coupes(mots_coupes, chaine);

            //trouver quel type d'arbre
            int res = trouver_arbre(mots_coupes[2]);

            if (res ==1){
                rentrer_mot_arbre_entier(t_nom.root, mots_coupes[1],mots_coupes[2], mots_coupes[0]);
                printf("mot ajoute dans l'arbre : ");
                afficher_enfants(t_nom.root->children);
                printf("\n");
            }
            if (res == 2){
                rentrer_mot_arbre_entier(t_verbe.root, mots_coupes[1],mots_coupes[2], mots_coupes[0]);
                printf("mot ajoute dans l'arbre : ");
                afficher_enfants(t_verbe.root->children);
                printf("\n");
            }
            if (res == 3){
                rentrer_mot_arbre_entier(t_adj.root, mots_coupes[1],mots_coupes[2], mots_coupes[0]);
                printf("mot ajoute dans l'arbre : ");
                afficher_enfants(t_adj.root->children);
                printf("\n");
            }
            if (res == 4){
                rentrer_mot_arbre_entier(t_adv.root, mots_coupes[1],mots_coupes[2], mots_coupes[0]);
                afficher_enfants(t_adv.root->children);
                printf("mot ajoute dans l'arbre : ");
                printf("\n");
            }
        }
        fclose(fichier);
    }

    printf("%d\n", recherche_mot(t_nom.root, "stabilimetre"));

    printf("%d\n", recherche_mot(t_nom.root, "stabilisant"));

    printf("%d\n", recherche_mot(t_nom.root, "stabiliser"));



    //couper la  ligne
    /*char mots_coupes[3][TAILLE_MAX];
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
        //printf("'%s'\n", mot);
        while(isspace(chaine[pos_chaine])) {
            pos_chaine++;
        }
    }
    //trouver quel type d'arbre
    int res = trouver_arbre(mots_coupes[2]);
    t_tree t_nom, t_verbe, t_adj, t_adv;
    t_nom.root = t_verbe.root = t_adv.root = t_adj.root = createNode('/');
    if (res ==1){
        rentrer_mot_arbre_entier(t_nom.root, mots_coupes[1]);
        afficher_enfants(t_nom.root->children);
        printf("\n");
    }
    if (res == 2){
        rentrer_mot_arbre_entier(t_verbe.root, mots_coupes[1]);
        afficher_enfants(t_verbe.root->children);
        printf("\n");
    }
    if (res == 3){
        rentrer_mot_arbre_entier(t_adj.root, mots_coupes[1]);
        afficher_enfants(t_adj.root->children);
        printf("\n");
    }
    if (res == 4){
        rentrer_mot_arbre_entier(t_adv.root, mots_coupes[1]);
        afficher_enfants(t_adv.root->children);
        printf("\n");
    }*/

    /*printf("%s\n", mots_coupes[2]);
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
    }*/



    /*LISTE L;
    p_node pn;
    t_tree t;
    t.root = createNode('/');*/


    /*
    //ajoute lettre dans liste_children du p_node precedent
    t.root->children = ajouter_mot_arbre(t.root->children, mots_coupes[1]);
    printf("\n");
    //affiche toutes les listes des enfants non nulles
    afficher_enfants(t.root->children);
    if (recherche_lettre(t.root ->children->pn->children->pn->children->pn->children, mots_coupes[1][3])){
        printf("\noui %c existe", mots_coupes[1][3]);
    }
    else{
        printf("\nnon %c existe pas", mots_coupes[1][3]);
    }*/

    /*rentrer_mot_arbre_entier(t.root, mots_coupes[1]);
    afficher_enfants(t.root->children);*/


    return 0;
}
