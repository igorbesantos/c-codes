/*	Aluno: Igor Bezerra dos Santos		Matrícula: UC16101948
	Síntese
	Objetivo: Ler vários produtos (até ser informado um produto de valor 0) e os apresentar com reajuste no final
	Entrada:  Valor atual e porcentagem de reajuste de cada produto
	Saída:	  Valor atual, porcentagem de reajuste e novo valor de cada produto
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_QTD 3

typedef struct{
	float precoAtual;
	float reajuste;
	float precoFinal;
} produto;

int leProduto (produto*);
float leValidaFloat(char[], int);
void exibeProduto(produto*);

int main() {
	int cont=0, i=0;
	produto produtos[MAX_QTD];
	
	//recebe produtos
	do{
		//leProduto
		if(!leProduto(&produtos[cont])){
			if(cont==0){
				printf("Nenhum produto foi lido, o programa sera encerrado!\n");
				system("pause");
			}
			break;
		}
		cont++;
		if(cont==MAX_QTD){
			printf("Buffer cheio! (%d Produtos)", MAX_QTD);
			system("pause");
			system("cls");
		}
	}while(cont<MAX_QTD);
	
	//exibeResultado
	for(i=0; i<cont; i++){
		printf("Produto %2d:\n", i+1);
		exibeProduto(&produtos[i]);
	}
	return 0;
}

int leProduto (produto *p){
	produto prod = *p;
	prod.precoAtual = leValidaFloat("Informe o preco atual do produto: ", 1);
	if(prod.precoAtual==0.0){
		return 0;
	}
	prod.reajuste = leValidaFloat("Informe a porcentagem (%) do reajuste do preco do produto : ", 0);
	prod.precoFinal = prod.precoAtual + (prod.precoAtual*prod.reajuste/100);
	*p = prod;
	printf("\nProduto cadastrado com sucesso!\n");
	system("pause");
	system("cls");
	return 1;
}

float leValidaFloat (char mensagem[], int isPreco){
	float valor = 0.0;
	
	do{
		printf("%s", mensagem);
		scanf("%f", &valor);
		fflush(stdin);
		system("cls");
		if(isPreco){
			if(valor==0.0){
				return 0.0;
			}
		}
		if(valor<0.0){
			printf("Valor invalido! ");
		}
	}while(valor<0.0);
	return valor;
}

void exibeProduto(produto *p){
	produto prod = *p;
	printf("Valor original: %.2f \nReajuste: %.2f%% \nNovo Valor: %.2f \n\n", prod.precoAtual, prod.reajuste, prod.precoFinal);
}
