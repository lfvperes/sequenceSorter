#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SEQUENCE_LENGTH 17
#define SIGNIFICANT_DIGITS 5
#define DECIMAL_PLACES 2

int parseCSV(char *strSeq, float *sequence);
void showSequence(float *sequence, int seqSize);
int compare(const void *, const void *);
char *sequenceToString(float *sequence, int seqSize);

void sorter(char *strSeq, FILE *outputFile) {
    
    float *sequence = malloc(sizeof(float) * MAX_SEQUENCE_LENGTH);

    printf("\nnew sequence: \n");
    int seqSize = parseCSV(strSeq, sequence);
    showSequence(sequence, seqSize);
    
    qsort(sequence, seqSize, sizeof(float), compare);
    showSequence(sequence, seqSize);

    char *newLine = malloc(sizeof(char) * (seqSize + 1));
    newLine = sequenceToString(sequence, seqSize);
    printf("%s", newLine);
    fputs(newLine, outputFile);    

    free(sequence);
}

int parseCSV(char *strSeq, float *sequence)
{
    char *newNumber = malloc(sizeof(char) * SIGNIFICANT_DIGITS);
    int i = 0, currDecSpace = 0, seqSize = 0;
    while (strSeq[i] != '\0')
    {
        if (strSeq[i] != ',')
        {
            newNumber[currDecSpace] = strSeq[i];
            currDecSpace++;
        }
        else
        {
            *(sequence++) = atof(newNumber);
            memset(newNumber, 0, SIGNIFICANT_DIGITS);
            currDecSpace = 0;
            ++seqSize;
        }

        ++i;
    }
    *(sequence++) = atof(newNumber);
    ++seqSize;

    sequence -= seqSize;

    free(newNumber);
    return seqSize;
}

void showSequence(float *sequence, int seqSize)
{
    for (int i = 0; i < seqSize; i++)
    {
        printf("%.2f ", sequence[i]);
    }
    printf("\n");
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

char *sequenceToString(float *sequence, int seqSize)
{
    char *newLine = malloc(sizeof(char) * (SIGNIFICANT_DIGITS + 1) * MAX_SEQUENCE_LENGTH);
    char buffer[SIGNIFICANT_DIGITS];
    for (int i = 0; i < seqSize; i++)
    {
        gcvt(sequence[i], SIGNIFICANT_DIGITS, buffer);
        strcat(newLine, buffer);
        if (i < seqSize - 1)
        {
            strcat(newLine, ",");
        }
        else
        {
            strcat(newLine, "\n");
        }
    }

    return newLine;
}