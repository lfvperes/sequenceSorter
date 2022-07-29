#include <stdio.h>
#include <stdlib.h>
#include "./include/sorter.h"
#define BUFFER_LENGTH 104

int main()
{
    char *filename = "inputFloatSequences.csv";
    
    /* char buffer[BUFFER_LENGTH]; */
    char *buffer = malloc(sizeof(char) * BUFFER_LENGTH);

    FILE *fp = fopen(filename, "r");

    /* char *seq = buffer; */

    while (fgets(buffer, BUFFER_LENGTH, fp))
    {
        /* sorter(buffer); */
        sorter(buffer);
        /* printf("%s\n", buffer); */
        /* printf("%d", ch); */
    }
    fclose(fp);
    return 0;
}
