
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

