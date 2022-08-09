#include <stdio.h>
#include <stdlib.h>
#include "./include/sorter.h"
#define BUFFER_LENGTH MAX_SEQUENCE_LENGTH * (SIGNIFICANT_DIGITS+1)

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        printf("Missing arguments. Terminal input should be in the form:\n");
        printf("\"./sequenceSorter <input-file-name>.csv <output-file-name>.csv\"\n");
        return 0;
    }
    char const *inputFilename = argv[1];
    char const *outputFilename = argv[2];

    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");
    
    fseek(inputFile, 0, SEEK_END);
    int fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    char *buffer = malloc(fileSize);

    while (fgets(buffer, fileSize, inputFile))
    {
        char *newLine = sorter(buffer);
        fputs(newLine, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
    free(buffer);
    // buffer = realloc(buffer, 0);
    return 0;
}