#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "contact.h"
#include "fichier.h"

int main()
{
    int level = 5;
    int n;
    int valeur;

    printf("Donner le nombre de niveaux que vous souhaitez pour votre liste : ");
    scanf("%d", &n);

    t_sk_list liste = CreateEmptyList(level);
    int taille_cell = pow(2, n) - 1;

    for (int i = 1; i <= taille_cell; i++)
    {
        if (i % 2 == 0)
        {
            if (i % 4 == 0)
            {
                if (i % 8 == 0)
                {
                    if (i % 16 == 0)
                    {
                        insertList(&liste, i, 5);
                    }
                    else
                    {
                        insertList(&liste, i, 4);
                    }
                }
                else
                {
                    insertList(&liste, i, 3);
                }
            }
            else
            {
                insertList(&liste, i, 2);
            }
        }
        else
        {
            insertList(&liste, i, 1);
        }
    }

    int choix;

    do
    {
        printf("\nMenu :\n");
        printf("1. Afficher la liste au niveau 0\n");
        printf("2. Afficher tous les niveaux de la liste\n");
        printf("3. Insérer une valeur en tête de liste\n");
        printf("4. Insérer une valeur dans la liste\n");
        printf("5. Rechercher une valeur dans la liste\n");
        printf("6. Quitter\n\n");

        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                display_list(&liste, 0);
                break;
            case 2:
                displayAlllist(&liste);
                break;
            case 3 :
                printf("Entrez la valeur à insérer : ");
                scanf("%d", &valeur);
                insertHead(&liste, valeur, 5);
                break;
            case 4:
                printf("Entrez la valeur à insérer : ");
                scanf("%d", &valeur);
                printf("Entrez le niveau auquel vous souhaitez insérer la valeur : ");
                scanf("%d", &level);
                insertList(&liste, valeur, level+1);
                break;
            case 5:
                printf("Entrez la valeur à rechercher : ");
                scanf("%d", &valeur);
                isInlistAll(&liste, valeur);
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    } while (choix != 6);
    return 0;
}


