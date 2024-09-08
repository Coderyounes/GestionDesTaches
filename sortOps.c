#include "main.h"

void bubbleSort(Tache_t taches[], int count)
{
    int i, j;
    Tache_t *tache;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(taches[j].title, taches[j + 1].title) > 0)
            {
                Tache_t temp = taches[j];
                taches[j] = taches[j + 1];
                taches[j + 1] = temp;
            }
        }
    }
}

// fix the printing Issue in the Sort
void sortByAlpha(FILE *fp)
{
    char buffer[MAX];
    int i = 0, lines = countlines(fp);
    Tache_t taches[lines];

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        sscanf(buffer, "%d %s %s %s %s", &taches[i].id,
               taches[i].title,
               taches[i].description,
               taches[i].status,
               taches[i].deadline);
    }

    bubbleSort(taches, lines);
    for (i = 0; i < lines; i++)
    {
        printf("%d %s %s %s %s\n", taches[i].id,
               taches[i].title,
               taches[i].description,
               taches[i].status,
               taches[i].deadline);
    }
}

void sortOps(int choice)
{
    FILE *fp = fileops(tfile, "r");
    switch (choice)
    {
    case 1:
        sortByAlpha(fp);
        break;
    case 2:
        // sortByDeadline()
        break;
    case 0:
        break;
    default:
        printf("Enter from  0 to 2\n");
        break;
    }
}