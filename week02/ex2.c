#include "limits.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
int main() {
        char str1[10];
        int stringStarted = 0;
        fgets(str1, 10, stdin);
        for (int i = strlen(str1); i>=0; i--) {
                if (str1[i] == '\0') {stringStarted = 1; continue;}
                if (stringStarted == 1) {
                        printf("%c", str1[i]);
                }
        }
}
