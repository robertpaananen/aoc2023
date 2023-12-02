#include <stdio.h>
#include "file.h"
FILE *open_file(char *file)
{
    // open file
    FILE *fp;
    fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return NULL;
    }
    return fp;
}