#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

//Fonction pour écrire une chaîne de caractère

char *scanString()
{
    char *mot = (char *)malloc(100*sizeof(char));
    scanf("%s", mot);
    return mot;
}

//Fonction pour créer et initialiser une variable de type Contact avec des valeurs

Contact* creerContact(const char* nom, const char* prenom) 
{
    Contact* nouveauContact = (Contact*)malloc(sizeof(Contact));
    nouveauContact->nom = strdup(nom);
    nouveauContact->prenom = strdup(prenom);
    return nouveauContact;
}

//Fonction pour créer et initialiser une variable de type RDV avec des valeurs

RDV* creerRendezVous(int jour, int mois, int annee, int heure, int minute, int dureeHeure, int dureeMinute, const char* objet) 
{
    RDV* nouveauRendezVous = (RDV*)malloc(sizeof(RDV));
    nouveauRendezVous->date.jour = jour;
    nouveauRendezVous->date.mois = mois;
    nouveauRendezVous->date.annee = annee;
    nouveauRendezVous->heure.heure = heure;
    nouveauRendezVous->heure.minute = minute;
    nouveauRendezVous->duree.heure = dureeHeure;
    nouveauRendezVous->duree.minute = dureeMinute;
    nouveauRendezVous->objet = strdup(objet);
    return nouveauRendezVous;
}

//Fonction pour libérer l'espace alloué d'une variable Contact

void libererContact(Contact* contact) 
{
    free(contact->nom);
    free(contact->prenom);
    free(contact);
}

//Fonction pour libérer l'espace alloué d'une variable RDV

void libererRendezVous(RDV* rendezVous) 
{
    free(rendezVous->objet);
    free(rendezVous);
}

//Fonction pour insérer un contact

void insertSortedByName(Contact** head, Contact* newContact) {
    Contact* prev = NULL;
    Contact* current = *head;
    while (current != NULL && strcmp(newContact->nom, current->nom) > 0) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        newContact->next = *head;
        *head = newContact;
    } else {
        prev->next = newContact;
        newContact->next = current;
    }
}

//Fonction pour afficher la liste de contact

void printContactList(Contact* head) {
    Contact* current = head;
    while (current != NULL) {
        printf("Nom: %s, Prenom: %s\n", current->nom, current->prenom);
        current = current->next;
    }
}

void test()
{
  Contact* head = NULL;
  Contact* contact1 = creerContact("John", "Doe");
  insertSortedByName(&head, contact1);
  Contact* contact2 = creerContact("Alice", "Smith");
  insertSortedByName(&head, contact2);
  Contact* contact3 = creerContact("Bob", "Johnson");
  insertSortedByName(&head, contact3);
  printContactList(head);
  libererContact(contact1);
  libererContact(contact2);
  libererContact(contact3);
}
