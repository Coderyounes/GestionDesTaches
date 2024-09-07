#include "main.h"


int main() {
    int choix;
    char word[50];

    while(1) {
        welcome();
        printf("Entree votre choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                ajouteTache();
                break;
            case 2:
                afficherTaches();
                break;
            case 3:
                // modifier une tache
                break;
            case 4:
                // delete une tache
                break;
            case 5:
                break;
            case 0:
                printf("Exit Program....\n");
                exit(0);
            default:
                printf("Please Enter a Choice beetwen 0-6\n");
                break;
        }
    }
    return(0);
}