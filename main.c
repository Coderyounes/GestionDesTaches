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
                printf("Entree la Tache Titre: ");
                scanf("%s", word);
                modifieTache(word);
                clearString(word);
                break;
            case 4:
                printf("This the Word String: %s\n", word);
                break;
            case 5:
                break;
                printf("Exit Program....\n");
                exit(0);
            default:
                printf("Please Enter a Choice beetwen 0-6\n");
                break;
        }
    }
    return(0);
}