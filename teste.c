#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include
#define MAX_CLIENTES 1000
#define MAX_MEDICOS 100
#define MAX_CONSULTAS 5000

typedef struct {
    int id;
    char nome[100];
    char morada[200];
    char email[100];
    char dataNascimento[11];
    int nif;
    int sns;
    bool ativo;   
} Cliente;

typedef struct {
    int id;
    char nome[100];
    char identificacaoProfissional[50];
    char especialidade[50];
    bool disponivel;
} Medico;

typedef struct {
    int id;
    char dataHora[20]; 
    int idMedico;
    int idCliente;
    char estado[15]; 
} Consulta;



Cliente clientes[MAX_CLIENTES];
Medico medicos[MAX_MEDICOS];
Consulta consultas[MAX_CONSULTAS];


void InserirnovosClientes(int numClientes){
	if (numClientes >= MAX_CLIENTES) {
        printf("Erro: Limite máximo de clientes atingido.\n");
        return;
    }

    Cliente novoCliente;
    novoCliente.id = numClientes + 1;
    
    fflush(stdin);
    printf("Inserir novo cliente\n");
    printf("Nome: ");
    fgets(novoCliente.nome, 100, stdin);
    strtok(novoCliente.nome, "\n"); 
    
    printf("Morada: ");
    fgets(novoCliente.morada, 200, stdin);
    strtok(novoCliente.morada, "\n");
    
    printf("Email: ");
    fgets(novoCliente.email, 100, stdin);
    strtok(novoCliente.email, "\n");
    
    printf("Data de nascimento (DD/MM/AAAA): ");
    fgets(novoCliente.dataNascimento, 11, stdin);
    strtok(novoCliente.dataNascimento, "\n");
    
    fflush(stdin);
    printf("NIF: ");
    scanf("%d", &novoCliente.nif);
    
    printf("SNS: ");
    scanf("%d", &novoCliente.sns);
    
    novoCliente.ativo = true;

    clientes[numClientes++] = novoCliente;
    printf("Cliente inserido com sucesso! ID: %d\n", novoCliente.id);	
}

/*int encontrarClientePorId(int id) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].nome == nomePesquisa) {
        	//imprimir dados do cliente
            return i;
        }
    }
    return -1; 
}
*/

void Alterardadosdecliente(int total){
	int id, i, opcaoalterardadosclientes;
	
	
	
	printf("Digite o Id do cliente que pretende alterar os dados: \n");
	scanf("%d", &id);
	

	do {
		printf("\n Selecione o que deseja alterar \n");
		printf("1 -> Nome\n");
		printf("2 -> Morada\n");
		printf("3 -> Email\n");
		printf("4 -> Data de nascimento\n");
		printf("5 -> NIF\n");
		printf("6 -> SNS\n");
		printf("0 -> Voltar para Gestão de Clientes\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcaoalterardadosclientes);
		
		switch(opcaoalterardadosclientes) {
			case 1:
				printf("Digite o novo nome do cliente: ");
    			scanf("%c\n", &clientes[id].nome);
    			printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 2:
				printf("Digite a nova morada do cliente: ");
				scanf("%d", &clientes[id].morada);
				printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 3:
				printf("Digite o novo Email do cliente: ");
				scanf("%c", &clientes[id].email);
				printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 4:
				printf("Digite a nova data de nascimento do cliente: ");
				scanf("%d", &clientes[id].dataNascimento);
				printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 5:
				printf("Digite o novo NIF do cliente: ");
				scanf("%d", &clientes[id].nif);
				printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 6:
				printf("Digite o novo SNS do cliente: ");
				scanf("%d", &clientes[id].sns);
				printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 0:
				printf("Voltando para Gestão de Clientes...");
				break;
			default: printf("Opção inválida!\n");
		}
	} while (opcaoalterardadosclientes != 0);
}
	
void AtivarouDesativarCliente();
void ConsultarDadosCliente();
void ObterListaClientesAtivos();
void ProcurarClientepeloNome();

void menuPrincipalClientes(int total, int numClientes){
	int opcaoCliente;
	do {
		printf("\n Gestão de Clientes \n");
		printf("1 -> Inserir novos clientes \n");
		printf("2 -> Alterar dados de um cliente \n");
		printf("3 -> Ativar/desativar um cliente \n");
		printf("4 -> Consultar dados de um cliente \n");
		printf("5 -> Obter uma lista de clientes ativos \n");
		printf("6 -> Procurar um cliente pelo nome \n");
		printf("0 -> Voltar para menu principal \n");
		printf("Escolha uma opção: ");
        scanf("%d", &opcaoCliente);
		
		switch(opcaoCliente) {
			case 1: 
				InserirnovosClientes(numClientes); 
				break;
			case 2:	
				Alterardadosdecliente(total); 
				break;
			case 3: 
				//AtivarouDesativarCliente(); 
				break;
			case 4: 
				//ConsultarDadosCliente(); 
				break;
			case 5: 
				//ObterListaClientesAtivos(); 
				break;
			case 6: 
				//ProcurarClientepeloNome(); 
				break;
			case 0: 
				printf("Voltando para o menu principal..."); 
				break;
			default: printf("Opção inválida!\n");
		}
	} while (opcaoCliente != 0);
}

void menuMedicos();
void menuConsultas();




int main() {
	int numClientes = 0;
	int numMedicos = 0;
	int numConsultas = 0;
	Cliente clientes[1000];
	
	int totalClientes = 0;
	int opcao;
    do {
        printf("\n Clínica - Menu Principal \n");
        printf("1 -> Gestão de Clientes\n");
        printf("2 -> Gestão de Médicos\n");
        printf("3 -> Gestão de Consultas\n");
        printf("0 -> Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
				menuPrincipalClientes(totalClientes, numClientes); 
				break;
            case 2: 
				//menuMedicos(); 
				break;
            case 3: 
				//menuConsultas(); 
				break;
            case 0: 
				printf("Saindo...\n"); 
				break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);
	
	
	return 0;
}
