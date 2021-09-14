#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
//Now we use arguments
int main(int argc, char * argv[]) {
  char command[128];
	char *argv1[] = { argv[1], "New", "Shell", NULL };
	char *environment[] = { NULL };
	execve(argv[1], argv1, environment);
	perror("execve");
  //Using execve
  while (true)
    scanf("%s", input);
  //Stopping the shell when done with arguments and commands
    if (strcmp(input, "^Z") == 0) { 
    return 0;
  }
      system(input); //execute the command
        }
}
