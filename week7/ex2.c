#include <malloc.h>
#include "stdio.h"

int main() {
    printf("Please, input the number of elements in the array:\n");
    int N;
    scanf("%d", &N);
    int* array = malloc(sizeof(int)*N);
    for (int i = 0; i < N; ++i) {
        array[i] = i;
    }
    for (int i = 0; i < N; ++i) {
        printf("ptr[%d] == %d\n", i, array[i]);
    }
    free(array);
}
