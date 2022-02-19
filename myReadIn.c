#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

// ler linhas 
#define MAX_BUF 1024*1024

/*
================================================
Read line a ler um caracter de cada vez
================================================
*/
ssize_t readlna(int fd, char *line, size_t size)
{
    char buf[1]; 
    int bytes_reads = 0;
    int indice = 0;
    for(bytes_reads = read(fd,buf,1);*buf != '\n' && bytes_reads > 0;bytes_reads = read(fd,buf,1),indice++)
        line[indice] = *buf;
    return (ssize_t) indice;
}

//ou 

ssize_t readlnb(int fd, char* line, size_t size){
    char buffer[1];
    int bytes_read = 0;
    int i = 0;
    while(*buffer != '\n'){
        bytes_read=read(fd,buffer,1);
        if(bytes_read<=0)break;
        line[i] = *buffer;
        i++;
    }
    return i;
}


ssize_t readln2(int fd, char *line, size_t size)
{
    int bytes_reads = read(fd,line,size);
    if(bytes_reads == 0) return 0;
    int i;
    for(i = 0 ; i < bytes_reads; i++)
        if(line[i] == '\n')
            break;
    lseek(fd,i-bytes_reads+1,SEEK_CUR);
    return (ssize_t) i;
}


//percebe o que é o lseek e para que funciona o i-bytes_read+1 nesta conta


}
