#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include "graph.hpp"

class Algoritmos
{
private:

public:
    Algoritmos();
    ~Algoritmos();
    void BubbleSort(Grafo& mygraph, int n, int* vertices);
    void SelectionSort(Grafo& mygraph, int n, int* vertices);
    void InsertionSort(Grafo& mygraph, int n, int* vertices);
    void QuickSort(Grafo& mygraph, int n, int* vertices);
    void MergeSort(Grafo &mygraph, int* vertices, int left, int right);
    void HeapSort(Grafo &mygraph, int n, int* vertices);
    void MySort(Grafo &mygraph, int n, int* vertices);
    void AlgoritmoGuloso(Grafo *mygraph);

    bool isGulosa(Grafo &mygraph, int n, int* vertices);
    void printOutput(Grafo &mygraph, int n, bool gulosa, int* vertices);
    void Particao(int Esq, int Dir, int *i, int *j, Grafo &mygraph, int* vertices);
    void Ordena(int Esq, int Dir, Grafo &mygraph, int *vertices);
    void Merge(Grafo &mygraph, int* vertices, int left, int mid, int right);
    void Refaz(int Esq, int Dir, Grafo &mygraph, int* vertices);
    void Constroi(Grafo &mygraph, int n, int* vertices);
};

#endif