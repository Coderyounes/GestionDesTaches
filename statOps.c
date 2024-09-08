#include "main.h"

int countTache()
{
    int count;
    FILE *fp;

    fp = fileops(tfile, "r");
    count = countlines(fp);
    fclose(fp);
    return count;
}