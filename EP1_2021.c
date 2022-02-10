#include <stdio.h>
#include <math.h>

#define MAX 100

int main()
{
    int nserie;

    printf("Quantos números da sua série (N): ");
    scanf("%d", &nserie);

    while (nserie > MAX){
        printf("Valor muito alto! Insira um número até 100.\n..........\n");

        printf("Quantos números da sua série (N): ");
        scanf("%d", &nserie);
    }

    float vet[nserie];

    printf("Entre com números:\n");

    for (int i=0; i<nserie; i++){
        printf("> ");
        scanf("%f", &vet[i]);
    }


    //Valor Mínimo

    float nmin = vet[0];
    for (int i=0; i<nserie; i++) {
        if (vet[i]<nmin) {
            nmin = vet[i];
        }
    }
    printf("\nValor mínimo: ");
    printf("%.1f", nmin);



     //Valor Máximo

    float nmax = vet[0];
    for (int i=0; i<nserie; i++) {
        if (vet[i]>nmax) {
            nmax = vet[i];
        }
    }
    printf("\nValor Máximo: ");
    printf("%.1f", nmax);



     //Média

    double soma;
    double media;
    for (int i=0; i<nserie; i++) {
            soma = soma + vet[i];
    }
    media = soma / nserie;
    printf("\nMédia: ");
    printf("%.2f", media);



     //Mediana


    float aux;
    float mediana;
    int n = 0;
    float* ptr = &vet[0];

    while (ptr <= &vet[nserie]){
        for (int i=n; i<nserie; i++) {
            if (vet[i] < *ptr){
                aux = vet[i];
                vet[i] = *ptr;
                *ptr = aux;
            }
        }
        ptr++;
        n++;
    }


    if (nserie % 2 != 0){
        int meio = nserie / 2;
        mediana = vet[meio];
        printf("\nMediana: %.2f", mediana);
    }

    if (nserie % 2 == 0){
        int meio = nserie / 2;
        mediana = (vet[meio-1] + vet[meio])/ 2;
        printf("\nMediana: %.2f", mediana);
    }



    //Desvio Padrão

    double desvio;
    double somatquad;

    for(int i=0; i<nserie; i++){
        somatquad = somatquad + (pow((vet[i] - media), 2));
    }
    desvio = sqrt(somatquad / (nserie - 1));
    printf("\nDesvio Padrão: %.12f", desvio);



    return 0;
}
