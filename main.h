#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
#define CHECK_ALLOC(ptr) if(!(ptr)) { perror ("Memory Allocation Failed"); return;}
#define tfile "tachefile.txt"
#define ufile "userfile.txt"

typedef struct tache {
    /*int id;*/
    char status[MAX];
    char title[MAX];
    char description[MAX];
    char deadline[MAX];
} Tache_t;

typedef struct user {
    char nom[MAX];
    char prenom[MAX];
    char email[MAX];
} User_t;

typedef struct date {
    char jour;
    char month;
    char year;
} Date_t;

void ajouteTache();
void afficherTaches();
void modifieTache(char name[], char new[]);
/*void ajoutesTaches();
void deleteTache();*/

// fileOperation
FILE *fileops(char filename[], char mode[]);


//auxillary function
void welcome();
char *clearString(char *s);

#endif