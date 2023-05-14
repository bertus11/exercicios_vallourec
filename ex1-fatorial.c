#include<stdio.h>
#include<stdlib.h>

unsigned long long int fatorial(int num);

int main(){
    int num;
    printf("Insira um numero para calcular o fatorial: ");
    scanf("%d", &num);

    if (num < 0){
        printf("impossivel calcular fatorial negativo.");
    } else {
        unsigned long long int resultado = fatorial(num);
        if (resultado == -1){
            printf("Overflow ao calcular o fatorial de %d", num);
        } else {
            printf("%d! = %llu\n", num, resultado);
        }
    }
    return 0;
}

unsigned long long int fatorial(int num){

    if (num < 0){ //tratamento para numeros negativos
        return (0);
    } else {
        if (num <= 1){ //caso zero ou 1
            return (1);
        } else { 
            unsigned long long int resultado = num * fatorial(num-1);
            if (resultado < num){
                return (-1); //erro de overflow
            } else {
                return resultado;
            }
        }
    }
}