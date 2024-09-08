#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1024
#define CHECK_ALLOC(ptr)                    \
    if (!(ptr))                             \
    {                                       \
        perror("Memory Allocation Failed"); \
        return;                             \
    }
#define tfile "tachefile.txt"
#define ufile "userfile.txt"

#define TODO "à_réaliser"
#define INPROGRESS "en_cours_de_réalisation"
#define DONE "finalisée"

typedef struct tache
{
    int id;
    char status[MAX];
    char title[MAX];
    char description[MAX];
    char deadline[MAX];
} Tache_t;

typedef struct date
{
    char jour;
    char month;
    char year;
} Date_t;

void ajouteTache();
void afficherTaches();
void modifieTache(char name[], char newDescription[], char newStatus[], char newDeadline[]);
void deleteTache(int id);
/*void ajoutesTaches();
 */

// recherche functions
void searchOps();
void searchBytitre(char name[]);
/*void searchById(int id);*/

// sortOps

// fileOperation
FILE *fileops(char filename[], char mode[]);

// auxillary function
void welcome();
char *clearString(char *s);
int countlines(FILE *fp);

#endif