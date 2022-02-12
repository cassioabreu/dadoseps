#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//Estrutura do nó

typedef struct no{
    int num;
    struct no *prox;
} NO;



//função para alocar memória

NO* cria_no(){
    NO *no = (NO*)malloc(sizeof(NO));
    return no;
}



//função para adicionar novo nó ao final da lista

NO* insere_final(NO *lista, int dado){
    NO *novo_no = cria_no();
    novo_no->num = dado;

    if (lista == NULL){
        novo_no->prox = NULL;
        lista = novo_no;
    }
    else {
        NO* aux = lista;

        while (aux->prox != NULL){
            aux = aux->prox;
        }
        novo_no->prox = NULL;
        aux->prox = novo_no;
    }
    return lista;
}



//função para calcular o desvio padrão

double desvio_padrao(NO* ptr, double media, int nserie){
    NO *aux = ptr;
    double desvio;
    double somatquad;

    for(int i=0; i<nserie; i++){
        somatquad = somatquad + (pow((aux->num - media), 2));
        if(aux->prox != NULL){
            aux = aux->prox;
        }
    }
    desvio = sqrt(somatquad / (nserie));
    return desvio;
}



int main(){

    int numaval;
    int numalunos;

    printf("Quantidade de alunos: ");
    scanf("%d", &numalunos);

    printf("\nNúmero de avaliações: ");
    scanf("%d", &numaval);


    NO *notas = NULL;   //lista criada
    int n;


    //inserindo notas na lista

    for(int i=0; i < numaval; i++){
        printf("\n--- \nAvaliação %d \n", i+1);


        for(int j=0; j < numalunos; j++){
            printf("%d > ", j+1);
            scanf("%d", &n);
            notas = insere_final(notas, n);
        }
    }



    printf("\n\nResultado final ");


    // medias arredondadas dos alunos

    printf("\nMédias arredondadas, para cima, dos alunos:");

    float media1;
    NO* ptr = notas;
    NO* aux = notas;
    for(int a=0; a<numalunos; a++){
        int soma = 0;
        aux = ptr;
        ptr = ptr->prox;
        for(int i=0; i<numaval; i++){
            soma = soma + aux->num;
            if(i!=(numaval-1)){
                for (int j=0; j<numalunos; j++){
                aux = aux->prox;
                }
            }
        }
        media1 = ((float)soma/(float)numaval);
        printf("\n%d > %.0f", (a+1), ceil(media1));
    }



    // média e desvio padrão

    printf("\n\n\nMédia e desvio padrão (populacional) das avaliações:");
    printf("\n\n         Média     Desvio");

    aux = notas;
    ptr = notas;
    for(int i=0; i<numaval; i++){
        double media2 = 0;
        double desvio = 0;
        int soma = 0;
        ptr = aux;

        for (int j=0; j<numalunos; j++){
            soma = soma + aux->num;
            if(aux->prox != NULL){
                aux = aux->prox;
            }
        }
        media2 = ((double)soma/(double)numalunos);
        desvio = desvio_padrao(ptr, media2, numalunos);

        printf("\nAv %d. %7.1f %10.2f", i+1, media2, desvio);
    }

    printf("\n ");
    return 0;
}
