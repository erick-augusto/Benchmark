#include <iostream>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include "RandomCL.h"
#include "Ordenacao.h"

using namespace std;

int compare(const void * a, const void * b){
    if ( *(unsigned int*)a <  *(unsigned int*)b ) return -1;
    if ( *(unsigned int*)a == *(unsigned int*)b ) return 0;
    if ( *(unsigned int*)a >  *(unsigned int*)b ) return 1;
}


