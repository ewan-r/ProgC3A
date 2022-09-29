#include "suite.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
   int n = argc > 1 ? atoi(argv[1]) : 0;
   char *ns;
   printf("la suite de %d symbole(s): ", n);
   while (n--){
      suite_e_suite(n);
   }
   free(ns);
   printf("\n");
   return EXIT_SUCCESS;
}