#include "ListaAdjacencia.hpp"

ListaAdjacencia::ListaAdjacencia()
{
    vertices = nullptr;
    numVertices = 0;
    numArestas = 0;
    auxsize = 0;
}

ListaAdjacencia::~ListaAdjacencia()
{
    while (vertices != nullptr)
    {
        ListaEncadeada *temp = vertices;
        vertices = vertices->nextlist;
        delete temp;
    }
}

void ListaAdjacencia::insereFinal(ListaEncadeada *mylista)
{
    ListaEncadeada *novaLista = new ListaEncadeada(*mylista);
    novaLista->nextlist = nullptr;

    if (vertices == nullptr)
    {
        vertices = novaLista;
    }
    else
    {
        ListaEncadeada *atual = vertices;
        while (atual->nextlist != nullptr)
        {
            atual = atual->nextlist;
        }

        atual->nextlist = novaLista;
    }

    numVertices++;
}

ListaEncadeada *ListaAdjacencia::removeFinal()
{
    if (vertices == nullptr)
    {
        throw std::runtime_error("Erro: lista vazia");
    }

    ListaEncadeada *itemRemovido = vertices;

    if (numVertices == 1)
    {
        delete vertices;
        vertices = nullptr;
    }
    else
    {
        ListaEncadeada *atual = vertices;
        while (atual->nextlist->nextlist != nullptr)
        {
            atual = atual->nextlist;
        }

        delete atual->nextlist;
        atual->nextlist = nullptr;

        itemRemovido = atual;
    }

    numVertices--;

    return itemRemovido;
}

void ListaAdjacencia::imprime()
{
    ListaEncadeada *atual = vertices;

    while (atual != nullptr)
    {
        atual->Imprime();
        atual = atual->nextlist;
    }
}

int ListaAdjacencia::getTamanho()
{
    return numVertices;
}

ListaEncadeada *ListaAdjacencia::getLista(int index)
{
    if (index < 0 || index >= numVertices)
    {
        throw std::runtime_error("Erro: índice fora dos limites");
    }

    ListaEncadeada *atual = vertices;

    for (int i = 0; i < index; i++)
    {
        atual = atual->nextlist;
    }

    return atual;
}