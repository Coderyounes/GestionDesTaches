#include "main.h"

int main()
{
    int choix, id;
    char word[50], newdescription[50], newStatus[50], newDeadline[50];
    while (1)
    {
        welcome();
        printf("Entree votre choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
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
            printf("Entree l'identifiant  de tache a supprimer: ");
            scanf("%d", &id);
            deleteTache(id);
            break;
        case 5:
            searchOps();
            break;
        case 6:
            printf("Total of Tasks are : %d Task\n", countTache());
            break;
        case 7:
            printf("Select the Sort Mode\n1: by alphabet\n2: By deadline\nn");
            printf("enter your choice: ");
            scanf("%d", &choix);
            sortOps(choix);
            break;
        case 0:
            printf("Exit Program....\n");
            exit(0);
        default:
            printf("Please Enter a Choice beetwen 0-6\n");
            break;
        }
    }
    return (0);
}