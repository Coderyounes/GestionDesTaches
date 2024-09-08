#include "main.h"

void welcome()
{
    printf("\n\n\tBonjour\n");
    printf("***********************************");
    printf("\n0: Exit\n");
    printf("1: Ajouter Une Tache\n");
    printf("2: Lister les Taches\n");
    printf("3: modifier une Taches\n");
    printf("4: supprimer une Taches\n");
    printf("5: recherche\n");
    printf("6: count total Tasks\n");
}

char *clearString(char *s)
{
    s[0] = '\0';
    return s;
}

int countlines(FILE *fp)
{
    int lines = 0;
    char buffer[MAX];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        lines++;
    }
    rewind(fp);
    return lines;
}