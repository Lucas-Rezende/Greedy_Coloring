#include <iostream>
#include <string>

#include "algoritmos.hpp"
#include "graph.hpp"

const int MAX_VERTICES = 10000000;

int main()
{
    std::string metodo;
    int numVertices;
    int cores[MAX_VERTICES];

    std::cin >> metodo;
    std::cin >> numVertices;

    if (metodo != "b" && metodo != "s" && metodo != "i" && metodo != "q" && metodo != "m" && metodo != "p" && metodo != "y")
    {
        std::cout << "Uso: \"escolha do método de ordenação\" \"quantidade de vértices\"" << std::endl;
        return 1;
    }

    Grafo grafo(numVertices);
    Algoritmos algs;

    int vertices[numVertices];
    for (int i = 0; i < numVertices; i++)
        vertices[i] = i;

    for (int v = 0; v < numVertices; v++)
    {
        int numVizinhos;
        std::cin >> numVizinhos;
        for (int i = 0; i < numVizinhos; i++)
        {
            int w;
            std::cin >> w;
            grafo.InsereAresta(v, w);
        }
    }

    for (int i = 0; i < numVertices; i++)
    {
        std::cin >> cores[i];
    }

    for (int i = 0; i < numVertices; i++)
    {
        grafo.SetCor(i, cores[i]);
    }

        // bubble sort
        if (metodo == "b")
        {
            algs.BubbleSort(grafo, numVertices, vertices);
            bool gulosa = algs.isGulosa(grafo, numVertices, vertices);
            algs.printOutput(grafo, numVertices, gulosa, vertices);
        }

        // selection sort
        if (metodo == "s")
        {
            algs.SelectionSort(grafo, numVertices, vertices);
            bool gulosa = algs.isGulosa(grafo, numVertices, vertices);
            algs.printOutput(grafo, numVertices, gulosa, vertices);
        }

        // insertion sort
        if (metodo == "i")
        {
            algs.InsertionSort(grafo, numVertices, vertices);
            bool gulosa = algs.isGulosa(grafo, numVertices, vertices);
            algs.printOutput(grafo, numVertices, gulosa, vertices);
        }

        // quicksort
        if (metodo == "q")
        {
            algs.QuickSort(grafo, numVertices, vertices);
            bool gulosa = algs.isGulosa(grafo, numVertices, vertices);
            algs.printOutput(grafo, numVertices, gulosa, vertices);
        }

        // mergesort
        if (metodo == "m")
        {
            algs.MergeSort(grafo, vertices, 0, numVertices - 1);
            bool gulosa = algs.isGulosa(grafo, numVertices, vertices);
            algs.printOutput(grafo, numVertices, gulosa, vertices);
        }

        // heapsort
        if (metodo == "p")
        {
            algs.HeapSort(grafo, numVertices, vertices);
            bool gulosa = algs.isGulosa(grafo, numVertices, vertices);
            algs.printOutput(grafo, numVertices, gulosa, vertices);
        }

        // meu método de ordenação
        if (metodo == "y")
        {
            algs.MySort(grafo, numVertices, vertices);
            bool gulosa = algs.isGulosa(grafo, numVertices, vertices);
            algs.printOutput(grafo, numVertices, gulosa, vertices);
        }
    return 0;
}