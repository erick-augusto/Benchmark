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

#endif