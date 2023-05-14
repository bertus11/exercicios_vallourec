#include <stdio.h>
#include<stdio.h>

int carretas[] = {6000, 27000, 31000, 35000};

int pesos_tubos[] = {480, 1320, 1800};

int selecionar_carreta(int qtd_tubos_5_1_2, int qtd_tubos_10, int qtd_tubos_10_3_4) {
    int peso_total = qtd_tubos_5_1_2 * pesos_tubos[0] +
                     qtd_tubos_10 * pesos_tubos[1] +
                     qtd_tubos_10_3_4 * pesos_tubos[2];

    for (int i = 0; i <= 3; i++) {
        if (peso_total <= carretas[i]) {
            return i;
        }
    }

    return 3; // se não couber em nenhuma carreta, utilizar a maior disponível (T35)
}

int main(){

    int qtd_tubos_5_1_2, qtd_tubos_10, qtd_tubos_10_3_4;
    printf("---------------------------------\n");
    printf("Quantidade de tubos 5 1/2\": ");
    scanf("%d", &qtd_tubos_5_1_2);
    printf("Quantidade de tubos 10\": ");
    scanf("%d", &qtd_tubos_10);
    printf("Quantidade de tubos 10 3/4\": ");
    scanf("%d", &qtd_tubos_10_3_4);

    int tipo_carreta = selecionar_carreta(qtd_tubos_5_1_2, qtd_tubos_10, qtd_tubos_10_3_4);

    switch (tipo_carreta)
    {
    case 0:
        printf("Utilizar carreta T6");
        break;
    case 1:
        printf("Utilizar carreta T27");
        break;
    case 2:
        printf("Utilizar carreta T31");
    default:
        printf("Utilizar carreta T35");
        break;
    }
    return 0;
}
