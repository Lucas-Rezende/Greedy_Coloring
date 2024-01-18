#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP

#include <iostream>

struct No {
    int value;
    //No* previous;
    No* next;
};

class ListaEncadeada {
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        void InsereFinal(int insertvalue);
        No RemoveFinal();
        void Imprime();
        bool isEmpty();
        int Tamanho();

        No* first;
        No* last;
        ListaEncadeada* previouslist;
        ListaEncadeada* nextlist;
        int size;

    private:
};

#endif