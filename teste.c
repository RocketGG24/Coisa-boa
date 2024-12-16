#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>
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


void InserirnovosClientes(int *numClientes){
	if (*numClientes >= MAX_CLIENTES) {
        printf("Erro: Limite máximo de clientes atingido.\n");
        return;
    }

    Cliente novoCliente;
    novoCliente.id = *numClientes + 1;
    
    while (getchar() != '\n'); 
    
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

    clientes[*numClientes] = novoCliente;
    (*numClientes)++;
    printf("Cliente inserido com sucesso! ID: %d\n", novoCliente.id);	
}

int encontrarClientePorId(int id) {
    for (int i = 0; i < MAX_CLIENTES; i++) { 
        if (clientes[i].id == id) {  
            return i;                
        }
    }
    return -1; 
}


void Alterardadosdecliente(int total){
	int c, id, i, opcaoalterardadosclientes;
	
	
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
		while ((c = getchar()) != '\n' && c != EOF);
		scanf("%d", &opcaoalterardadosclientes);
		
		switch(opcaoalterardadosclientes) {
			case 1:
				printf("Digite o novo nome do cliente: ");
				while ((c = getchar()) != '\n' && c != EOF);
    			scanf("%s", clientes[id].nome);
    			printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 2:
				printf("Digite a nova morada do cliente: ");
				while ((c = getchar()) != '\n' && c != EOF);
				scanf("%d", &clientes[id].morada);
				printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 3:
				printf("Digite o novo Email do cliente: ");
				while ((c = getchar()) != '\n' && c != EOF);
				scanf("%s", clientes[id].email);
				printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 4:
				printf("Digite a nova data de nascimento do cliente: ");
				while ((c = getchar()) != '\n' && c != EOF);
				scanf("%d", &clientes[id].dataNascimento);
				printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 5:
				printf("Digite o novo NIF do cliente: ");
				while ((c = getchar()) != '\n' && c != EOF);
				scanf("%d", &clientes[id].nif);
				printf("Dados do cliente atualizados com sucesso!\n");
				break;
			case 6:
				printf("Digite o novo SNS do cliente: ");
				while ((c = getchar()) != '\n' && c != EOF);
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
	
void AtivarouDesativarCliente(int total, int numClientes){
    int id, i, encontrado = 0;

    printf("Digite o ID do cliente que deseja ativar ou desativar: ");
    scanf("%d", &id);

    for (i = 0; i < numClientes; i++) {
        if (clientes[i].id == id) {
            encontrado = 1; 
            break;          
        }
    }

    if (!encontrado) {
        printf("Cliente com ID %d não encontrado.\n", id);
        return;
    }

    if (clientes[i].ativo) {
        printf("O cliente com ID %d está atualmente ATIVO.\n", id);
        printf("Deseja desativá-lo? (1-Sim, 0-Não): ");
    } else {
        printf("O cliente com ID %d está atualmente DESATIVADO.\n", id);
        printf("Deseja ativá-lo? (1-Sim, 0-Não): ");
    }

    int escolha;
    scanf("%d", &escolha);

    if (escolha == 1) {
        clientes[i].ativo = !clientes[i].ativo; 
        if (clientes[i].ativo) {
            printf("O cliente com ID %d foi ATIVADO com sucesso.\n", id);
        } else {
            printf("O cliente com ID %d foi DESATIVADO com sucesso.\n", id);
        }
    } else {
        printf("Nenhuma alteração foi feita no status do cliente.\n");
    }
}

void ConsultarDadosCliente(int totalClientes) {
    int idProcurado, encontrado = 0;

    if (totalClientes == 0) {
        printf("Não existem clientes cadastrados.\n");
        return;
    }

    printf("Digite o ID do cliente que deseja consultar: ");
    scanf("%d", &idProcurado);

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == idProcurado) {
            encontrado = 1;
            printf("\nDados do Cliente\n");
            printf("ID: %d\n", clientes[i].id);
            printf("Nome: %s\n", clientes[i].nome);
            printf("Morada: %s\n", clientes[i].morada);
            printf("Email: %s\n", clientes[i].email);
            printf("Data de Nascimento: %s\n", clientes[i].dataNascimento);
            printf("NIF: %d\n", clientes[i].nif);
            printf("SNS: %d\n", clientes[i].sns);
            printf("Status: %s\n", clientes[i].ativo ? "Ativo" : "Inativo");
            return;
        }
    }

    if (!encontrado) {
        printf("Cliente com ID %d não encontrado.\n", idProcurado);
    }
}

