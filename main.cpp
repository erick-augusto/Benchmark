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
            t1 = clock();
            qsort(vet, n, sizeof(unsigned int), compare);
            t2 = clock();
            tempo[j] = (double) (t2-t1)/CLOCKS_PER_SEC*1000;
            //cout << "Saida " << i+1 << "." << j+1 << ": " << tempo[j] << "ms" << endl;
            delete vet;
        }
        media[i] = (tempo[0]+tempo[1]+tempo[2]+tempo[3]+tempo[4]+tempo[5])/6;
        cout << "Media do QSort no caso " << i+1 << ": " << media[i] << "ms\n" << endl;
    }

    //Sort
    cout << "   ***Testes do Sort***" << endl;
    for(i=0;i<9;i++){
        n = tamanho[i];
        for(j=0;j<6;j++){
            RandomCL<unsigned long int> gerador(i);
            vet = new unsigned long int [n];
            for(k=0;k<n;k++){
                vet[k] = gerador.nextr();
            }
            t1 = clock();
            sort(vet, vet+n);
            t2 = clock();
            tempo[j] = (double) (t2-t1)/CLOCKS_PER_SEC*1000;
            //cout << "Saida " << i+1 << "." << j+1 << ": " << tempo[j] << "ms" << endl;
            delete vet;
        }
        media[i] = (tempo[0]+tempo[1]+tempo[2]+tempo[3]+tempo[4]+tempo[5])/6;
        cout << "Media do Sort no caso " << i+1 << ": " << media[i] << "ms\n" << endl;
    }
	
	//Quick CentralSort
    cout << "   ***Testes do Quick Central***" << endl;
    for(i=0;i<9;i++){
        n = tamanho[i];
        for(j=0;j<6;j++){
            RandomCL<unsigned long int> gerador(i);
            vet = new unsigned long int [n];
            for(k=0;k<n;k++){
                vet[k] = gerador.nextr();
            }
            t1 = clock();
            ED::Ordenacao<unsigned long int>::quicks_central(vet, 0, n-1);
            t2 = clock();
            tempo[j] = (double) (t2-t1)/CLOCKS_PER_SEC*1000;
            //cout << "Saida " << i+1 << "." << j+1 << ": " << tempo[j] << "ms" << endl;
            delete vet;
        }
        media[i] = (tempo[0]+tempo[1]+tempo[2]+tempo[3]+tempo[4]+tempo[5])/6;
        cout << "Media do Quick Central no caso " << i+1 << ": " << media[i] << "ms\n" << endl;
    }
	
	//HeapSort
    cout << "   ***Testes do HeapSort***" << endl;
    for(i=0;i<9;i++){
        n = tamanho[i];
		for(j=0;j<6;j++){
            RandomCL<unsigned long int> gerador(i);
            vet = new unsigned long int [n];
            for(k=0;k<n;k++){
                vet[k] = gerador.nextr();
            }
			t1 = clock();
            ED::Ordenacao<unsigned long int>::heapsort(vet, n);
            t2 = clock();
            tempo[j] = (double) (t2-t1)/CLOCKS_PER_SEC*1000;
            cout << "Saida " << i+1 << "." << j+1 << ": " << tempo[j] << "ms" << endl;
            delete vet;
		}
	}
}