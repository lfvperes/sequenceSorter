#include <stdio.h>
#include <stdlib.h>
#include "./include/sorter.h"

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

    char *buffer = malloc(fileSize * sizeof(char));

    while (fgets(buffer, fileSize, inputFile))
    {
        char *newLine = sorter(buffer);
        fputs(newLine, outputFile);
        free(newLine);
    }
    fclose(inputFile);
    fclose(outputFile);
    free(buffer);

    return 0;
}