#include "main.h"

void welcome() {
    printf("\n\tBonjour\n");
    printf("***********************************");
    printf("\n0: Exit\n");
    printf("1: Ajouter Une Tache\n");
    printf("2: Lister les Taches\n");
    printf("3: modifier une Taches\n");
    printf("4: supprimer une Taches\n");
}

char *clearString(char *s) {
    s[0] = '\0';
    return s;
}