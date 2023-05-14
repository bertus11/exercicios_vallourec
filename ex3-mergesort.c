#include <stdio.h>
#include <stdlib.h>

void merge(int x[], int y[], int z[], int n, int m) {
    int i = 0, j = 0, k = 0;
    
    //fazendo comparação entre os indices das duas filas (x,y) e armazenando os menores em z//
    while (i < n && j < m) {
        if (x[i] < y[j]) {
            z[k] = x[i];
            i++;
        } else {
            z[k] = y[j];
            j++;
        }
        k++;
    }
    
    //caso haja resto de conteudo
    while (i < n) {
        z[k] = x[i];
        i++;
        k++;
    }
    
    while (j < m) {
        z[k] = y[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int n) {
    if (n > 1) {
        int meio = n / 2;
        int *esquerda = (int*) malloc(meio * sizeof(int));
        int *direita = (int*) malloc((n - meio) * sizeof(int));
        
        for (int i = 0; i < meio; i++) {
            esquerda[i] = a[i];
        }
        
        for (int i = meio; i < n; i++) {
            direita[i - meio] = a[i];
        }
        
        merge_sort(esquerda, meio);
        merge_sort(direita, n - meio);
        merge(esquerda, direita, a, meio, n - meio);
        
        free(esquerda);
        free(direita);
    }
}

int main() {
    int x[] = {-1, 10, 8, 31};
    int y[] = {3, 6, 15};
    int n = sizeof(x) / sizeof(x[0]);
    int m = sizeof(y) / sizeof(y[0]);
    int *z = (int*) malloc((n + m) * sizeof(int));
    
    merge_sort(x, n);
    merge_sort(y, m);
    merge(x, y, z, n, m);
    
    for (int i = 0; i < n + m; i++) {
        printf("%d ", z[i]);
    }
    printf("\n");
    
    free(z);
    
    return 0;
}
