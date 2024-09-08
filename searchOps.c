#include "main.h"

void searchBytitre(char name[])
{
    char buffer[MAX];
    Tache_t *T;
    FILE *fp;
    T = malloc(sizeof(Tache_t));
    CHECK_ALLOC(T);
    fp = fileops(tfile, "r");
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        sscanf(buffer, "%s %s %s %s", T->title, T->description, T->status, T->deadline);
        if (strcmp(T->title, name) == 0)
        {
            printf("Found: %s %s %s %s\n", T->title, T->description, T->status, T->deadline);
        }
    }
    fclose(fp);
    free(T);
}

void searchByid(int id)
{
    char buffer[MAX];
    Tache_t *T;
    FILE *fp;
    T = malloc(sizeof(Tache_t));
    CHECK_ALLOC(T);
    fp = fileops(tfile, "r");
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        sscanf(buffer, "%d %s %s %s %s", &T->id, T->title, T->description, T->status, T->deadline);
        if (T->id == id)
        {
            printf("Found: %d %s %s %s %s\n", T->id, T->title, T->description, T->status, T->deadline);
        }
    }
    fclose(fp);
    free(T);
}

void searchOps()
{
    int choice, id;
    char word[MAX];

    printf("1: recherche par titre\n");
    printf("2: recherche par id\n");
    printf("Entree votre choix:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Quel Titre a Rechercher: ");
        scanf("%s", word);
        searchBytitre(word);
        clearString(word);
        break;
    case 2:
        printf("Entre la tache identifiant: ");
        scanf("%d", &id);
        searchByid(id);
        break;
    case 0:
        printf("Go to Menu\n");
        break;
    default:
        printf("either 1 or 2\n");
        break;
    }
}