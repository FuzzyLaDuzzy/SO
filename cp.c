#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <errno.h>

#define MAX_BUF 1024*1024

int main (int argc, char * argv[]){

    printf("argv[0]: %s\n",argv[0]);
    printf("argv[1]: %s\n",argv[1]);
    printf("argv[2]: %s\n",argv[2]);


    char buffer [MAX_BUF];


    int fd_origem,fd_destino;

    if (fd_origem = open (argv[1], O_RDONLY)== -1)
    {
        printf("Msg: %s, Nr: %d\n", strerror(errno),errno);
        perror("erro no open origem");
        return -1;
    }

    if ((fd_destino = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0640)))
    {
        printf("erro no open origem");
        return -1;
    }

    int bytes_read;

    while((bytes_read = read(fd_origem, buffer, MAX_BUF)) == 0){ // temos de adicionar o MAX BUF para o buffer nao ler menos do que este / evite escrever lixo a seguir...
        write(fd_destino, buffer, bytes_read);
    }

    //free(buffer);

    close(fd_origem);
    close(fd_destino);

    return 0;

}
