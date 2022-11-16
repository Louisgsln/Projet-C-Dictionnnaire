#include "node.h"
#include <stdlib.h>
#include <string.h>
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


int research_letter(p_children children, char c){

    //printf("- %c", children->pn->value);
    if (children == NULL){
        return 0;
    }
    if (c == children->pn->value){
        return 1;
    }
    else{
        return research_letter(children->next, c);
    }
}

p_children research_children(p_children children, char c){

    //printf("- %c", children->pn->value);
    if (children == NULL){
        return NULL;
    }
    if (c == children->pn->value){
        return children;
    }else{
        return research_children(children->next, c);
    }
}

p_children createChildren(p_node pn){
    p_children nouv;
    nouv = (p_children) malloc(sizeof(t_children));
    nouv ->pn = pn;
    nouv->next = NULL;

    return nouv;
}

p_forms createForms(char *infos, char *mot){
    p_forms nouv;
    nouv = (p_forms) malloc(sizeof(t_forms));
    strcpy(nouv -> infos, infos);
    strcpy(nouv -> value, mot);
    nouv->next = NULL;

    return nouv;
}



LISTE add_end_Children(LISTE L, p_node pn)
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

p_forms add_end_Forms(p_forms L, char *infos, char *mot)
{
    p_forms nouvelElement = createForms(infos, mot);

    if (L == NULL)
    {
        return nouvelElement;
    }
    else
    {
        p_forms temp= L;
        while(temp->next != NULL)
        {
            temp = temp-> next;
        }
        temp->next = nouvelElement;
        return L;
    }
}

void Display_List(LISTE L)
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

void Display_word_associated(p_forms F)
{
    p_forms tmp = F;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On affiche */
        printf("mots flechis : %s\n ", tmp->value);
        /* On avance d'une case */
        tmp = tmp->next;
    }
}

LISTE add_word_tree(LISTE L, char *mot, char *infos, char *mots_flechis){
    //printf("%s:%u - L: 0x%lx\n", __FILE__, __LINE__, L);
    if (mot[0] == '\0'){
        return NULL;
    }
    else{

        p_node pn = createNode(mot[0]);
        L = add_end_Children(L, pn);
        //afficherListe(L);
        pn -> children = add_word_tree(pn->children,mot+1, infos, mots_flechis);
        if (pn -> children == NULL){
            pn->forms = add_end_Forms(pn->forms, infos, mots_flechis);
            Display_word_associated(pn->forms);
        }
    }
    return L;
}


void Display_children(LISTE L){
    if (L == NULL){
        return;
    }
    else {
        p_children tmp;
        tmp = L;

        Display_List(L);
        while (tmp != NULL) {
            Display_children(tmp->pn->children);
            tmp = tmp->next;
        }
    }
}

void enter_word_tree_entire(p_node pn,  char *mot, char *infos, char *mots_flechis){
    //printf("%s:%u - mot %s\n", __FILE__,__LINE__, mot);
    if (research_letter(pn->children, mot[0])){
        //printf("%s:%u", __FILE__,__LINE__);
        enter_word_tree_entire(pn->children->pn, mot+1, infos, mots_flechis);
    }
    else{
        pn->children = add_word_tree(pn->children, mot , infos, mots_flechis);
        if (pn->children == NULL){
            pn->forms = add_end_Forms(pn->forms, infos, mots_flechis);
            Display_word_associated(pn->forms);
        }
    }
}

int search_word(p_node pn,  char *mot){
    if (mot[0] == '\0'){
        return 1;
    }
    //printf("%s:%u - mot %s\n", __FILE__,__LINE__, mot);
    p_children enfant = research_children(pn->children, mot[0]);
    if (enfant != NULL){
        //printf("%s:%u", __FILE__,__LINE__);
        return search_word(enfant->pn, mot+1);
    }
    else{
        return 0;
    }
}
int children_number(LISTE L){
    LISTE tmp = L;
    int cpt=0;
/* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        cpt++;
/* On avance d'une case */
        tmp = tmp->next;
    }return cpt;
}

void random_node_research(p_node node){


    int fate = rand() % children_number(node->children);
    p_node temp = node;
    p_children child = node->children; //
    for (int i = 0; i < fate ; i++)
        child = child->next;
    temp = child->pn;
    printf("%c",temp->value);
    if (children_number(temp->children) > 0) {//has next characters
        if (temp->forms == NULL || choice_word()) //does not have next characters or continue
            random_node_research(temp);
    }
}

//évite de choisir toujours le premier mot
int choice_word(){
    int fate_choice;
    if (rand()% 2 == 0)
        fate_choice = 0;
    else
        fate_choice = 1;
    return fate_choice;
}
