#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <unistd.h>

int main() {
    int size = 100 * 1024 * 1024;
    char *p;
    for (int i = 0; i < 10; ++i) {
        p = malloc(size * sizeof(char));
        memset(p, 0, size);
      
        // get current usage of the process
        getrusage(RUSAGE_SELF, &usage);

        printf("The memory usage:\t%ld\n", usg.ru_maxrss);

        sleep(1);
      
    }
}
