#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


#define COPYMODE 0644
#define BUFSIZE 4096

void oops(char*, char *);
int main(int argc, char *argv[]){

    int n_chars, in_fd, out_fd;
    char buf[BUFSIZE];

    if(argc < 3){
        printf("Usage: arguments should more than 2\n");
        exit(1);
    }

    if((in_fd = open(argv[1], O_RDONLY)) == -1)
        oops("Cannot open", argv[1]);
    
    if((out_fd = creat(argv[2], COPYMODE)) == -1)
        oops("Cannot open", argv[2]);

    while((n_chars = read(in_fd, buf, BUFSIZE)) > 0)
    {
        if(write(out_fd, buf, n_chars) != n_chars)
            fprintf(stderr, "Error:");
    }
    
    close(in_fd);
    close(out_fd);

    return 0;
}

void oops(char *s1, char *s2)
{
    fprintf(stderr, "Error: %s", s1);
    perror(s2);
    exit(1);
}
