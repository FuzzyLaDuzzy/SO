#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

// ler linhas 
#define MAX_BUF 1024*1024

int main (int fd, char *line, size_t size){
   
   int bytes_read;

   
   char buffer[MAX_BUF];
   printf("%lu", sizeof(buffer));

   int i = 0;
   int flag = 1;

   while(flag){
   char c;
   read(fd, &c, 1);
   if(c == '\n')
      flag = 0;
      buffer[i] = c;
      i++;
     }


}