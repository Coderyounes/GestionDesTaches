#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 1024
#define FMEMO "Failed to Allocate Memory"
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

void welcome();
void ajouteTache();
void afficherTaches();
/*void ajoutesTaches();
void modifieTache();
void deleteTache();*/

// fileOperation
FILE *fileops(char filename[], char mode[]);

#endif