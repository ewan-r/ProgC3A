#include "generator.h"
#define INITIAL_VALUE 0

int generate(void){
   //val est v.l de classe statique
   static int val = INITIAL_VALUE;
   return val++;
}