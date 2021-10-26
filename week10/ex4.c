#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>

typedef struct dirent dirent;

int main() {
    dirent *pointersDir[20];
    DIR* pDir;
    // trying to open "tmp" directory
    pDir = opendir("tmp/");
    if (pDir == NULL) {
        printf("cannot open tmp/\n");
        return EXIT_SUCCESS;
    }
    int pointersDirSize = 0;
    // reading the files till the last one
    while(1) {
        pointersDir[pointersDirSize] = readdir(pDir);
        if (pointersDir[pointersDirSize] == NULL)
            break;
        pointersDirSize++;
    }
    closedir(pDir);
    //Printing the hard links (and making them)
    printf("File--Hard Links\n");
    // Searching for the same links
    for (int i = 0; i < pointersDirSize; ++i) {
        int quantityOfLinks = 0;
        for (int j = 0; j < pointersDirSize; ++j) {
            if (pointersDir[i]->d_ino == pointersDir[j]->d_ino) {
                quantityOfLinks++;
            }
        }
        if (quantityOfLinks >= 2) {
            printf("%s--", pointersDir[i]->d_name);
            for (int k = 0; k < pointersDirSize; ++k) {
                if (pointersDir[i]->d_ino == pointersDir[k]->d_ino) {
                    printf("%s ", pointersDir[k]->d_name);
                }
            }
            printf("\n");
        }
    }
    return EXIT_SUCCESS;
}
