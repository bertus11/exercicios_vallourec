#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void proxPrimo(int num);

int main(){

    int num;

    do {
        printf("Insira um numero: ");
        scanf("%d", &num);
    } while (num < 1);

    proxPrimo(num);

    return 0;
}

void proxPrimo(int num){
    bool ehPrimo = false;

    do {
        ehPrimo = true;
        num++;

        for (int i = 2; i <= num/2; i++){
            if (num % i == 0){ //nao eh primo
                ehPrimo = false;
                break;
            }
        }
    } while (!ehPrimo);

    if(ehPrimo){
        printf("O proximo numero primo e: %d", num);
    }
}