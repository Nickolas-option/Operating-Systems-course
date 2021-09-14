#include <stdio.h>
#include <stdlib.h>

int main(){
    char command[1001];
    while (1) {
        scanf("%s", command);
        system(command);
    }
  return 0;
}
