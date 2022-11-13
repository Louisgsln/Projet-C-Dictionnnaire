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
LISTE ajouterEnFinChildren(LISTE, p_node);
void afficherListe(LISTE );
LISTE ajouter_mot_arbre(LISTE, char*, char*, char*);
void afficher_enfants(LISTE );
int recherche_lettre(p_children, char);
void rentrer_mot_arbre_entier(p_node, char *, char*, char*);
int recherche_mot(p_node,  char *);
p_children recherche_enfant(p_children, char);
p_forms createForms(char *, char *);
p_forms ajouterEnFinForms(p_forms , char *, char *);
void affichermots_flechis(p_forms );

#endif //UNTITLED_NODE_H
