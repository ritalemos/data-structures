#include <stdio.h>
#include <stdlib.h>

int busca_linear(int *v, int i, int size, int chave){
    if(i == size) return -1;

    if(*(v + i) == chave) return i;

    else return busca_linear(v, i+1, size, chave);
}

//obs.: o array deve estar ordenado!!
int busca_binaria(int *v, int size, int chave, int esquerda, int direita){
    int meio = (esquerda + direita) / 2;

    if(esquerda > direita) return -1;
    if(*(v + meio) == chave) return meio;
    else if(chave < *(v + meio)) return busca_binaria(v, size, chave, esquerda, meio-1);
    else if(chave > *(v+ meio)) return busca_binaria(v, size, chave, meio+1, direita);
}

int main(){
    int size, i;
    int *v;

    scanf("%d", &size);

    v = malloc(size * sizeof(int));

    for(i = 0; i < size; i++){
        scanf("%d", (v + i));
    }

    int pos_linear = busca_linear(v, 0, size, 3);
    int pos_binaria = busca_binaria(v, size, 3, 0, size-1);

    printf("index %d %d\n", pos_linear, pos_binaria);
    printf("valores %d %d\n", *(v + pos_linear), *(v + pos_binaria));

    free(v);
    return 0;
}