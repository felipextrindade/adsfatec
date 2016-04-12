#include <stdio.h>
struct regLista
{
    int valor;
    struct regLista *prox;
};

int main()
{
    int numero;
    struct regLista *inicio, *aux, *ant;
/* inicializando a vari�vel inicio com um endereco vazio */
    inicio = NULL;
    while(1)
    {
        printf("Informe o numero: ");
        scanf("%d", &numero);
        if( numero < 0 )
            break;
/* criando uma vari�vel struct regLista dinamicamente */
        aux = (struct regLista *) malloc( sizeof(struct regLista) );
/* preenchendo os campos da vari�vel criada dinamicamente */
        aux->valor = numero;
        aux->prox = NULL;
        if( inicio == NULL )
            inicio = aux;
        else    // procura posicao correta para incluir
        {
            ant = inicio;
            while ( ant->prox != NULL )
            {   //printf("%d\n", ant->valor);
                ant = ant->prox;
            }
            ant->prox = aux;
            //ant->prox = aux;
            //ant = aux;
        }
    }
/* imprimindo os valores da lista */
    printf("\n\n\nConteudo da lista:\n");
    aux = inicio;
    while ( aux != NULL )
    {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
    return 0;
}
