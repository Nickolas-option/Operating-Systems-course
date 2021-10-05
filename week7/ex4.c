#include <stdio.h>
#include <stdlib.h>

int main() {

    char **s = (char**)(malloc(sizeof(char*)))       
    //allocated memory for s
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %p\n",s);      
    //changed %s to %p
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return(0);
    
}
