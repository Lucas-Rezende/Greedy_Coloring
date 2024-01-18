#ifndef LISTA_ADJACENCIA_HPP
#define LISTA_ADJACENCIA_HPP

#include "ListaEncadeada.hpp"

class ListaAdjacencia
{
public:
    ListaAdjacencia();
    ~ListaAdjacencia();

    void insereFinal(ListaEncadeada *mylista);
    ListaEncadeada* removeFinal();
    void imprime();
    int getTamanho();
    ListaEncadeada* getLista(int index);

    void insereAresta();
private:
    ListaEncadeada *vertices;
    int numVertices;
    int numArestas;
    int auxsize;
};

#endif