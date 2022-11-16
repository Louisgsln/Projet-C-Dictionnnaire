#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
#include "bintree.h"
#include "fichier.h"

#define TAILLE_MAX 1000 // Tableau de taille 1000

void fill_in_words_cut(char mots_coupes[3][TAILLE_MAX], char *chaine)
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

    fichier = fopen("dico_10_lignes.txt", "r");

    if (fichier != NULL) {
        //fgets(chaine, TAILLE_MAX, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
        //printf("%s", chaine); // On affiche la chaîne
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) {
            printf("\n%s ", chaine); // On affiche la chaîne
            //couper la  ligne
            char mots_coupes[3][TAILLE_MAX];

            fill_in_words_cut(mots_coupes, chaine);

            //trouver quel type d'arbre
            int res = search_tree(mots_coupes[2]);

            if (res ==1){
                enter_word_tree_entire(t_nom.root, mots_coupes[1],mots_coupes[2], mots_coupes[0]);
                printf("mot ajoute dans l'arbre : ");
                Display_children(t_nom.root->children);
                printf("\n");
            }
            if (res == 2){
                enter_word_tree_entire(t_verbe.root, mots_coupes[1],mots_coupes[2], mots_coupes[0]);
                printf("mot ajoute dans l'arbre : ");
                Display_children(t_verbe.root->children);
                printf("\n");
            }
            if (res == 3){
                enter_word_tree_entire(t_adj.root, mots_coupes[1],mots_coupes[2], mots_coupes[0]);
                printf("mot ajoute dans l'arbre : ");
                Display_children(t_adj.root->children);
                printf("\n");
            }
            if (res == 4){
                enter_word_tree_entire(t_adv.root, mots_coupes[1],mots_coupes[2], mots_coupes[0]);
                Display_children(t_adv.root->children);
                printf("mot ajoute dans l'arbre : ");
                printf("\n");
            }
        }
        fclose(fichier);
    }

    printf("%d\n", search_word(t_nom.root, "stabilimetre"));

    printf("%d\n", search_word(t_nom.root, "stabilisant"));

    printf("%d\n", search_word(t_nom.root, "stabiliser"));
    
    printf("\nBonjour ! \n");
    int end = 0;
    while (end!=1){
        printf("\nQuel modèle de phrases souhaitez-vous générer ? \n\n");
        printf("1 - Modèle n°1 : nom – adjectif – verbe – nom\n2 - Modèle n°2 : nom – 'qui' – verbe – verbe – nom – adjectif \n3 - Modèle n°3 : nom - verbe - adjectif - 'avec' - nom \n");
        int rep;
        printf("\nSaisissez le numéro correspondant : ");
        fflush(stdin);
        scanf("%d",&rep);

        while(rep!=1 & rep!=2 & rep!=3){
            printf("Le numéro saisit ne correspond à aucune des propositions.\n\n");
            printf("1 - Modèle n°1 : nom – adjectif – verbe – nom\n2 - Modèle n°2 : nom – 'qui' – verbe – verbe – nom – adjectif \n3 - Modèle n°3 : nom - verbe - adjectif - 'avec' - nom ");
            printf("\n\nSaisissez le numéro correspondant : ");
            scanf("%d",&rep);
        }
        printf("\n");

        if (rep==1){

            // ajouter fonction pour modèle 1

            random_node_research(t_nom.root);
            printf(" ");
            random_node_research(t_nom.root);
            printf(" ");
            random_node_research(t_verbe.root);
            printf(" ");
            random_node_research(t_nom.root);
        }

        if (rep==2){
            // ajouter fonction pour modèle 2
            random_node_research(t_nom.root);
            printf(" qui ");
            random_node_research(t_verbe.root);
            printf(" ");
            random_node_research(t_verbe.root);
            printf(" ");
            random_node_research(t_nom.root);
            printf(" ");
            random_node_research(t_adj.root);
        }
        if (rep==3){
            // ajouter fonction pour modèle 3
            random_node_research(t_nom.root);
            printf(" ");
            random_node_research(t_verbe.root);
            printf(" ");
            random_node_research(t_adj.root);
            printf(" avec ");
            random_node_research(t_nom.root);
        }

        printf("\n\nAvez-vous terminé?\n");
        printf("Saisir 1 pour oui ou 2 pour non : ");
        fflush(stdin);
        scanf("%d",end);
        printf("%d",end);
    }
    return 0;
}
