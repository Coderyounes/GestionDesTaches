#include "main.h"

// Une simple switch pour mieux manager les choix d'utilisateur
// Cree 2 recherche function  une par titre l'autre par identifiant 
// Implement Binary Search Alghorithme
/*void searchById(int id);*/

void searchBytitre(char name[]) {
    char buffer[MAX];
    Tache_t *T;
    FILE *fp;
    T = malloc(sizeof(Tache_t));
    CHECK_ALLOC(T);
    fp = fileops(tfile, "r");
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%s %s %s %s", T->title, T->description, T->status, T->deadline);
        if (strcmp(T->title, name) == 0) {
            printf("Found: %s %s %s %s\n", T->title, T->description, T->status, T->deadline);
        }
    }
    fclose(fp);
    free(T);

}

void searchOps() {
    int choice;
    char word[MAX];

    printf("1: recherche par titre\n");
    printf("2: recherche par id\n");
    printf("Entree votre choix:");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Quel Titre a Rechercher: ");
            scanf("%s", word);
            searchBytitre(word);
            clearString(word);
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