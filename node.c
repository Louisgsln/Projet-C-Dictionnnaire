#include "node.h"
#include <stdlib.h>
#include <stdio.h>

p_node createNode(char val)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->value = val;
    nouv-> children = NULL;
    nouv->forms = NULL;

    return nouv;
}

int recherche_lettre_children(LISTE L, char c){
    if (L == NULL){
        return 0;
    }
    else{
        if (c == L->pn->value){
            return 1;
        }
        return recherche_lettre_children(L->next, c);
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
        afficherListe(L);
        afficher_enfants(L->pn->children);
    }
}
