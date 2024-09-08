#include "main.h"

void ajouteTache()
{
    int count;
    char buffer[MAX];
    Tache_t *T;
    FILE *fp, *tfp;

    T = malloc(sizeof(Tache_t));
    CHECK_ALLOC(T);

    fp = fileops(tfile, "a");
    tfp = fileops(tfile, "r");
    count = countlines(tfp);
    getchar();
    printf("Entre titel, description, deadline: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        T->id = count + 1;
        sscanf(buffer, "%s %s %s", T->title, T->description, T->deadline);
        strcpy(T->status, TODO);
        fprintf(fp, "%d %s %s %s %s\n", T->id, T->title, T->description, T->status, T->deadline);
    }
    fclose(fp);
    fclose(tfp);
    free(T);
}

void afficherTaches()
{
    char buffer[MAX];
    Tache_t *T;
    FILE *fp;

    T = malloc(sizeof(Tache_t));
    CHECK_ALLOC(T);

    fp = fileops(tfile, "r");
    if (fp < 0)
    {
        perror("File Error");
        return;
    }
    while (fgets(buffer, sizeof(buffer), fp))
    {
        sscanf(buffer, "%d %s %s %s %s", &T->id, T->title, T->description, T->status, T->deadline);
        printf("%d %s %s %s %s\n", T->id, T->title, T->description, T->status, T->deadline);
    }
    fclose(fp);
    free(T);
}

// Update: Modification by ID
void modifieTache(char titre[], char newDescription[], char newStatus[], char newDeadline[])
{
    char buffer[MAX];
    Tache_t *T;
    FILE *fp, *tfp;

    T = malloc(sizeof(Tache_t));
    CHECK_ALLOC(T);

    fp = fileops(tfile, "r");
    tfp = fileops("temp.txt", "a");
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        sscanf(buffer, "%s %s %s %s", T->title, T->description, T->status, T->deadline);
        if (strcmp(T->title, titre) == 0)
        {
            strcpy(T->description, newDescription);
            strcpy(T->status, newStatus);
            strcpy(T->deadline, newDeadline);
        }
        fprintf(tfp, "%s %s %s %s\n", T->title, T->description, T->status, T->deadline);
    }

    free(T);

    fclose(fp);
    fclose(tfp);

    remove(tfile);
    rename("temp.txt", tfile);
}

// Update: Delete function should delete by ID

void deleteTache(int id)
{
    char buffer[MAX];
    Tache_t *T;
    FILE *fp, *tfp;

    T = malloc(sizeof(Tache_t));
    CHECK_ALLOC(T);

    fp = fileops(tfile, "r");
    tfp = fileops("temp.txt", "a");

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        sscanf(buffer, "%d %s %s %s %s", &T->id, T->title, T->description, T->status, T->deadline);
        if (T->id > id)
        {
            fprintf(tfp, "%d %s %s %s %s\n", T->id - 1, T->title, T->description, T->status, T->deadline);
        }
        else if (T->id != id)
        {
            fprintf(tfp, "%d %s %s %s %s\n", T->id, T->title, T->description, T->status, T->deadline);
        }
    }

    fclose(fp);
    fclose(tfp);

    remove(tfile);
    rename("temp.txt", tfile);

    free(T);
}
