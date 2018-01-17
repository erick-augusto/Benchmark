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

int main()
{
    int i, j, k, n, t1, t2;
    unsigned long int *vet;
    int tamanho[9] = {500, 1000, 2500, 5000, 7500, 10000, 15000, 20000, 25000};
    double tempo[6];
    double media[9];

	//QSort
    cout << "   ***Testes do QSort***" << endl;
    for(i=0;i<9;i++){
        n = tamanho[i];
		for(j=0;j<6;j++){
            RandomCL<unsigned long int> gerador(i);
            vet = new unsigned long int [n];
            for(k=0;k<n;k++){
                vet[k] = gerador.nextr();
            }
		}
	}
}