void ObterListaClientesAtivos(int totalClientes) {
    if (totalClientes <= 0) {  
        printf("Não existem clientes cadastrados.\n");
        return;
    }

    int encontrouAtivos = 0; 

    printf("\nLista de Clientes Ativos\n");

    for (int i = 0; i < totalClientes; i++) {  
        if (clientes[i].ativo) {  
            encontrouAtivos = 1;
            printf("ID: %d\n", clientes[i].id);
            printf("Nome: %s\n", clientes[i].nome);
            printf("Morada: %s\n", clientes[i].morada);
            printf("Email: %s\n", clientes[i].email);
            printf("Data de Nascimento: %s\n", clientes[i].dataNascimento);
            printf("NIF: %d\n", clientes[i].nif);
            printf("SNS: %d\n", clientes[i].sns);
            printf("-----------------------------\n");
        }
    }

    if (!encontrouAtivos) { 
        printf("Nenhum cliente ativo encontrado.\n");
    }
}


void ProcurarClientepeloNome(int totalClientes) {
    if (totalClientes <= 0) {
        printf("Não existem clientes cadastrados.\n");
        return;
    }

    char nomeBusca[100];
    int encontrado = 0;

    printf("Digite o nome (ou parte do nome) do cliente que deseja procurar: ");
    while (getchar() != '\n');
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    strtok(nomeBusca, "\n");

    printf("\nResultados da Busca\n");

    for (int i = 0; i < totalClientes; i++) {
        char *ptrNomeCliente = clientes[i].nome;
        char *ptrBusca = nomeBusca;

        while (*ptrNomeCliente != '\0') {
            char *startCliente = ptrNomeCliente;
            char *startBusca = ptrBusca;

            while (*startBusca != '\0' && 
                   *startCliente != '\0' && 
                   ((*startCliente == *startBusca) || 
                    (*startCliente >= 'A' && *startCliente <= 'Z' && *startCliente + 32 == *startBusca) || 
                    (*startCliente >= 'a' && *startCliente <= 'z' && *startCliente - 32 == *startBusca))) {
                startCliente++;
                startBusca++;
            }

            if (*startBusca == '\0') {
                encontrado = 1;
                printf("ID: %d\n", clientes[i].id);
                printf("Nome: %s\n", clientes[i].nome);
                printf("Morada: %s\n", clientes[i].morada);
                printf("Email: %s\n", clientes[i].email);
                printf("Data de Nascimento: %s\n", clientes[i].dataNascimento);
                printf("NIF: %d\n", clientes[i].nif);
                printf("SNS: %d\n", clientes[i].sns);
                printf("Status: %s\n", clientes[i].ativo ? "Ativo" : "Inativo");
                printf("-----------------------------\n");
                break;
            }

            ptrNomeCliente++;
        }
    }

    if (!encontrado) {
        printf("Nenhum cliente encontrado com o nome '%s'.\n", nomeBusca);
    }
}
                                                                                  //adsadsahbshbvhfdvbfvkfvbkjsblfvibdivbdfkhvbfsjbvksbvksfdvbkfdhvbkdjvbkdsjvbksjhvbhdvbdf
void menuPrincipalClientes(int total, int *numClientes){
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
		
		switch (opcaoCliente) {
            case 1:
                InserirnovosClientes(numClientes);
                break;
            case 2:
                Alterardadosdecliente(total);
                break;
            case 3:
                AtivarouDesativarCliente(total, *numClientes);
                break;
            case 4:
                ConsultarDadosCliente(*numClientes);
                break;
            case 5:
                ObterListaClientesAtivos(*numClientes);
                break;
            case 6:
                ProcurarClientepeloNome(*numClientes);
                break;
            case 0:
                printf("Voltando para o menu principal...");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcaoCliente != 0);
}

