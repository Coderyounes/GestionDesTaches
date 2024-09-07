#include "main.h"


FILE *fileops(char filename[], char mode[]) {
    FILE *fp = fopen(filename, mode);

    if (filename == NULL || mode == NULL ) {
        perror("File or mode didn't pass\n");
        return NULL;
    }
    if (fp == NULL) {
        perror("Failed to Open the file\n");
        return NULL;
    }
    return fp;
}