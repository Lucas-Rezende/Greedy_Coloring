#include "algoritmos.hpp"

Algoritmos::Algoritmos() {}

Algoritmos::~Algoritmos() {}

void Algoritmos::BubbleSort(Grafo &mygraph, int n, int *vertices)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 1; j < n - i; j++)
            if (mygraph.GetCor(vertices[j]) < mygraph.GetCor(vertices[j - 1]) ||
                (mygraph.GetCor(vertices[j]) == mygraph.GetCor(vertices[j - 1]) && vertices[j] < vertices[j - 1]))
            {
                std::swap(vertices[j], vertices[j - 1]);
            }
}

void Algoritmos::SelectionSort(Grafo &mygraph, int n, int *vertices)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (mygraph.GetCor(vertices[j]) < mygraph.GetCor(vertices[min]) ||
                (mygraph.GetCor(vertices[j]) == mygraph.GetCor(vertices[min]) && vertices[j] < vertices[min]))
            {
                min = j;
            }
        }
        std::swap(vertices[i], vertices[min]);
    }
}

void Algoritmos::InsertionSort(Grafo &mygraph, int n, int *vertices)
{
    for (int i = 1; i < n; i++)
    {
        int key = vertices[i];
        int j = i - 1;

        // Move os elementos do array[0..i-1], que são maiores que a chave, para uma posição à frente de sua posição atual
        while (j >= 0 && mygraph.GetCor(vertices[j]) > mygraph.GetCor(key))
        {
            vertices[j + 1] = vertices[j];
            j = j - 1;
        }
        vertices[j + 1] = key;
    }
}

