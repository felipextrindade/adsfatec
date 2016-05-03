#include <stdio.h>
struct regLista
{
    int valor;
    struct regLista *prox;
};

int main()
{
    int numero, opcao;
    struct regLista *raiz, *aux;

    raiz = NULL;

    while(opcao != 5){
        printf("\n1) Inserir um novo elemento no topo\n2) Remover o elemento do topo\n3) Consultar o elemento do topo\n4) Inicializar a pilha\n5) Fim\nOpção: ");
        scanf("%i", &opcao);

        aux = raiz;

        while ( aux != NULL ){
        printf("%d\n", aux->valor);
        aux = aux->prox;
        }

        if(opcao == 1){
            printf("\nNumero: ");
            scanf("%i", &numero);
            if(numero < 0){
                break;
            }
            aux = (struct regLista *) malloc( sizeof(struct regLista) );

            aux->valor = numero;
            aux->prox = NULL;

            if(raiz == NULL)
                raiz = aux;
            else{
                aux->prox = raiz;
                raiz = aux;
            }
        }
        if(opcao == 2){
            if(raiz == NULL)
                printf("\nJá está vazia\n");
            else if (raiz->prox == NULL){
                raiz = raiz->prox;
                printf("\nItem removido. Não há mais nada na lista\n");
            }
            else{
                raiz = raiz->prox;
            }
        }
        if(opcao==3) {
            if(raiz == NULL)
                printf("\nA pilha está vazia\n");
            printf("\nO elemento do topo é: %i\n", raiz->valor);
        }

        if(opcao==4) {
            raiz = NULL;
            printf("\nLista inicializada.\n");
        }

    }
    return 0;
}
