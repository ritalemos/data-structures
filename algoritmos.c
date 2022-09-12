#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int *v, int size){
    int i, j;
    for(j = size - 1; j >= 0; j--){
        for(i = 0; i < j; i++){
            if(v[i] > v[i+1]){
                swap(&v[i], &v[i+1]);
            }
        }
    }
}

void selection(int *v, int size){
    int i, j, menor;
    for(i = 0; i < size; i++){
        menor = i;
        for(j = i + 1; j < size; j++){
            if(v[j] < v[menor]){
                menor = j;
                swap(&v[i], &v[menor]);
            }
        }
    }
}

void quick(int *v, int size){
    if(size <= 1) return;

    else{
        int pivot = v[size/2];
        int a = 0;
        int b = size - 1;

        while(a < b){
            while(v[a] < pivot) a++;
            while(v[b] > pivot) b--;

            if(a < b){
                swap(&v[a], &v[b]);
                if(v[a] == v[b]) b--;
            }
        }
        quick(v, a);
        quick(v+a+1, size-a-1);
    }
}

void insertion(int *v, int size){
    int i, j, aux;

    for(i = 1; i < size; i ++){
        aux = v[i];
        j = i - 1;

        while((j >= 0) && v[j] > aux){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}

void merge(int *v, int size){

}

int binaria(int *v, int esquerda, int direita, int key){
    while(esquerda <= direita){
        int meio = (esquerda + direita) / 2;
        
        if(v[meio] > key) return binaria(v, esquerda, meio - 1, key);
        else if(v[meio] < key) return binaria(v, meio + 1, direita, key);
        else return meio;
    }
    return -1;
}

int linear(int *v, int size, int key){
    int i;
    for(i = 0; i < size; i++){
        if(v[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    printf("Digite uma opção:\n1. Busca Linear\n2. Busca Binária\n3. Ordenação\n");
    int op;
    scanf("%d", &op);

    int size, key, i;

    printf("Digite o tamanho do array\n");
    scanf("%d", &size);
        
    int array[size];

    for(i = 0; i < size; i++) scanf("%d", &array[i]);

    if(op == 1){
        printf("Qual valor você deseja encontrar?\n");
        scanf("%d", &key);

        int resultado = linear(array, size, key);

        if(resultado == -1) printf("Elemento não encontrado\n");

        else printf("Elemento encontrado na posição %d\n", resultado);
    }

    if(op == 2){
        bubble(array, size);

        printf("Array ordenado:\n");
        for(i = 0; i < size; i++) printf("%d ", array[i]);
        printf("\n");

        printf("Qual valor você deseja encontrar?\n");
        scanf("%d", &key);
        

        int resultado = binaria(array, 0, size-1, key);

        if(resultado == -1) printf("Elemento não encontrado\n");

        else printf("Elemento encontrado na posição %d\n", resultado);

    }
    else{
        printf("Escolha um método de ordenação:\n");
        printf("1. BubbleSort\n");
        printf("2. SelectionSort\n");
        printf("3. QuickSort\n");
        printf("4. InsertionSort\n");
        printf("5. MergeSort\n");


        int sort;
        scanf("%d", &sort);
        if(sort == 1) bubble(array, size);
        else if(sort == 2) selection(array, size);
        else if(sort == 3) quick(array, size);
        else if(sort == 4) insertion(array, size);

        for(i = 0; i < size; i++) printf("%d ", array[i]);
            printf("\n");
    }

    return 0;
}