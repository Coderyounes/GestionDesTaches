#include "main.h"


int main() {
    int choix;
    char word[50], newdescription[50], newStatus[50], newDeadline[50];
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
                printf("Entree le nouveau description: ");
                scanf("%s", newdescription);
                printf("Entree la nouveau stats: ");
                scanf("%s", newStatus);
                printf("Enter le nouveau deadline: ");
                scanf("%s", newDeadline);
                modifieTache(word, newdescription, newStatus, newDeadline);
                clearString(word);
                break;
            case 4:
                printf("Entree le titre de tache a supprimer: ");
                scanf("%s", word);
                deleteTache(word);
                clearString(word);
                break;
            case 5:
                searchOps();
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