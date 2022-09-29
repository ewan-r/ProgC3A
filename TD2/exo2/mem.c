// mem.c programme principal
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"
int main(int argc, char *argv[]){
   if (argc != 2){
      fprintf(stderr, "usage: mem <value>\n");
      exit(1);
   }
   int *p;
   p = malloc(sizeof(int));
   assert(p != NULL);
   printf("(%d) addr stored in p: %p\n", (int)getpid(), p);
   *p = atoi(argv[1]); // assign value to object pointed to by p
   while (1) {
      Spin(1);
      *p = *p + 1;
      printf("(%d) value of *p: %d\n", getpid(), *p);
   }
   return 0;
}