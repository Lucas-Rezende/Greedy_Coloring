#include <iostream>
#include <string>

#include "algoritmos.hpp"
#include "graph.hpp"

const int MAX_VERTICES = 1000000;

int main()
{
    std::string metodo;
    int numVertices;
    int rotulos[MAX_VERTICES];
    int cores[MAX_VERTICES];

    std::cin >> metodo;
    std::cin >> numVertices;

    Grafo grafo(numVertices);
    Algoritmos algs;

    // Inicializa o array vertices
    int vertices[numVertices];
    for (int i = 0; i < numVertices; i++)
        vertices[i] = i;

    // Lê as arestas
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

    // Armazena as cores
    for (int i = 0; i < numVertices; i++)
    {
        std::cin >> cores[i];
    }

    // Define as cores dos vértices
    for (int i = 0; i < numVertices; i++)
    {
        grafo.SetCor(i, cores[i]);
    }

    if (metodo != "b" && metodo != "s" && metodo != "i" && metodo != "q" && metodo != "m" && metodo != "p" && metodo != "y")
    {
        std::cout << "Uso: \"escolha do método de ordenação\" \"quantidade de vértices\"" << std::endl;
        return 1;
    }

    else
    {
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
    }
    return 0;
}