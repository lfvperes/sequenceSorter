#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SEQUENCE_LENGTH 17
#define TOTAL_DECIMAL_SPACES 5

void parseCSV(char *strSeq, int *totalSeqSize, float *sequence);
void showSequence(float *sequence, int seqSize);

void sorter(char *strSeq) {
    
    int *seqSize = 0;
    float *sequence = malloc(sizeof(float) * MAX_SEQUENCE_LENGTH);

    printf("new sequence: \n");
    parseCSV(strSeq, seqSize, sequence);
    
    // qsort(sequence, sizeof(float), sizeof(float), compare);
    // showSequence(sequence, *seqSize);

    free(sequence);
}

void parseCSV(char *strSeq, int *totalSeqSize, float *sequence)
{

    char *newNumber = malloc(sizeof(char) * TOTAL_DECIMAL_SPACES);
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
            memset(newNumber, 0, TOTAL_DECIMAL_SPACES);
            currDecSpace = 0;
            ++seqSize;
        }

        ++i;
    }
    *(sequence++) = atof(newNumber);
    ++seqSize;


    sequence -= seqSize;

    showSequence(sequence, seqSize);
    
    totalSeqSize = &seqSize;

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