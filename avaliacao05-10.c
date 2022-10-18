#include <stdio.h>
#include <string.h>
size_t strlen(const char *s);

// Recursividades
int total = 0;
int contador = 1;
int multiplicarNaturais(int num1, int num2){
	if(contador <= num1){
		total += num2;
		contador++;
		return multiplicarNaturais(num1, num2);
	}else{
		return total;
	}
		
}
struct funcionarioType {
	int codigoFuncional;
	char nome[50];
	float salario;
	char dataAdmissao[10];
};

int i;
i = 0;
char invertida[];
void inverterString(char teste[], int fim, int tam){
	if(i < tam){
		invertida[i] = teste[fim];
		i++;
		inverterString(teste, fim-1, tam);
	}
}

int somaVetor(int vetor[], int contador, int somatoria){
	if(contador == -1) return somatoria;
	somatoria += vetor[contador];
	contador--;
	somaVetor(vetor, contador, somatoria);	
}


int palindromo(int i, int tam, int sucesso, char palavra[]){
	if(sucesso == tam) return 1;
	if(palavra[i] != palavra[tam]) return 0;
	tam--;
	i++;
	sucesso++;
	palindromo(i, tam, sucesso, palavra);
}





// Fun��es
void Exercicio01A(int primeiroNumeroNatural, int segundoNumeroNatural){
	// Somatoria com recursividade
	int resultado = multiplicarNaturais(primeiroNumeroNatural,segundoNumeroNatural);
	printf("O resultado de 5x3 = %d", resultado);
}

void Exercicio01B(char teste[]){
	// Inversao de Strings
	int tam = strlen(teste);
	int fim = tam-1;
	inverterString(teste, fim, tam);
	printf("A palavra invertida eh: %s", invertida);
}

void Exercicio01C(int vetor[], int qtdNumeros){
	int total= somaVetor(vetor, qtdNumeros, 0);
	printf("%d", total);
}

void Exercicio01D(char palavra[]){
	int tam = strlen(palavra);
	tam--;
	int i = 0;
	int sucesso = 0;
	
	int simOuNaoPalindromo = palindromo(i,tam,sucesso, palavra);
	printf("%d", simOuNaoPalindromo);
}

void Exercicio02B(struct funcionarioType funcionario){
	for(int i = 0; i < 30; i++){
		for(int j = i+1; j < 30; j++){
			if(funcionario[i].codigoFuncional > funcionario[j].codigoFuncional){
				struct funcionarioType aux = funcionario[i];
				funcionario[i] = funcionario[j];
				funcionario[j] = aux;
			}
		}
	}

	return funcionario;
}


void funcionarios(){
	struct funcionarioType funcionario;
	int opcao;
	int i;

	while(opcao != 0){
		printf("Digite a opção que deseja realizar:");
		printf("1 - Cadastrar funcionario");
		printf("2 - Listar funcionarios");
		printf("3 - Buscar funcionario");
		printf("4 - Sair");
		scanf("%d", &opcao);

		if(opcao == 1){
			printf("Digite o codigo do funcionario:");
			scanf("%d", &funcionario[i].codigoFuncional);
			printf("Digite o nome do funcionario:");
			scanf("%s", &funcionario[i].nome);
			printf("Digite o salario do funcionario:");
			scanf("%f", &funcionario[i].salario);
			printf("Digite a data de admissao do funcionario:");
			scanf("%s", &funcionario[i].dataAdmissao);
			printf("Obrigado! Cadastrado com sucesso.");
		}else if(opcao == 2){
			funcionario = Exercicio02B(funcionario);
			for(int i = 0; i < 30; i++){
				printf("Codigo: %d", funcionario[i].codigoFuncional);
				printf("Nome: %s", funcionario[i].nome);
				printf("Salario: %f", funcionario[i].salario);
				printf("Data de admissao: %s", funcionario[i].dataAdmissao);
			}
		}else if(opcao == 3){
			int codigo;
			printf("Digite o codigo do funcionario que deseja buscar:");
			scanf("%d", &codigo);
			for(int i = 0; i < 30; i++){
				if(funcionario[i].codigoFuncional == codigo){
					printf("Codigo: %d", funcionario[i].codigoFuncional);
					printf("Nome: %s", funcionario[i].nome);
					printf("Salario: %f", funcionario[i].salario);
					printf("Data de admissao: %s", funcionario[i].dataAdmissao);
				}
			}
		}
		i++;
	}
	
}

//Main
int main(void)
{
	int primeiroNumeroNatural = 5;
	int segundoNumeroNatural = 3;
	char teste[] = "Teste1";
	int vetorNumeros[5] = {1,2,1,1,10};
	int qtdNumeros = 5;
	
	
	Exercicio01A(primeiroNumeroNatural,segundoNumeroNatural);
	Exercicio01B(teste);
	Exercicio01C(vetorNumeros, qtdNumeros);
	Exercicio01D(teste);
	
	return 0;

}

