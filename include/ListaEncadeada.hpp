#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP

#include <iostream>

struct No {
    int value; // Valor do nó
    No* next; // Ponteiro para o próximo nó
};

class ListaEncadeada {
    public:
        /**
         * \brief Construtor padrão.
         */
        ListaEncadeada();
        /**
         * \brief Destrutor padrão.
         */
        ~ListaEncadeada();
        /**
         * \brief Insere um valor no final da lista.
         */
        void InsereFinal(int insertvalue);
        /**
         * \brief Remove o último valor da lista.
         */
        No RemoveFinal();
        /**
         * \brief Imprime a lista.
         */
        void Imprime();
        /**
         * \brief Verifica se a lista está vazia.
         */
        bool isEmpty();
        /**
         * \brief Retorna o tamanho da lista.
         */
        int Tamanho();

        No* first; // Ponteiro para o primeiro nó
        No* last; // Ponteiro para o último nó
        ListaEncadeada* previouslist; // Ponteiro para a lista anterior
        ListaEncadeada* nextlist; // Ponteiro para a próxima lista
        int size; // Tamanho da lista

    private:
};

#endif