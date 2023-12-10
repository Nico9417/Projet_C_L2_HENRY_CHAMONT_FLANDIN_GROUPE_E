#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"
#include <math.h>
#include "timer.h"
#include <time.h>

//Fonction permettant de créer une cellule vide

t_sk_cell* CreateCell(int valeur, int level) {
    t_sk_cell* new_cell = (t_sk_cell*)malloc(sizeof(t_sk_cell));
    new_cell->value = valeur;
    new_cell->next = (t_sk_cell**)malloc(sizeof(t_sk_cell*) * (level));
    new_cell->nb_level = level;
    for(int i = 0; i < level; i++) {
        new_cell->next[i] = NULL;
    }
    return new_cell;
}

//Fonction permettant de créer une liste vide

t_sk_list CreateEmptyList(int level) {
    t_sk_list new_list;
    new_list.heads = (t_sk_cell**)malloc(sizeof(t_sk_cell*) * (level));
    new_list.max_cell = level;
    for(int i = 0; i < level; i++) {
        new_list.heads[i] = NULL;
    }
    return new_list;
}


//Fonction permettant d'insérer une valeur en tête de liste

void insertHead(t_sk_list *liste, int valeur, int level) {
    t_sk_cell *new_cell = CreateCell(valeur, level);
    t_sk_cell *tmp = (t_sk_cell*)malloc(sizeof(t_sk_cell));
    for (int i=0; i<=level; i++) {
        tmp = liste->heads[i];
        liste->heads[i] = new_cell;
        new_cell->next[i] = tmp;
    }
}

//Fonction permettant d'afficher la liste à un niveau donné

void display_list(t_sk_list* list, int level) {
    t_sk_cell * tmp = list->heads[level];
    printf("[list head_%d @-]-->", level);
    while (tmp != NULL) {
        printf("[ %d|@-]--> ", tmp->value);
        tmp = tmp->next[level];
    }
    printf ("NULL");
    printf("\n");
}

//Fonction permettant d'afficher la liste à tous les niveaux

void displayAlllist(t_sk_list* list) {
    for (int i = 0; i < list->max_cell; i++) {
        display_list(list, i);
    }
}

//Fonction permettant d'insérer uen valeur dans la liste à un niveau donné

void insertList(t_sk_list* liste, int valeur, int level) {
    ptr_cell new_cell = CreateCell(valeur, level);
    for (int i = 0; i < level; i++) {
        if (liste->heads[i] == NULL  || liste->heads[i]->value >= valeur) {
            new_cell->next[i] = liste->heads[i];
            liste->heads[i] = new_cell;
        } else {
            ptr_cell temp = liste->heads[i];
            while (temp->next[i] != NULL && temp->next[i]->value < valeur) {
                temp = temp->next[i];
            }
            new_cell->next[i] = temp->next[i];
            temp->next[i] = new_cell;
        }
    }
}

//Fonction permettant de savoir si la valeur est dans la liste à un niveau donné

int isInList(t_sk_list *liste, int level, int valeur)
{
    t_sk_cell *tmp= liste->heads[level-1];
    while (tmp != NULL)
    {
        if (tmp->value == valeur)
        {
            return 1;
        }
        tmp = tmp->next[level-1];
    }
    return 0;
}

//Fonction permettant de savoir si la valeur est dans la liste en parcourant tous ces niveaux

void isInlistAll(t_sk_list *liste, int valeur){
    int level = 4;
    t_sk_cell *current = liste->heads[level];
    t_sk_cell *prev = current;
    while (level >= 0) {
        while (current != NULL) {
            if (current->value == valeur) {
                printf("La valeur %d est dans la liste au niveau %d\n", valeur, level);
                return;
            } else if (current->value > valeur) {
                break;
            }

            prev = current;
            current = current->next[level];
        }
        --level;
        if (level >= 0) {
            if (prev != NULL){
                current = prev->next[level];
            } else {
                current = liste->heads[level];
            }
        }
    }
    printf("La valeur %d n'est pas dans la liste\n", valeur);
    return;
}

//Fonction permettant de faire n recherches aléatoires dans la liste à tous les niveaux

void search(int valeur, t_sk_list *liste, int n){
    startTimer();
    srand(time(NULL));
    for (int i = 0; i < valeur; i++) {
        isInlistAll(liste, rand() % n+1 );
    }
    stopTimer();
    displayTime();
}

//Fonction permettant de faire n recherches aléatoires dans la liste au niveau 0

void searchligne(int valeur, t_sk_list *liste, int n){
    startTimer();
    srand(time(NULL));
    for (int i = 0; i < valeur; i++) {
        isInList(liste, 1, rand() % n+1 );
    }
    stopTimer();
    displayTime();
}