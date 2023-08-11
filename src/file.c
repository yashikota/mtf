#include "file.h"

#include <stdlib.h>
#include <string.h>

#include "option.h"

FILE *fileOpen(const char *fileName, const char *mode) {
    FILE *fp = fopen(fileName, mode);
    if (fp == NULL) {
        perror(fileName);
        exit(EXIT_FAILURE);
    }

    return fp;
}

char *outputFileName(char *fileName, const char *extention) {
    char *p = strrchr(fileName, '/');
    if (p != NULL) {
        fileName = p + 1;
    }
    fileName = strdup(fileName);

    p = strrchr(fileName, '.');
    if (p != NULL) {
        *p = '\0';
    }

    if (strcmp(extention, "mtf") == 0) {
        strcat(fileName, ".mtf");
    } else if (strcmp(extention, "txt") == 0) {
        strcat(fileName, ".txt");
    }

    return fileName;
}