void InserirNovosMedicos(Medico *medicos, int *numMedicos) {
    if (*numMedicos >= MAX_MEDICOS) {
        printf("Erro: Limite máximo de médicos atingido.\n");
        return;
    }

    Medico novoMedico;
    novoMedico.id = *numMedicos + 1;

    printf("Inserir novo médico\n");
    printf("Nome: ");
    while (getchar() != '\n');
    fgets(novoMedico.nome, sizeof(novoMedico.nome), stdin);
    strtok(novoMedico.nome, "\n");

    printf("Identificação Profissional: ");
    fgets(novoMedico.identificacaoProfissional, sizeof(novoMedico.identificacaoProfissional), stdin);
    strtok(novoMedico.identificacaoProfissional, "\n");

    printf("Especialidade: ");
    fgets(novoMedico.especialidade, sizeof(novoMedico.especialidade), stdin);
    strtok(novoMedico.especialidade, "\n");

    novoMedico.disponivel = true;
    medicos[*numMedicos] = novoMedico;
    (*numMedicos)++;

    printf("Médico inserido com sucesso! ID: %d\n", novoMedico.id);
}

void AlterarDadosMedico(Medico *medicos, int numMedicos) {
    int id;
    printf("Digite o ID do médico que deseja alterar: ");
    scanf("%d", &id);

    if (id <= 0 || id > numMedicos) {
        printf("Médico com ID %d não encontrado.\n", id);
        return;
    }

    int opcao;
    do {
        printf("\nAlterar Dados do Médico\n");
        printf("1 -> Nome\n");
        printf("2 -> Identificação Profissional\n");
        printf("3 -> Especialidade\n");
        printf("0 -> Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        while (getchar() != '\n');
        switch (opcao) {
            case 1:
                printf("Digite o novo nome: ");
                fgets(medicos[id - 1].nome, sizeof(medicos[id - 1].nome), stdin);
                strtok(medicos[id - 1].nome, "\n");
                printf("Nome atualizado com sucesso!\n");
                break;
            case 2:
                printf("Digite a nova identificação profissional: ");
                fgets(medicos[id - 1].identificacaoProfissional, sizeof(medicos[id - 1].identificacaoProfissional), stdin);
                strtok(medicos[id - 1].identificacaoProfissional, "\n");
                printf("Identificação profissional atualizada com sucesso!\n");
                break;
            case 3:
                printf("Digite a nova especialidade: ");
                fgets(medicos[id - 1].especialidade, sizeof(medicos[id - 1].especialidade), stdin);
                strtok(medicos[id - 1].especialidade, "\n");
                printf("Especialidade atualizada com sucesso!\n");
                break;
            case 0:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

void MarcarDisponibilidadeMedico(Medico *medicos, int numMedicos) {
    int id;
    printf("Digite o ID do médico que deseja alterar a disponibilidade: ");
    scanf("%d", &id);

    if (id <= 0 || id > numMedicos) {
        printf("Médico com ID %d não encontrado.\n", id);
        return;
    }

    medicos[id - 1].disponivel = !medicos[id - 1].disponivel;
    printf("Médico com ID %d agora está %s.\n", id, medicos[id - 1].disponivel ? "disponível" : "indisponível");
}

void ConsultarDadosMedico(Medico *medicos, int numMedicos) {
    int id;
    printf("Digite o ID do médico que deseja consultar: ");
    scanf("%d", &id);

    if (id <= 0 || id > numMedicos) {
        printf("Médico com ID %d não encontrado.\n", id);
        return;
    }

    printf("\nDados do Médico\n");
    printf("ID: %d\n", medicos[id - 1].id);
    printf("Nome: %s\n", medicos[id - 1].nome);
    printf("Identificação Profissional: %s\n", medicos[id - 1].identificacaoProfissional);
    printf("Especialidade: %s\n", medicos[id - 1].especialidade);
    printf("Disponibilidade: %s\n", medicos[id - 1].disponivel ? "Disponível" : "Indisponível");
}

void ListarTodosMedicos(Medico *medicos, int numMedicos) {
    printf("\nLista de Todos os Médicos\n");
    for (int i = 0; i < numMedicos; i++) {
        printf("ID: %d, Nome: %s, Especialidade: %s, Disponibilidade: %s\n",
               medicos[i].id, medicos[i].nome, medicos[i].especialidade,
               medicos[i].disponivel ? "Disponível" : "Indisponível");
    }
}

void ListarMedicosDisponiveis(Medico *medicos, int numMedicos) {
    printf("\nLista de Médicos Disponíveis\n");
    for (int i = 0; i < numMedicos; i++) {
        if (medicos[i].disponivel) {
            printf("ID: %d, Nome: %s, Especialidade: %s\n",
                   medicos[i].id, medicos[i].nome, medicos[i].especialidade);
        }
    }
}

void ListarMedicosPorEspecialidade(Medico *medicos, int numMedicos) {
    char especialidade[50];
    printf("Digite a especialidade desejada: ");
    while (getchar() != '\n');
    fgets(especialidade, 50, stdin);
    strtok(especialidade, "\n");

    printf("\nLista de Médicos por Especialidade: %s\n", especialidade);
    for (int i = 0; i < numMedicos; i++) {
        if (strcmp(medicos[i].especialidade, especialidade) == 0) {
            printf("ID: %d, Nome: %s, Disponibilidade: %s\n",
                   medicos[i].id, medicos[i].nome,
                   medicos[i].disponivel ? "Disponível" : "Indisponível");
        }
    }
}

void ProcurarMedicoPeloNome(Medico *medicos, int numMedicos) {
    char nomeBusca[100];
    printf("Digite o nome (ou parte do nome) do médico: ");
    while (getchar() != '\n');
    fgets(nomeBusca, 100, stdin);
    strtok(nomeBusca, "\n");

    printf("\nResultados da Busca\n");
    for (int i = 0; i < numMedicos; i++) {
        if (strstr(medicos[i].nome, nomeBusca) != NULL) {
            printf("ID: %d, Nome: %s, Especialidade: %s, Disponibilidade: %s\n",
                   medicos[i].id, medicos[i].nome, medicos[i].especialidade,
                   medicos[i].disponivel ? "Disponível" : "Indisponível");
        }
    }
}

void menuMedicos(int *numMedicos) {
    int opcao;
    
    do {
        printf("\nGestão de Médicos\n");
        printf("1 -> Inserir novos médicos\n");
        printf("2 -> Alterar dados de um médico\n");
        printf("3 -> Marcar médico como disponível ou indisponível\n");
        printf("4 -> Consultar dados de um médico\n");
        printf("5 -> Listar todos os médicos\n");
        printf("6 -> Listar médicos disponíveis\n");
        printf("7 -> Listar médicos por especialidade\n");
        printf("8 -> Procurar médico pelo nome\n");
        printf("0 -> Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                InserirNovosMedicos(medicos, numMedicos);
                break;
            case 2:
                AlterarDadosMedico(medicos, *numMedicos);
                break;
            case 3:
                MarcarDisponibilidadeMedico(medicos, *numMedicos);
                break;
            case 4:
                ConsultarDadosMedico(medicos, *numMedicos);
                break;
            case 5:
                ListarTodosMedicos(medicos, *numMedicos);
                break;
            case 6:
                ListarMedicosDisponiveis(medicos, *numMedicos);
                break;
            case 7:
                ListarMedicosPorEspecialidade(medicos, *numMedicos);
                break;
            case 8:
                ProcurarMedicoPeloNome(medicos, *numMedicos);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

int idsMedicos[MAX_CONSULTAS]; 
int idsClientes[MAX_CONSULTAS];
time_t datasHora[MAX_CONSULTAS];

bool VerificarSobreposicaoConsulta(char *dataHora, int idMedico, int idCliente, Consulta *consultas, int numConsultas) {
    for (int i = 0; i < numConsultas; i++) {
        if (consultas[i].idMedico == idMedico && consultas[i].idCliente == idCliente && strcmp(consultas[i].dataHora, dataHora) == 0) {
            return true;
        }
    }
    return false;
}

void AgendarConsulta() {
    int idMedico, idCliente;
    char dataHora[20];

    printf("Digite o ID do médico: ");
    scanf("%d", &idMedico);

    if (idMedico <= 0 || idMedico > MAX_MEDICOS) {
        printf("Médico inválido!\n");
        return;
    }

    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);

    if (idCliente <= 0 || idCliente > MAX_CLIENTES || !clientes[idCliente - 1].ativo) {
        printf("Cliente inválido ou não ativo!\n");
        return;
    }

    printf("Digite a data e hora da consulta (formato: dd/mm/aaaa hh:mm): ");
    scanf("%s", dataHora);

    if (VerificarSobreposicaoConsulta(dataHora, idMedico, idCliente, consultas, MAX_CONSULTAS)) {
        printf("Já existe uma consulta agendada para esse horário.\n");
        return;
    }

    int idConsulta = 0;
    while (consultas[idConsulta].id != 0 && idConsulta < MAX_CONSULTAS) {
        idConsulta++;
    }

    if (idConsulta >= MAX_CONSULTAS) {
        printf("Número máximo de consultas alcançado.\n");
        return;
    }

    consultas[idConsulta].id = idConsulta + 1;
    consultas[idConsulta].idMedico = idMedico;
    consultas[idConsulta].idCliente = idCliente;
    strcpy(consultas[idConsulta].dataHora, dataHora);
    strcpy(consultas[idConsulta].estado, "Agendada");

    printf("Consulta agendada com sucesso!\n");
}

void DesmarcarConsulta(Consulta *consultas, int numConsultas) {
    int idConsulta;
    printf("Digite o ID da consulta que deseja desmarcar: ");
    scanf("%d", &idConsulta);

    if (idConsulta <= 0 || idConsulta > numConsultas || consultas[idConsulta - 1].id == 0) {
        printf("Consulta não encontrada ou já desmarcada!\n");
        return;
    }

    strcpy(consultas[idConsulta - 1].estado, "Desmarcada");
    printf("Consulta com ID %d foi desmarcada com sucesso!\n", idConsulta);
}

void MarcarConsultaComoRealizada(int numConsultas) {
    int idConsulta;
    printf("Digite o ID da consulta para marcar como realizada: ");
    scanf("%d", &idConsulta);

    if (idConsulta <= 0 || idConsulta > numConsultas) {
        printf("Consulta não encontrada!\n");
        return;
    }

    strcpy(consultas[idConsulta - 1].estado, "Realizada");
    printf("Consulta marcada como realizada!\n");
}

void AtualizarConsulta(int numConsultas, Consulta *consultas) {
    int idConsulta;
    printf("Digite o ID da consulta para atualizar: ");
    scanf("%d", &idConsulta);

    if (idConsulta <= 0 || idConsulta > numConsultas) {
        printf("Consulta não encontrada!\n");
        return;
    }

    int opcao;
    do {
        printf("\n1 -> Alterar data e hora\n");
        printf("2 -> Alterar médico\n");
        printf("0 -> Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char novaDataHora[20];
                printf("Digite a nova data e hora da consulta (formato: dd/mm/aaaa hh:mm): ");
                scanf("%s", novaDataHora);

                if (VerificarSobreposicaoConsulta(novaDataHora, consultas[idConsulta - 1].idMedico, consultas[idConsulta - 1].idCliente, consultas, numConsultas)) {
                    printf("Já existe uma consulta agendada para esse horário.\n");
                    break;
                }

                strcpy(consultas[idConsulta - 1].dataHora, novaDataHora);
                printf("Data e hora da consulta alteradas com sucesso!\n");
                break;
            }
            case 2: {
                int idMedico;
                printf("Digite o novo ID do médico: ");
                scanf("%d", &idMedico);

                if (idMedico <= 0 || idMedico > MAX_MEDICOS) {
                    printf("Médico inválido!\n");
                    break;
                }

                consultas[idConsulta - 1].idMedico = idMedico;
                printf("Médico da consulta alterado com sucesso!\n");
                break;
            }
            case 0:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

void ListarConsultasDiaAtual(Consulta *consultas, int numConsultas) {
    time_t t = time(NULL);
    struct tm tmAtual = *localtime(&t);

    char dataAtual[11];
    snprintf(dataAtual, sizeof(dataAtual), "%02d/%02d/%04d", tmAtual.tm_mday, tmAtual.tm_mon + 1, tmAtual.tm_year + 1900);

    printf("\nConsultas para o dia %s:\n", dataAtual);

    int encontrou = 0;
    for (int i = 0; i < numConsultas; i++) {
        if (strcmp(consultas[i].dataHora, dataAtual) == 0) {
            printf("ID Consulta: %d\n", consultas[i].id);
            printf("Médico ID: %d\n", consultas[i].idMedico);
            printf("Cliente ID: %d\n", consultas[i].idCliente);
            printf("Estado: %s\n", consultas[i].estado);
            printf("--------------------\n");
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Não há consultas agendadas para hoje.\n");
    }
}

void ExibirConsultas(int numConsultas) {
    for (int i = 0; i < numConsultas; i++) {
        printf("Consulta ID: %d\n", consultas[i].id);
        printf("Data e Hora: %s\n", consultas[i].dataHora);
        printf("Médico ID: %d\n", consultas[i].idMedico);
        printf("Cliente ID: %d\n", consultas[i].idCliente);
        printf("Estado: %s\n", consultas[i].estado);
        printf("--------------------\n");
    }
}

void ObterHistoricoConsultasPorCliente(int numConsultas) {
    int idCliente;
    printf("Digite o ID do cliente para obter o histórico de consultas: ");
    scanf("%d", &idCliente);

    if (idCliente <= 0 || idCliente > MAX_CLIENTES || !clientes[idCliente - 1].ativo) {
        printf("Cliente inválido ou não ativo!\n");
        return;
    }

    printf("\nHistórico de Consultas do Cliente:\n");

    int encontrado = 0;
    for (int i = 0; i < numConsultas; i++) {
        if (consultas[i].idCliente == idCliente) {
            printf("ID Consulta: %d, Médico: %s, Data e Hora: %s, Estado: %s\n",
                   consultas[i].id, 
                   medicos[consultas[i].idMedico - 1].nome, 
                   consultas[i].dataHora,
                   consultas[i].estado);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhuma consulta encontrada para o cliente com ID %d.\n", idCliente);
    }
}

void menuConsultas(Medico *medicos, int numMedicos, Cliente *clientes, int numClientes, Consulta *consultas, int numConsultas) {
    int opcao;

    do {
        printf("\nGestão de Consultas\n");
        printf("1 -> Agendar nova consulta\n");
        printf("2 -> Desmarcar uma consulta\n");
        printf("3 -> Marcar consulta como realizada\n");
        printf("4 -> Atualizar uma consulta\n");
        printf("5 -> Listar consultas para o dia de hoje\n");
        printf("6 -> Obter histórico de consultas por cliente\n");
        printf("0 -> Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                AgendarConsulta();
                break;
            case 2:
                DesmarcarConsulta(consultas, numConsultas);
                break;
            case 3:
                MarcarConsultaComoRealizada(numConsultas);
                break;
            case 4:
                AtualizarConsulta(numConsultas, consultas);
                break;
            case 5:
                ListarConsultasDiaAtual(consultas, numConsultas);
                break;
            case 6:
                ObterHistoricoConsultasPorCliente(numConsultas);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

int main() {
	int numClientes = 0;
	int numMedicos = 0;
	int numConsultas = 0;
	Cliente clientes[1000];
	Medico medicos[100];
	Consulta consultas[5000];
	int idMedicos[100], idClientes[100];
    time_t dataHoras[100];
	int totalClientes = 0;
	int opcao;

	setlocale(LC_ALL, "Portuguese");
	
    do {
        printf("\n Clínica - Menu Principal \n");
        printf("1 -> Gestão de Clientes\n");
        printf("2 -> Gestão de Médicos\n");
        printf("3 -> Gestão de Consultas\n");
        printf("0 -> Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch(opcao) {
            case 1:
				menuPrincipalClientes(totalClientes, &numClientes); 
				break;
            case 2: 
				menuMedicos(&numMedicos); 
				break;
            case 3: 
				menuConsultas(medicos, numMedicos, clientes, numClientes, consultas, numConsultas);
				break;
            case 0: 
				printf("Saindo...\n"); 
				break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);
	
	
	return 0;
}
