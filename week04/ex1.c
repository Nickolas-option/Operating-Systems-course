int main()  {
        int n = 10;
        int  pid = fork();
        if (pid == 0){
                for (int i = 0; i < n; ++i){
                        printf("This is the child process. My id is %d - %d.\n", pid, i);
                }
        }
        if (pid > 0) {
                for (int i = 0; i < n; ++i){
         printf("This is the parent process. My pid is %d - %d.\n", pid, i);
                }
        }
}