void Algoritmos::Particao(int Esq, int Dir, int *i, int *j, Grafo &mygraph, int* vertices)
{ 
    int pivo = vertices[(Esq + Dir) / 2];
    int w;
    *i = Esq; *j = Dir;
    do
    { 
        while (mygraph.GetCor(vertices[*i]) < mygraph.GetCor(pivo) || 
               (mygraph.GetCor(vertices[*i]) == mygraph.GetCor(pivo) && vertices[*i] < pivo)) (*i)++;
        while (mygraph.GetCor(vertices[*j]) > mygraph.GetCor(pivo) || 
               (mygraph.GetCor(vertices[*j]) == mygraph.GetCor(pivo) && vertices[*j] > pivo)) (*j)--;
        if (*i <= *j)
        { 
            w = vertices[*i]; vertices[*i] = vertices[*j]; vertices[*j] = w;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void Algoritmos::Ordena(int Esq, int Dir, Grafo &mygraph, int* vertices)
{ 
    int i, j;
    Particao(Esq, Dir, &i, &j, mygraph, vertices);
    if (Esq < j) Ordena(Esq, j, mygraph, vertices);
    if (i < Dir) Ordena(i, Dir, mygraph, vertices);
}

void Algoritmos::QuickSort(Grafo &mygraph, int n, int* vertices)
{ 
    Ordena(0, n-1, mygraph, vertices); 
}

void Algoritmos::Merge(Grafo &mygraph, int* vertices, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = vertices[left + i];
    for (j = 0; j < n2; j++)
        R[j] = vertices[mid + 1 + j];

    // Mescla os arrays temporários de volta para o array vertices[]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = left; // Índice inicial do subarray mesclado
    while (i < n1 && j < n2)
    {
        if (mygraph.GetCor(L[i]) <= mygraph.GetCor(R[j]))
        {
            vertices[k] = L[i];
            i++;
        }
        else
        {
            vertices[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1)
    {
        vertices[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2)
    {
        vertices[k] = R[j];
        j++;
        k++;
    }
}

void Algoritmos::MergeSort(Grafo &mygraph, int* vertices, int left, int right)
{
    if (left < right)
    {
        // Mesmo que (left+right)/2, mas evita overflow para grandes valores de left e right
        int mid = left + (right - left) / 2;

        // Ordena a primeira e a segunda metade
        MergeSort(mygraph, vertices, left, mid);
        MergeSort(mygraph, vertices, mid + 1, right);

        Merge(mygraph, vertices, left, mid, right);
    }
}

void Algoritmos::Refaz(int Esq, int Dir, Grafo &mygraph, int* vertices)
{
    int i = Esq;
    int j = 2*i + 1; // Filho esquerdo de i
    int x = vertices[i];
    while (j <= Dir)
    {
        if (j < Dir)
        {
            // Compara com base na cor e no rótulo em caso de empate na cor
            if (mygraph.GetCor(vertices[j]) < mygraph.GetCor(vertices[j + 1]) ||
                (mygraph.GetCor(vertices[j]) == mygraph.GetCor(vertices[j + 1]) && vertices[j] < vertices[j + 1]))
                j++; // Filho direito de i
        }
        // Compara com base na cor e no rótulo em caso de empate na cor
        if (mygraph.GetCor(x) < mygraph.GetCor(vertices[j]) ||
            (mygraph.GetCor(x) == mygraph.GetCor(vertices[j]) && x < vertices[j]))
        {
            vertices[i] = vertices[j];
            i = j;
            j = 2*i + 1;
        }
        else
        {
            break;
        }
    }
    vertices[i] = x;
}

void Algoritmos::Constroi(Grafo &mygraph, int n, int* vertices)
{
    for(int i = n/2 - 1; i >= 0; i--)
        Refaz(i, n-1, mygraph, vertices);
}

void Algoritmos::HeapSort(Grafo &mygraph, int n, int* vertices)
{
    Constroi(mygraph, n, vertices);
    for(int i = n-1; i > 0; i--)
    {
        std::swap(vertices[0], vertices[i]);
        Refaz(0, i-1, mygraph, vertices);
    }
}

void Algoritmos::MySort(Grafo &mygraph, int n, int *vertices)
{
// 1. Encontre o valor máximo em vértices[]
    int maxVal = 0;
    for (int i = 0; i < n; i++)
        maxVal = std::max(maxVal, mygraph.GetCor(vertices[i]));

    // 2. Crie um array de baldes
    int bucket[maxVal + 1][n];
    int bucketCount[maxVal + 1] = {0};

    // 3. Coloque cada vértice no respectivo balde
    for (int i = 0; i < n; i++) {
        int idx = mygraph.GetCor(vertices[i]);
        bucket[idx][bucketCount[idx]++] = vertices[i];
    }

    // 4. Ordene os baldes individualmente usando Shell Sort
    for (int i = 0; i <= maxVal; i++) {
        for (int gap = bucketCount[i]/2; gap > 0; gap /= 2) {
            for (int j = gap; j < bucketCount[i]; j++) {
                int temp = bucket[i][j];
                int k;
                for (k = j; k >= gap && bucket[i][k - gap] > temp; k -= gap)
                    bucket[i][k] = bucket[i][k - gap];
                bucket[i][k] = temp;
            }
        }
    }

    // 5. Concatene todos os baldes em vertices[]
    int index = 0;
    for (int i = 0; i <= maxVal; i++)
        for (int j = 0; j < bucketCount[i]; j++)
            vertices[index++] = bucket[i][j];
}

bool Algoritmos::isGulosa(Grafo &mygraph, int n, int *vertices)
{
    bool checkGulosa = true;
    for (int i = 0; i < n && checkGulosa; i++)
    {
        int corVertice = mygraph.GetCor(vertices[i]);
        for (int cor = 1; cor < corVertice && checkGulosa; cor++)
        {
            bool found = false;
            ListaEncadeada *adjacencias = mygraph.getAdjacencias(vertices[i]);
            No *noAtual = adjacencias->first;
            while (noAtual != nullptr && !found)
            {
                if (mygraph.GetCor(noAtual->value) == cor)
                {
                    found = true;
                }
                noAtual = noAtual->next;
            }
            if (!found)
            {
                checkGulosa = false;
            }
        }
    }
    return checkGulosa;
}

void Algoritmos::printOutput(Grafo &mygraph, int n, bool gulosa, int *vertices)
{
    if (isGulosa(mygraph, n, vertices))
    {
        std::cout << "1 ";
        for (int i = 0; i < n; i++)
        {
            std::cout << vertices[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "0" << std::endl;
    }
}