#include <stdio.h>
#include <stdlib.h>

void *reallocate_memory(int *pointer, int size)
{
    if (pointer == NULL)
    {
        return malloc(size);
    }
    else if (size == 0)
    {
        free(pointer);
        return NULL;
    }
    else
    {   // Reallocation
        int *Array = malloc(size);

        //Copying
        if (Array)
        {
            for (int i = 0; i < size; ++i)
            {
                *(Array + i) = *(pointer + i);
            }
        }
        free(pointer);
        return Array;
    }
}

int main()
{   //Test the implementation in main function:
    int *a = malloc(sizeof(int) * 3);
    printf("\nInitialization\n");
    for (int i = 0; i < 3; ++i)
    {
        *(a + i) = i * i;
        printf("%d ", *(a + i));
    }
    a = reallocate_memory(a, sizeof(int) * 100);
    printf("\nTesting\n");
    for (int i = 0; i < 100; ++i)
    {
        printf("%d ", *(a + i));
    }
    return 0;
}