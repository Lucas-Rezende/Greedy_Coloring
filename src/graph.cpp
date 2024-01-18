#include "graph.hpp"
#include <climits>

Grafo::Grafo() {}

// Construtor da classe Grafo
Grafo::Grafo(int n) : numVertices(n), cores(new int[n])
{
    // Inicializa o grafo e as cores
    for (int i = 0; i < numVertices; i++)
    {
        vertices.insereFinal(new ListaEncadeada());
        cores[i] = -1; // Inicializa todas as cores como -1 (sem cor)
    }
}

// Destrutor da classe Grafo
Grafo::~Grafo()
{
    // Libera a memória alocada para cores
    delete[] cores;
}

void Grafo::InsereVertice()
{
    ListaEncadeada *novaLista = new ListaEncadeada();
    vertices.insereFinal(novaLista);
}

void Grafo::InsereAresta(int v, int w)
{
    ListaEncadeada *listaV = vertices.getLista(v);
    ListaEncadeada *listaW = vertices.getLista(w);

    if (listaV != nullptr && listaW != nullptr)
    {
        listaV->InsereFinal(w);
    }
}

int Grafo::QuantidadeVertices()
{
    return vertices.getTamanho();
}

int Grafo::QuantidadeArestas()
{
    int totalArestas = 0;

    for (int i = 0; i < vertices.getTamanho(); i++)
    {
        totalArestas += vertices.getLista(i)->Tamanho();
    }

    return totalArestas / 2;
}

void Grafo::ImprimeVizinhos(int v)
{
    ListaEncadeada *listaV = vertices.getLista(v);

    if (listaV != nullptr)
    {
        listaV->Imprime();
    }
}

// Método para definir a cor de um vértice
void Grafo::SetCor(int vertice, int cor)
{
    if (vertice >= 0 && vertice < numVertices)
    {
        cores[vertice] = cor;
    }
}

// Método para obter a cor de um vértice
int Grafo::GetCor(int vertice)
{
    if (vertice >= 0 && vertice < numVertices)
    {
        return cores[vertice];
    }
    return -1; // Retorna -1 se o vértice estiver fora dos limites
}

void Grafo::ImprimeVerticesECores()
{
    for (int i = 0; i < numVertices; i++)
    {
        std::cout << "Vertice: " << i << ", Cor: " << GetCor(i) << std::endl;
    }
}

ListaEncadeada* Grafo::getAdjacencias(int v)
{
    return vertices.getLista(v);
}