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
    void Ordenacao<T>::heapify(T *vet, int pai, int heapsize) {
        int fl, fr, imaior;
        fl = (pai << 1) + 1;
        fr = fl + 1;
        while (true) {
            if ((fl < heapsize) && (vet[fl] > vet[pai])) imaior = fl;
            else imaior = pai;
            if ((fr < heapsize) && (vet[fr] > vet[imaior])) imaior = fr;
            if (imaior != pai){
                T aux = vet[pai];
                vet[pai] = vet[imaior];
                vet[imaior] = aux;
                pai = imaior;
                fl = (pai << 1) + 1;
                fr = fl + 1;
            }
            else break;
        }
    }

    template <typename T>
    void Ordenacao<T>::heapsort(T *vet, int n) {
        int i;
        for (i=(n>>1)-1; i>=0; i--) heapify(vet, i, n);
        for (i=n-1; i > 0; i--) {
            T aux = vet[0];
            vet[0] = vet[i];
            vet[i] = aux;
            heapify(vet, 0, i);
        }
    }
	
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
		vet[i] = pivo;
        quicks_central(vet, l, i-1);
        quicks_central(vet, i+1, r);
	}
	
	template <typename T>
    void Ordenacao<T>::mergesort(T *vet, int n) {
        T *aux = new T[n];
        m_sort(vet, aux , 0, n-1);
        delete aux;
    }

#endif