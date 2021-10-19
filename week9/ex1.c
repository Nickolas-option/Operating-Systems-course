#include <stdio.h>
#include <stdlib.h>

int main() {

    int pageNumber;
    printf("Enter the number of page frames:\n");
    scanf("%d", &pageNumber);

    int memAcc;
    printf("Enter the number of memory accesses:\n");
    scanf("%d", &memAcc);

    FILE *inputFile = fopen("input.txt", "r");

    long count[pageNumber];

    int table[pageNumber];

    // initialization
    for (int i = 0; i < pageNumber; i++) {
        table[i] = -1;
        count[i] = 0;
    }

    int missNumber = 0;
    int hitsNumber = 0;

    for (int i = 0; i < memAcc; i++) {

        int reference = 0;
        fscanf(inputFile, "%d", &reference);
        int found = 0;
        int id = -1;

        for (int l = 0; l < pageNumber; l++) {
            if (table[l] == reference) {
                // in the case of a hit
                hitsNumber++;
                found = 1;
                id = l;
                break;
            }
        }

        if (!found) {
            // in the case of a miss
            missNumber++;
            for (int h = 0; h < pageNumber; h++) {
                if (table[h] == -1) {
                    id = h;
                    break;
                }
            }
            // if there is no space left
            if (id == -1) {
                int min = (int) (count[0]);
                id = 0;
                for (int g = 1; g < pageNumber; g++) {
                    if (count[g] < min) {
                        min = (int) (count[g]);
                        id = g;
                        // we find id of the substitution
                    }
                }
            }

            table[id] = reference;
        }

        for (int k = 0; k < pageNumber; k++) {
            count[k] = count[k] >> 1;
        }
        count[id] = count[id] | (1 << 7);
    }

    printf("Hits/Miss ratio: %f", (float) hitsNumber / (float) missNumber);

    fclose(inputFile);
    return 0;
}
