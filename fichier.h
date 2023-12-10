#include <stdio.h>


typedef struct s_sk_cell
{
    int value;
    int nb_level;
    struct s_sk_cell **next;
} t_sk_cell, *ptr_cell;

typedef struct s_sk_list
{
    t_sk_cell **heads;
    int max_cell;
} t_sk_list;


t_sk_list *create_list(int max_level);
t_sk_cell* CreateCell (int, int);

t_sk_list CreateEmptyList (int);

void insertHead(t_sk_list *, int, int);

void display_list(t_sk_list* list, int level);
void displayAlllist(t_sk_list* list);
void insertList(t_sk_list* liste, int valeur, int level);
int isInList(t_sk_list* liste, int level, int valeur);
void isInlistAll(t_sk_list *liste, int valeur);
void searchligne(int valeur, t_sk_list *liste, int n);
