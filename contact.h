#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_sk_cell_3 {
    int value;
    int nb_level;
    struct s_sk_cell** next;
} t_sk_cell_3, *ptr_cell_3;

typedef struct s_sk_list_3 {
    t_sk_cell** heads;
    int max_cell;
} t_sk_list_3;

typedef struct s_contact {
    char* nom;
    char* prenom;
    struct s_contact* next;
} Contact;

typedef struct s_date {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct s_heure {
    int heure;
    int minute;
} Heure;

typedef struct s_rdv {
    Date date;
    Heure heure;
    Heure duree;
    char* objet;
    struct s_rdv* next;
} RDV;

//Nos fonctions 

char *scanString(void);

Contact* creerContact(const char* nom, const char* prenom);

RDV* creerRendezVous(int jour, int mois, int annee, int heure, int minute, int dureeHeure, int dureeMinute, const char* objet);

void libererContact(Contact* contact);

void libererRendezVous(RDV* rendezVous);
