#include <stdio.h>
#include <stdlib.h>
#include "./include/sorter.h"
#define BUFFER_LENGTH 104

int main(int argc, char const *argv[])
{
    char *inputFilename = argv[1];
    char *outputFilename = argv[2];

    char *buffer = malloc(sizeof(char) * BUFFER_LENGTH);

    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");

    while (fgets(buffer, BUFFER_LENGTH, inputFile))
    {
        char *newLine = sorter(buffer);
        fputs(newLine, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
    free(buffer);
    return 0;
}