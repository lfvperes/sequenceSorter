#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SEQUENCE_LENGTH 17
#define TOTAL_DECIMAL_SPACES 5

float parseCSV(char *strSeq, int *totalSeqSize);

void sorter(char *strSeq) {
    
    int *seqSize = 0;
    float seq = parseCSV(strSeq, seqSize);
    printf("%.2f\n", seq);
    // qsort(seq, sizeof(float));

}

float parseCSV(char *strSeq, int *totalSeqSize)
{
    printf("nova sequencia\n");

    char *newNumber = malloc(sizeof(char) * TOTAL_DECIMAL_SPACES);
    float *sequence = malloc(sizeof(float) * MAX_SEQUENCE_LENGTH);
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
    for (int i = 0; i < seqSize; i++)
    {
        printf("%.2f ", sequence[i]);
    }
    
    printf("\n");
    free(newNumber);
    // free(sequence);

    *totalSeqSize = seqSize;

    return *sequence;
}