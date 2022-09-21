#include <stdio.h>
#include <stdlib.h>
#define MAX (100)

// Gerenciamento de uma Agencia de Veiculo

// Utilizar Funcoes, Clean Code
// Cadastrar 
// Listar 
// Localizar

struct veiculoType {
    char placa[MAX];
    int anoFabricado;
    char marca[MAX];
    char modelo[MAX];
    char cor[MAX];
    int valorVenda;
};

typedef struct veiculoType veiculo;

void criarVeiculo( veiculo * car, char * placa, char * marca, char * modelo, int anoFabricado, char * cor, int valorVenda )
{
    strncpy( car->placa, placa, MAX );
    strncpy( car->marca, marca, MAX );
    strncpy( car->modelo, modelo, MAX );
    car->anoFabricado = anoFabricado;
    strncpy( car->cor, cor, MAX );
    car->valorVenda = valorVenda;
}


void exibirMenu(){
	printf("\n------------------ [MENU] ------------------\n");
	printf("[1] - Cadastrar novo Veículo\n");
	printf("[2] - Listar Veículos\n");
	printf("[3] - Buscar Veículo por Placa\n");
	printf("[4] - Buscar Veículo por Ano de Fabricação\n");
	printf("[0] - Sair\n\n");
	printf("Digite a opcao desejada: ");
}



int main(void)
{
	int qtdCarros = 5;
	 /* Cria array de carros */
    veiculo *veiculos = calloc( qtdCarros, sizeof(veiculo) );
    
    int sair = 0;
    int resposta;
    int qtdCarrosInseridos = 0;
    
    while(sair == 0){
    	exibirMenu();
    	scanf("%d", &resposta);
    
	    if(resposta == 0 ){
	    	sair = 1;
	    	break;
		}
	    if(resposta == 1){
	    	if(qtdCarrosInseridos == qtdCarros){
	    		
	    		int adicionarMais = 0;
	    		printf("Voce atingiu o numero maximo de alocacao, quantos carros mais voce deseja adicionar?");
	    		scanf("%d", adicionarMais);
	    		
	    		veiculo *veiculos = realloc(adicionarMais, sizeof(veiculo));
	    		qtdCarros = adicionarMais + qtdCarros;
	    		
			}
			qtdCarrosInseridos++;
			printf("Voce esta adicionando o veiculo na casa [%d]", qtdCarrosInseridos);
			
	    	printf("Digite a placa:");
	    	scanf("%s", veiculos[qtdCarrosInseridos].placa);
	    	printf("Digite o ano de fabricacao:");
	    	scanf("%d", &veiculos[qtdCarrosInseridos].anoFabricado);
	    	printf("Digite a marca:");
	    	scanf("%s", veiculos[qtdCarrosInseridos].marca);
	    	printf("Digite o modelo:");
	    	scanf("%s", veiculos[qtdCarrosInseridos].modelo);
	    	printf("Digite a cor:");
	    	scanf("%s", veiculos[qtdCarrosInseridos].cor);
	    	printf("Digite o preco de venda:");
	    	scanf("%d", &veiculos[qtdCarrosInseridos].valorVenda);
	    	
	    	
	    	
	    	printf("Veiculo inserido com sucesso!\n");
	    	printf("----------------------------------");
		}
		
		if(resposta == 2){
			int i =1;
			for(i; i <= qtdCarrosInseridos; i++){
				printf("[%d] - PLACA: %s - ANO FAB: %d - MARCA: %s - MODELO: %s - COR: %s - PRECO DE VENDA: %d\n", i, veiculos[i].placa, veiculos[i].anoFabricado, veiculos[i].marca, veiculos[i].modelo, veiculos[i].cor, veiculos[i].valorVenda);
			}
		}
		
		if(resposta == 3){
			char buscarPlaca[MAX];
			printf("Digite a placa: ");
			scanf("%s", buscarPlaca);
		}
	}
	
	// Incompleto
    
    
    
    
    

	return 0;

}
