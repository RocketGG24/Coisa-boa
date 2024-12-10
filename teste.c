#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CLIENTES 1000
#define MAX_MEDICOS 100
#define MAX_CONSULTAS 5000

typedef struct {
    int id;
    char nome[100];
    char morada[200];
    char email[100];
    int dataNascimento[11];
    int nif[10];
    int sns[10];
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

int numClientes = 0;
int numMedicos = 0;
int numConsultas = 0;

Cliente clientes[MAX_CLIENTES];
Medico medicos[MAX_MEDICOS];
Consulta consultas[MAX_CONSULTAS];


void InserirnovosClientes(int numClientes){
	if (numClientes >= MAX_CLIENTES) {
        printf("Erro: Limite m�ximo de clientes atingido.\n");
        return;
    }

    Cliente novoCliente;
    novoCliente.id = numClientes + 1;
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
    printf("NIF: ");
    fgets(novoCliente.nif, 10, stdin);
    strtok(novoCliente.nif, "\n");
    printf("SNS: ");
    fgets(novoCliente.sns, 10, stdin);
    strtok(novoCliente.sns, "\n");
    novoCliente.ativo = true;

    clientes[numClientes] = novoCliente;
    printf("Cliente inserido com sucesso! ID: %d\n", novoCliente.id);
}


void Alterardadosdecliente(Cliente clientes[], int total){
	int id, i, encontrado = 0;
	printf("Digite o Id do cliente que pretende alterar os dados: \n");
	scanf("%d", &id);
	
	//encontrar posicao array
	
	
	
	for (i = 0; i < total; i++){
		if (clientes[i].id == id){
			encontrado = 1;
			break;
		}
	}
	
	
	do {
		printf("\n Selecione o que deseja alterar \n");
		printf("1 -> Nome\n");
		printf("2 -> Morada\n");
		printf("3 -> Email\n");
		printf("4 -> Data de nascimento\n");
		printf("5 -> NIF\n");
		printf("6 -> SNS\n");
		printf("0 -> Voltar para Gest�o de Clientes\n");
		scanf("")
		
		switch(alteracaoCliente) {
			case 1:
				printf("Digite o novo nome do cliente: ");
    			scanf("%c\n", &clientes[i].nome);
				break;
			case 2:
				printf("Digite a nova morada do cliente: ");
				scanf("%d", &clientes[i].morada);
				break;
			case 3:
				printf("Digite o novo Email do cliente: ");
				scanf("%c", &clientes[i].email);
				break;
			case 4:
				printf("Digite a nova data de nascimento do cliente: ");
				scanf("%d", &clientes[i].dataNascimento);
				break;
			case 5:
				printf("Digite o novo NIF do cliente: ");
				scanf("%d", &clientes[i].nif);
				break;
			case 6:
				printf("Digite o novo SNS: ");
				scanf("%d", &clientes[i].sns);
				break;
			case 0: printf("Voltando para Gest�o de Clientes...");
			default: printf("Op��o inv�lida!\n");
		}
	} while (alteracaoCliente != 0)
	
	printf("Digite o novo nome do cliente: ");
    scanf("%c\n", &clientes[i].nome);
    
    printf("Digite a nova idade do cliente: ");
    scanf("%d", &clientes[i].morada);
    
    

    printf("Dados do cliente atualizados com sucesso!\n");
	
}
	
void ativarDesativarCliente();
	int id, i, encontrado = 0;

    printf("Digite o ID do cliente que deseja ativar/desativar: ");
    scanf("%d", &id);

    for (i = 0; i < total; i++) {
        if (clientes[i].id == id) {
            encontrado = 1; 
            break;          
        }
    }

    if (!encontrado) {
        printf("Cliente com ID %d n�o encontrado.\n", id);
        return;
    }

    if (clientes[i].ativo) {
        printf("O cliente com ID %d est� atualmente ATIVO.\n", id);
        printf("Deseja desativ�-lo? (1-Sim, 0-N�o): ");
    } else {
        printf("O cliente com ID %d est� atualmente DESATIVADO.\n", id);
        printf("Deseja ativ�-lo? (1-Sim, 0-N�o): ");
    }

    int opcao;
    scanf("%d", &opcao);

    if (opcao == 1) {
        clientes[i].ativo = !clientes[i].ativo; 
        if (clientes[i].ativo) {
            printf("O cliente com ID %d foi ATIVADO com sucesso.\n", id);
        } else {
            printf("O cliente com ID %d foi DESATIVADO com sucesso.\n", id);
        }
    } else {
        printf("Nenhuma altera��o foi feita no status do cliente.\n");
    }
}
void consultarCliente();
void listarClientesAtivos();
void procurarClientePorNome();

void menuPrincipal(Cliente){
	int opcaoCliente;
	do {
		printf("\n Gest�o de Clientes \n");
		printf("1 -> Inserir novos clientes \n");
		printf("2 -> Alterar dados de um cliente \n");
		printf("3 -> Ativar/desativar um cliente \n");
		printf("4 -> Consultar dados de um cliente \n");
		printf("5 -> Obter uma lista de clientes ativos \n");
		printf("6 -> Procurar um cliente pelo nome \n");
		printf("0 -> Voltar para menu principal \n");
		scanf("%d", &opcaoCliente);
		
		switch(opcaoCliente) {
			case 1: Inserirnovosclientes(); break;
			case 2:	Alterardadosdecliente(); break;
			case 3: Ativaroudesativarcliente(); break;
			case 4: Consultardadoscliente(); break;
			case 5: Obterlistaclientesativos(); break;
			case 6: Procurarclientepelonome(); break;
			case 0: printf("Voltando para o menu principal..."); 
			default: printf("Op��o inv�lida!\n");
		}
	} while (opcaoCliente != 0);
}

void menuClientes();
void menuMedicos();
void menuConsultas();

void limparBuffer();


int main() {
	Cliente clientes[1000];
	int totalClientes = 1;
	int opcao;
    do {
        printf("\n Cl�nica - Menu Principal \n");
        printf("1 -> Gest�o de Clientes\n");
        printf("2 -> Gest�o de M�dicos\n");
        printf("3 -> Gest�o de Consultas\n");
        printf("0 -> Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1: menuClientes(clientes, totalClientes); break;
            case 2: menuMedicos(); break;
            case 3: menuConsultas(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Op��o inv�lida!\n");
        }
    } while (opcao != 0);
	
	
	return 0;
}