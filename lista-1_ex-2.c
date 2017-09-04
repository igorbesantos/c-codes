/*	Síntese
	Objetivo: 
	Entrada: 
	Saída: 
*/
#include <stdio.h>
#include <stdlib.h>
#define QTD_MAX 8

char leValidaOpcao();
int leValidaInteiro(char[], int[]);
float leValidaFloat(char[]);
int isCadastrado(int, int[]);
void ordena(float[], int[], int);

int main() {
	int cont=0, i=0, matricula[QTD_MAX]={0};
	float salario[QTD_MAX]={0};
	char opcao;
	do{
		printf("%d%c Funcionario: \n", cont+1, 248);
		matricula[cont]=leValidaInteiro("Informe a matricula: ", matricula);
		printf("%d%c Funcionario: \n", cont+1, 248);
		salario[cont]=leValidaFloat("Informe o salario: ");
		
		if(++cont<QTD_MAX){
			opcao=leValidaOpcao();
		}else{
			opcao = 'N';
		}	
	}while(opcao=='S' && cont<QTD_MAX);
	
	ordena(salario, matricula, cont);
	
	for(i=cont; i>0; i--){
		printf("Matricula: %d\nSalario: R$ %.2f\n\n", matricula[i], salario[i]);
	}
	return 0;
}

int leValidaInteiro(char msg[], int lista[]){
	int valor=0;
	
	do{
		printf("%s", msg);
		scanf("%d", &valor);
		if(valor<=0){
			printf("\nNumero invalido! ");
		}else if(isCadastrado(valor, lista)){
			printf("\nJá cadastrado! ");
		}
	}while(valor<=0 || isCadastrado(valor, lista));
	system("cls");
	return valor;
}

float leValidaFloat(char msg[]){
	float valor=0;
	
	do{
		printf("%s", msg);
		scanf("%f", &valor);
		if(valor<=0){
			printf("\nValor invalido! ");
		}
	}while(valor<=0);
	system("cls");
	return valor;
}

int isCadastrado(int valor, int lista[]){
	int i=0;
	int cadastrado = 0;
	
	for(i=0; i<QTD_MAX; i++){
		if(valor==lista[i]){
			cadastrado = 1;
		}
	}
	return cadastrado;
}

char leValidaOpcao(){
	char opcao;
	fflush(stdin);
	do{
		printf("Deseja cadastrar mais um funcionario? (S/N)");
		opcao = getch();
		opcao = toupper(opcao);
		system("cls");
		if(opcao!='S' && opcao!='N'){
			printf("Opcao invalida! ");
		}
	}while(opcao!='S' && opcao!='N');
	return opcao;
}

void ordena(float salarios[], int matriculas[], int cont){
	cont--;
	float auxf = 0.0;
	int auxi = 0, i=0 , j=0;
	for(i=0; i<cont; i++){
		for(j=0; j<cont-i-1; j++){
			if(salarios[j]>salarios[j+1]){
				auxf = salarios[j];
				auxi = matriculas[j];
				salarios[j]=salarios[j+1];
				matriculas[j]=matriculas[j+1];
				salarios[j+1]=auxf;
				matriculas[j+1]=auxi;
			}
		}
	}
}

