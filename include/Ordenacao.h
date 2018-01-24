#ifndef ORDENACAO_H
#define ORDENACAO_H

namespace ED {
    template <typename T>
    class Ordenacao {
        public:
            static void heapsort(T *vet, int n);
            static void quicks_central(T *vet, int l, int r);
            static void mergesort(T *vet, int n);
            static void shellSort_shell(T *vet, int n);
            static void shellSort_knuth(T *vet, int n);
            static void shellSort_pardons(T *vet, int n);
        private:
            static void heapify(T *vet, int pai, int heapsize);
            static void m_sort(T *vet, T *aux, int esq, int dir);
            static void merge(T *vet, T *aux, int esq, int meio, int dir);
    };
	
	template <typename T>
    void Ordenacao<T>::quicks_central(T *vet, int l, int r) {
		if (r <= l) return;
		int i, j;
        i = (l+r)/2;
        T pivo = vet[i]; vet[i] = vet[l]; vet[l] = pivo;
        i = l; j = r;
		while (true) {
            while ((j > i) && (vet[j] > pivo)) j--;
            if (i==j) break;
            vet[i] = vet[j]; i++;
            while ((i < j) && (vet[i] < pivo)) i++;
            if (i==j) break;
            vet[j] = vet[i]; j--;
        }
	}

#endif