/*	Síntese
	Objetivo: Ler de até 500 animais um identificador e o peso. 
		No final, apresentar todos, além do mais leve e do mais pesaado.
	Entrada: Id e peso de cada animal
	Saída: 
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_ANIMAIS 3 //500

char leValidaOpcao();
int leValidaInteiro(char[], int[]);
int isCadastrado(int, int[]);

int main() {
	char opcao;
	int i=0, cont=0, id[MAX_ANIMAIS]={0}, peso[MAX_ANIMAIS]={0}, codMaisPesado=0, codMaisLeve=0;

	do{
		printf("Animal %d\n",cont+1);
		id[cont] = leValidaInteiro("Informe o numero identificador do animal: ", id);
		printf("Animal %d\n",cont+1);
		peso[cont] = leValidaInteiro("Informe o peso do animal: ", peso);
		
		if(peso[cont] > peso[codMaisPesado] || cont==0){
			codMaisPesado = cont;
		}
		if(peso[cont] < peso[codMaisLeve] || cont==0){
			codMaisLeve = cont;
		}
		if(++cont<MAX_ANIMAIS){
			opcao=leValidaOpcao();
		}else{
			opcao = 'N';
		}	
	}while(opcao=='S' && cont<MAX_ANIMAIS);
	system("cls");
	
	for(i=0; i<cont; i++){
		printf("Codigo: %d\tPeso: %d\n", id[i], peso[i]);
	}
	printf("\nAnimal mais pesado:\nCodigo: %d\tPeso: %d\n", id[codMaisPesado], peso[codMaisPesado]);
	printf("\nAnimal mais leve:\nCodigo: %d\tPeso: %d\n", id[codMaisLeve], peso[codMaisLeve]);
	return 0;
}

char leValidaOpcao(){
	char opcao;
	fflush(stdin);
	do{
		printf("Deseja cadastrar mais um animal? (S/N)");
		opcao = getch();
		opcao = toupper(opcao);
		system("cls");
		if(opcao!='S' && opcao!='N'){
			printf("Opcao invalida! ");
		}
	}while(opcao!='S' && opcao!='N');
	return opcao;
}

int leValidaInteiro(char msg[], int lista[]){
	int valor=0;
	
	do{
		printf("%s", msg);
		scanf("%d", &valor);
		if(valor<=0){
			printf("\nValor invalido! ");
		}else if(isCadastrado(valor, lista)){
			printf("\nJá cadastrado! ");
		}
	}while(valor<=0 || isCadastrado(valor, lista));
	system("cls");
	return valor;
}

int isCadastrado(int valor, int lista[]){
	int i=0;
	int cadastrado = 0;
	
	for(i=0; i<MAX_ANIMAIS; i++){
		if(valor==lista[i]){
			cadastrado = 1;
		}
	}
	return cadastrado;
}


