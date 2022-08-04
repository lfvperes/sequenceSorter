#include <stdio.h>
#include <stdlib.h>
#include "./include/sorter.h"
#define BUFFER_LENGTH 104

int main()
{
    char *inputFilename = "inputFloatSequences.csv";
    char *outputFilename = "outputFloatSequences.csv";
    
    /* char buffer[BUFFER_LENGTH]; */
    char *buffer = malloc(sizeof(char) * BUFFER_LENGTH);

    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");

    /* char *seq = buffer; */

    while (fgets(buffer, BUFFER_LENGTH, inputFile))
    {
        sorter(buffer, outputFile);
        // printf("%s\n", buffer);
    }
    fclose(inputFile);
    fclose(outputFile);
    free(buffer);
    return 0;
}
