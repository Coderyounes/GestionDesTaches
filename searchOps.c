#include "main.h"

// Une simple switch pour mieux manager les choix d'utilisateur
// Cree 2 recherche function  une par titre l'autre par identifiant 
// Implement Binary Search Alghorithme
/*void searchById(int id);*/

void searchBytitre(char name[]);

void searchOps(char name[]) {
    int choice;
    printf("1: recherche par titre\n");
    printf("2: recherche par id\n");
    printf("Entree votre choix:");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            searchBytitre(name);
            break;
        case 2:
            printf("in Case 2\n");
            break;
        case 0:
            printf("Go to Menu\n");
            break;
        default:
            printf("either 1 or 2\n");
            break;
    }
}