#ifndef LISTA_ADJACENCIA_HPP
#define LISTA_ADJACENCIA_HPP

#include "ListaEncadeada.hpp"

class ListaAdjacencia
{
public:
    /**
     * \brief Construtor padrão.
     */
    ListaAdjacencia();
    /**
     * \brief Destrutor padrão.
     */
    ~ListaAdjacencia();

    /**
     * \brief Insere uma lista no final da lista de adjacências.
     */
    void insereFinal(ListaEncadeada *mylista);
    /**
     * \brief Remove a última lista da lista de adjacências.
     */
    ListaEncadeada* removeFinal();
    /**
     * \brief Imprime a lista de adjacências.
     */
    void imprime();
    /**
     * \brief Retorna o tamanho da lista de adjacências.
     */
    int getTamanho();
    /**
     * \brief Retorna a lista na posição index da lista de adjacências.
     */
    ListaEncadeada* getLista(int index);

    /**
     * \brief Insere uma aresta na lista de adjacências.
     */
    void insereAresta();
private:
    ListaEncadeada *vertices; // Lista de vértices
    int numVertices; // Número de vértices
    int numArestas; // Número de arestas
    int auxsize; // Tamanho auxiliar
};

#endif