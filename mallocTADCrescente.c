#include <stdio.h>
struct regLista
{
    int valor;
    struct regLista *prox;
};

int main()
{
    int numero;
    struct regLista *inicio, *aux, *ant, *aux2;
/* inicializando a variável inicio com um endereco vazio */
    inicio = NULL;
    while(1)
    {
        printf("Informe o numero: ");
        scanf("%d", &numero);
        if( numero < 0 )
            break;
/* criando uma variável struct regLista dinamicamente */
        aux = (struct regLista *) malloc( sizeof(struct regLista) );
/* preenchendo os campos da variável criada dinamicamente */
        aux->valor = numero;
        aux->prox = NULL;
        if( inicio == NULL )
            inicio = aux;
        else    // procura posicao correta para incluir
        {
            if (inicio->valor > aux->valor)//se o novo tem que ser incluido no inicio e jogar o inicio para a frente
			{
				aux->prox = inicio;
				inicio = aux;
			}
	        else   //começa os testes com os demais
	        {
	            aux2 = inicio->prox;
	            ant = inicio;
	            while ( aux2 != NULL )
	            {
	                if (aux2->valor > aux->valor)
					{   aux->prox = aux2;
						ant->prox = aux;
					}
					else
					{	ant = aux2;
						aux2 = aux2->prox;
					}
	            }
	            if (aux2 == NULL)
				{
					ant->prox = aux;
	        	}
        }
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
