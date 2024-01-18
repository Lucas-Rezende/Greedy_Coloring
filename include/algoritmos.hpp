#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include "graph.hpp"

/**
 * \class Algoritmos
 *
 * \brief Essa estrutura contém as estruturas de ordenação e seus métodos auxiliares, além de contar com funções que verificam
 * se o grafo é guloso ou não, por exemplo.
 */
class Algoritmos
{
private:
public:
    /**
     * \brief Construtor padrão.
     */
    Algoritmos();
    /**
     * \brief Destrutor padrão.
     */
    ~Algoritmos();
    /**
     * \brief Método de ordenação baseado em Bubble Sort.
     */
    void BubbleSort(Grafo &mygraph, int n, int *vertices);
    /**
     * \brief Método de ordenação baseado em Selection Sort.
     */
    void SelectionSort(Grafo &mygraph, int n, int *vertices);
    /**
     * \brief Método de ordenação baseado em Insertion Sort.
     */
    void InsertionSort(Grafo &mygraph, int n, int *vertices);
    /**
     * \brief Método de ordenação baseado em Quick Sort.
     */
    void QuickSort(Grafo &mygraph, int n, int *vertices);
    /**
     * \brief Método de ordenação baseado em Merge Sort.
     */
    void MergeSort(Grafo &mygraph, int *vertices, int left, int right);
    /**
     * \brief Método de ordenação baseado em Heap Sort.
     */
    void HeapSort(Grafo &mygraph, int n, int *vertices);
    /**
     * \brief Método de ordenação feito por mim.
     */
    void MySort(Grafo &mygraph, int n, int *vertices);

    /**
     * \brief Afirma se é gulosa ou não.
     */
    bool isGulosa(Grafo &mygraph, int n, int *vertices);
    /**
     * \brief Imprime o output.
     */
    void printOutput(Grafo &mygraph, int n, bool gulosa, int *vertices);
    /**
     * \brief Método que divide o vetor em duas partes para o Quick Sort.
     */
    void Particao(int Esq, int Dir, int *i, int *j, Grafo &mygraph, int *vertices);
    /**
     * \brief Método que ordena as duas partes do vetor após a partição no Quick Sort.
     */
    void Ordena(int Esq, int Dir, Grafo &mygraph, int *vertices);
    /**
     * \brief Método que combina as duas metades ordenadas no Merge Sort.
     */
    void Merge(Grafo &mygraph, int *vertices, int left, int mid, int right);
    /**
     * \brief Método que reorganiza o heap no Heap Sort.
     */
    void Refaz(int Esq, int Dir, Grafo &mygraph, int *vertices);
    /**
     * \brief Método que constrói o heap inicial no Heap Sort.
     */
    void Constroi(Grafo &mygraph, int n, int *vertices);
};

#endif