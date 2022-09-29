#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".././include/sorter.h"
#define PHL true

void parseCSV(char *strSeq, float *sequence);
void showSequence(float *sequence, int seqSize);
int compare(const void *, const void *);
char *sequenceToString(float *sequence, int seqSize);
char *sequenceToString2(float *sequence, int seqSize);
int sizeOfSequence(char *strSeq);

char *sorter(char *strSeq)
{
    printf("\nnew sequence: \n");
    // measuring the size of the sequence
    int seqSize = sizeOfSequence(strSeq);
    
    float *sequence = malloc(sizeof(float) * seqSize);
    // extracts from a .csv line as string, converts to float array
    parseCSV(strSeq, sequence);
    showSequence(sequence, seqSize);
    
    // sorts float array
    qsort(sequence, seqSize, sizeof(float), compare);
    showSequence(sequence, seqSize);

    // conditional compilation, shows min and max values of the sequence
    #ifdef PHL
        printf("min: %.2f max: %.2f\n", sequence[0], sequence[seqSize-1]);
    #endif

    // converts the sorted array back to .csv line format as string
    char *newLine = sequenceToString(sequence, seqSize);
    printf("%s", newLine);

    free(sequence);
    
    return newLine;
}

int sizeOfSequence(char *strSeq)
{
    // measuring the size of the sequence
    int seqSize = 0;
    for (int i = 0; strSeq[i] != '\0'; i++)
    {
        if ((strSeq[i] == ',') || (strSeq[i] == '\n'))
            seqSize++;
    }
    return seqSize;
}

void parseCSV(char *strSeq, float *sequence)
{
    // memory to store each number as the sequence is traversed
    char *newNumber = calloc((SIGNIFICANT_DIGITS + 1), sizeof(char));
    
    int currDecPlace = 0;
    // traversing the string until the end
    while (*strSeq != '\0')
    {
        // continue to add characters to the same string if no comma was found
        if ((*strSeq != ',') && (*strSeq != '\n'))
        {
            newNumber[currDecPlace] = *strSeq;
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
        }
        strSeq++;
    }
    // one iteration over
    // *(sequence++) = atof(newNumber);

    free(newNumber);
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
    // compare function to be called by qsort
    return *(int *)a - *(int *)b;
}

char *sequenceToString(float *sequence, int seqSize)
{
    // each number can have 4 or 5 characters, plus the comma
    // the complete line needs an extra character for the end of the string
    // total of 6 characters per number
    int maxLength = seqSize * (SIGNIFICANT_DIGITS) + 1;
    char *buffer = malloc(sizeof(char) * maxLength);

    // pointing to current and final positions of the buffer
    char *cur = buffer;
    const char *end = buffer + maxLength;

    while (cur < end)
    {
        // appending a new formatted number from the sequence, not exceeding buffer size
        // iterate over the sequence by one step
        // iterate over the buffer by the amount of characters appended
        cur += snprintf(cur, end-cur, "%.2f,", *(sequence++));
    }

    return buffer;
}
