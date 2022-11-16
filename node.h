#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H
#define TAILLE_MAX 1000
struct s_children;
typedef struct s_children *p_children;
struct s_forms;
typedef struct s_forms *p_forms;


typedef struct s_node{
    char value;
    p_children children;
    p_forms forms;
} *p_node, t_node;

typedef struct s_children{
    p_node pn;
    struct s_children *next;
} t_children;

typedef p_children LISTE;


typedef struct s_forms{
    //inofrmation (ex: Ver:IFut+SG+P1)
    char infos[TAILLE_MAX];
    //mot (ex: abandonnerai)
    char value[TAILLE_MAX];
    struct s_forms *next;
} t_forms;

p_node createNode(char);
int recherche_lettre_children(LISTE, char);
p_children createChildren(p_node);
LISTE add_end_Children(LISTE, p_node);
void Display_List(LISTE );
LISTE add_word_tree(LISTE, char*, char*, char*);
void Display_children(LISTE );
int research_letter(p_children, char);
void enter_word_tree_entire(p_node, char *, char*, char*);
int search_word(p_node,  char *);
p_children research_children(p_children, char);
p_forms createForms(char *, char *);
p_forms add_end_Forms(p_forms , char *, char *);
void Display_word_associated(p_forms );
void random_node_research(p_node);
int children_number(LISTE L);
int choice_word();

#endif //UNTITLED_NODE_H
