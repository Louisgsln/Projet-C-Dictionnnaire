#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"

p_node createNode(char val)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->value = val;
    nouv-> children = NULL;
    nouv->forms = NULL;

    return nouv;
}

/*int recherche_lettre_children(LISTE L, char c){
    if (L == NULL){
        return 0;
    }
    else{
        if (c == L->pn->value){
            return 1;
        }
        return recherche_lettre_children(L->next, c);
    }
}*/

int recherche_lettre(p_children children, char c){

    //printf("- %c", children->pn->value);
    if (children == NULL){
        return 0;
    }
    if (c == children->pn->value){
        return 1;
    }else{

        return recherche_lettre(children->next, c);
    }

}

p_children recherche_enfant(p_children children, char c){

    //printf("- %c", children->pn->value);
    if (children == NULL){
        return NULL;
    }
    if (c == children->pn->value){
        return children;
    }else{
        return recherche_enfant(children->next, c);
    }
}

p_children createChildren(p_node pn){
    p_children nouv;
    nouv = (p_children) malloc(sizeof(t_children));
    nouv ->pn = pn;
    nouv->next = NULL;

    return nouv;
}

LISTE ajouterEnFin(LISTE L, p_node pn)
{
    LISTE nouvelElement = createChildren(pn);


    if(L == NULL)
    {
        /* Si la liste est videé il suffit de renvoyer l'élément créé */
        return nouvelElement;
    }
    else
    {
        /* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
        LISTE temp= L;
        while(temp->next != NULL)
        {
            temp = temp-> next;
        }
        temp->next = nouvelElement;
        return L;
    }
}


void afficherListe(LISTE L)
{
    LISTE tmp = L;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On affiche */
        printf("%c ", tmp->pn->value);
        /* On avance d'une case */
        tmp = tmp->next;
    }
}

LISTE ajouter_mot_arbre(LISTE L, char *mot){
    //printf("%s:%u - L: 0x%lx\n", __FILE__, __LINE__, L);
    if (mot[0] == '\0'){
        return NULL;
    }
    else{

        p_node pn = createNode(mot[0]);
        L = ajouterEnFin(L, pn);
        //afficherListe(L);
        pn -> children = ajouter_mot_arbre(pn->children,mot+1);

    }
    return L;
}


void afficher_enfants(LISTE L){
    if (L == NULL){
        return;
    }
    else {
        p_children tmp;
        tmp = L;

        afficherListe(L);
        while (tmp != NULL) {
            afficher_enfants(tmp->pn->children);
            tmp = tmp->next;
        }
    }
}

void rentrer_mot_arbre_entier(p_node pn,  char *mot){
    //printf("%s:%u - mot %s\n", __FILE__,__LINE__, mot);
    if (recherche_lettre(pn->children, mot[0])){
        //printf("%s:%u", __FILE__,__LINE__);
        rentrer_mot_arbre_entier(pn->children->pn, mot+1);
    }
    else{
        pn->children = ajouter_mot_arbre(pn->children, mot);
    }
}

int recherche_mot(p_node pn,  char *mot){
    if (mot[0] == '\0'){
        return 1;
    }
    //printf("%s:%u - mot %s\n", __FILE__,__LINE__, mot);
    p_children enfant = recherche_enfant(pn->children, mot[0]);
    if (enfant != NULL){
        //printf("%s:%u", __FILE__,__LINE__);
        return recherche_mot(enfant->pn, mot+1);
    }
    else{
        return 0;
    }
}
