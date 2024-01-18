#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "ListaAdjacencia.hpp"

class Grafo
{
public:
    /**
     * \brief Construtor padrão.
     */
    Grafo();
    /**
     * \brief Construtor que inicializa o grafo com n vértices.
     */
    Grafo(int n);
    /**
     * \brief Destrutor padrão.
     */
    ~Grafo();

    /**
     * \brief Método para inserir um vértice no grafo.
     */
    void InsereVertice();
    /**
     * \brief Método para inserir uma aresta entre os vértices v e w.
     */
    void InsereAresta(int v, int w);

    /**
     * \brief Retorna a quantidade de vértices no grafo.
     */
    int QuantidadeVertices();
    /**
     * \brief Retorna a quantidade de arestas no grafo.
     */
    int QuantidadeArestas();

    /**
     * \brief Imprime os vizinhos do vértice v.
     */
    void ImprimeVizinhos(int v);
    /**
     * \brief Define a cor do vértice.
     */
    void SetCor(int vertice, int cor);
    /**
     * \brief Retorna a cor do vértice.
     */
    int GetCor(int vertice);
    /**
     * \brief Imprime os vértices e suas cores.
     */
    void ImprimeVerticesECores();

    /**
     * \brief Retorna a lista de adjacências do vértice v.
     */
    ListaEncadeada* getAdjacencias(int v);

private:
    int numVertices; // Número de vértices no grafo
    int* cores; // Array de cores dos vértices
    ListaAdjacencia vertices; // Lista de adjacências
};

#endif