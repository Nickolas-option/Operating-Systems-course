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
        sleep(1);
    }
}
