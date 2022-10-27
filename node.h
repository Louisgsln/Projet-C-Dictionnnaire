#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

typedef struct s_children{
    p_node pn;
    struct s_children *next;
} t_children, *p_children;

typedef struct s_forms{
    //inofrmation (ex: Ver:IFut+SG+P1)
    char infos[100];
    //mot (ex: abandonnerai)
    char value[100];
    struct s_forms *next;
} t_forms, *p_forms;


typedef struct s_node{
    char value[50];
    p_children children;
    p_forms forms;
} *p_node, t_node;



#endif //UNTITLED_NODE_H
