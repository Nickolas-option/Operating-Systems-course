#include <stdlib.h>
#include "stdio.h"
void print(int n, char x) {
        for ( int i = 0; i < n; i++) {
                printf("%c", x);
        }
}
int main(int argc, char* argv[]){

        int n = atoi(argv[1]);
        int numberOfStars = 1;
        int numberOfSpaces = 2*n-numberOfStars;
        for (int i = 0; i<n; i++) {
                int numberOfSpaces = 2*n-numberOfStars;
                print(numberOfSpaces/2, ' ');
                print(numberOfStars,  '*');
                print(numberOfSpaces/2, ' ');
                printf("\n");
                numberOfStars = numberOfStars + 2;
        }
}
