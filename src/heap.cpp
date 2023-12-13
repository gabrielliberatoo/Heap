#include "heap.hpp"


Heap::Heap(int maxsize) {
    tamanho = 0; 
    data = new int[maxsize]; 
}


Heap::~Heap() {
    delete[] data; 
}


void Heap::Inserir(int x) {
    if (tamanho == 0) {
        data[0] = x;
    } else {
        int pos = tamanho;
        data[pos] = x;

        while (pos > 0 && data[pos] < data[GetAncestral(pos)]) {
            int temp = data[pos];
            data[pos] = data[GetAncestral(pos)];
            data[GetAncestral(pos)] = temp;

            pos = GetAncestral(pos);
        }
    }
    tamanho++;
}


int Heap::Remover() {
    int max = data[0]; 
    tamanho--;

    if (tamanho > 0) {
        data[0] = data[tamanho]; 
        HeapifyPorBaixo(0); 
    }

    return max;
}

bool Heap::Vazio(){
    if(tamanho == 0){
        return 1;
    }
    else{return 0;}
}


int Heap::GetAncestral(int posicao) {
    return (posicao - 1) / 2;
}

int Heap::GetSucessorEsq(int posicao) {
    return (2 * posicao) + 1;
}

int Heap::GetSucessorDir(int posicao) {
    return (2 * posicao) + 2;
}


void Heap::HeapifyPorBaixo(int posicao) {
    int esquerda = GetSucessorEsq(posicao);
    int direita = GetSucessorDir(posicao);
    int menor = posicao; 

    if (esquerda < tamanho && data[esquerda] < data[menor]) { 
        menor = esquerda;
    }

    if (direita < tamanho && data[direita] < data[menor]) { 
        menor = direita;
    }

    if (menor != posicao) {
        int temp = data[posicao];
        data[posicao] = data[menor];
        data[menor] = temp;
        HeapifyPorBaixo(menor);
    }
}


void Heap::HeapifyPorCima(int posicao) {
    int ancestral;
    while (posicao > 0) {
        ancestral = GetAncestral(posicao);

        if (data[posicao] < data[ancestral]) {
            int temp = data[posicao];
            data[posicao] = data[ancestral];
            data[ancestral] = temp;
            posicao = ancestral;
        } else {
            break;
        }
    }
}


