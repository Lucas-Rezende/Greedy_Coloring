#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "ListaAdjacencia.hpp"

/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Nenhuma outra alteração neste arquivo é permitida
 */

class Grafo
{
public:
    Grafo();
    Grafo(int n);
    ~Grafo();

    void InsereVertice();
    void InsereAresta(int v, int w);

    int QuantidadeVertices();
    int QuantidadeArestas();

    void ImprimeVizinhos(int v);
    void SetCor(int vertice, int cor);
    int GetCor(int vertice);
    void ImprimeVerticesECores();

    ListaEncadeada* getAdjacencias(int v);

private:
    ListaAdjacencia vertices;
    int* cores;
    int numVertices;
};

#endif