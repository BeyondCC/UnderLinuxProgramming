#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

void oops(char*, char*);

void do_ls(char *);

int main(int argc, char *argv[]){
    
    if(argc == 1){
        do_ls(".");
    }
    return 0;
}

void do_ls(char *dir)
{
    DIR * pDir;
    struct dirent * pDirent;

    if((pDir = opendir(dir))  == NULL)
        oops("Read error:", dir);

    while((pDirent = readdir(pDir)) != NULL)
        printf("%s\n", pDirent->d_name);

    closedir(pDir);
}


void oops(char *s1, char *s2)
{
    fprintf(stderr, "Error: %s", s1);
    perror(s2);
    exit(1);
}

