#include "ListaEncadeada.hpp"

ListaEncadeada::ListaEncadeada()
{
    first = nullptr;
    last = nullptr;
    size = 0;
}

ListaEncadeada::~ListaEncadeada()
{
    while (first != nullptr) {
        No* temp = first;
        first = first->next;
        delete temp;
    }
}

bool ListaEncadeada::isEmpty() {
    return size == 0;
}

void ListaEncadeada::InsereFinal(int insertvalue)
{
    No *novoNo = new No;
    novoNo->value = insertvalue;
    novoNo->next = nullptr;

    if (isEmpty())
    {
        first = novoNo;
        last = novoNo;
    }
    else
    {
        last->next = novoNo;
        last = novoNo;
    }
    size++;
}

No ListaEncadeada::RemoveFinal()
{
    if (isEmpty())
    {
        std::cout << "Erro: lista vazia\n" << std::endl;
    }

    No itemRemovido = *last;

    if (size == 1)
    {
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else
    {
        No *atual = first;
        while (atual->next != last) {
            atual = atual->next;
        }
        
        delete last;
        last = atual;
        last->next = nullptr;
    }

    size--;
    
    return itemRemovido;
}

void ListaEncadeada::Imprime()
{
    No *atual = first;
    
    while (atual != nullptr)
    {
        std::cout << atual->value << " ";
        atual = atual->next;
    }
    
    std::cout << std::endl;
}

int ListaEncadeada::Tamanho() {
    return size;
}