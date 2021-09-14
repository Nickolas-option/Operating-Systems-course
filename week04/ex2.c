#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    for (int i = 0; i < 5; ++i)
        fork();
    sleep(5);
    return 0;
}
// Number of Processes is 2 ^ (number of forks)

// Example
// 5 forks - 32 pr
