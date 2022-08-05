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

char *sorter(char *strSeq, FILE *outputFile)
{
    // memory to receive the sequence after converting to float
    float *sequence = malloc(sizeof(float) * MAX_SEQUENCE_LENGTH);

    // extracts from a .csv line as string, converts to float array
    printf("\nnew sequence: \n");
    int seqSize = parseCSV(strSeq, sequence);
    showSequence(sequence, seqSize);
    
    // sorts float array
    qsort(sequence, seqSize, sizeof(float), compare);
    showSequence(sequence, seqSize);

    // converts the sorted array back to .csv line format as string
    char *newLine = malloc(sizeof(char) * (seqSize + 1));
    newLine = sequenceToString(sequence, seqSize);
    printf("%s", newLine);

    free(sequence);
    return newLine;
}

int parseCSV(char *strSeq, float *sequence)
{
    // memory to store each number as the sequence is traversed
    char *newNumber = malloc(sizeof(char) * SIGNIFICANT_DIGITS);
    int i = 0, currDecPlace = 0, seqSize = 0;
    
    // traversing the string until the end
    while (strSeq[i] != '\0')
    {
        // continue to add characters to the same string if no comma was found
        if (strSeq[i] != ',')
        {
            newNumber[currDecPlace] = strSeq[i];
            // increments decimal place for the new iteration
            currDecPlace++;
        }
        // identifies comma as the end of the current number
        else
        {
            // converts stored string to float and points to next element
            *(sequence++) = atof(newNumber);
            // clear to store next element
            memset(newNumber, 0, SIGNIFICANT_DIGITS);
            currDecPlace = 0;
            // increases size counter
            ++seqSize;
        }

        ++i;
    }
    // one iteration over
    *(sequence++) = atof(newNumber);
    ++seqSize;

    // back to the beginning of the array
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
    // memory to store the sorted array as a string
    // each number in the string has an extra character (comma or \n)
    char *newLine = malloc(sizeof(char) * (SIGNIFICANT_DIGITS + 1) * MAX_SEQUENCE_LENGTH);
    char buffer[SIGNIFICANT_DIGITS];
    for (int i = 0; i < seqSize; i++)
    {
        // convert each float number back to string and concatenate them
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