#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//variável global com o número do último contato/a quantidade 
int n_contatos = 0;

// struct da agenda
typedef struct {
    char nome[129];
    int id, telefone;
} Agenda;

// inserir novo contato
void inserir_contato(Agenda contatos[]) {
    int contato_vago;
    for (int i = 0; i <= n_contatos; i++) {
        if (contatos[i].id == -1) {
            n_contatos--;
            contato_vago = i;
            break;
        } else if (i == n_contatos) {
            contato_vago = i;
            break;
        }
    }
    // solicitar nome
    do {
        printf("\nQual o nome do contato? ");
        scanf("%s", contatos[contato_vago].nome);
    } while (strlen(contatos[contato_vago].nome) < 0 || strlen(contatos[contato_vago].nome) > 128);

    contatos[contato_vago].id = contato_vago + 1;

    // solicitar telefone
    int telefone_temp;
    int telefone_existente;
    do {
        telefone_existente = 0;
        printf("\nQual é o telefone do contato? ");
        scanf("%d", &telefone_temp);

        for (int i = 0; i < n_contatos; i++) {
            if (telefone_temp == contatos[i].telefone) {
                telefone_existente = 1;
            }
        }
    } while (telefone_temp > 1000000000000000 || telefone_temp < 10000000 || telefone_existente == 1);

    contatos[contato_vago].telefone = telefone_temp;

    // mostra resumo
    printf("------------resumo------------\n");
    printf("Nome: %s\nId:%d\nTelefone: %d", contatos[contato_vago].nome, contatos[contato_vago].id, contatos[contato_vago].telefone);

    n_contatos++;
}

// função para apagar 
void apagar_contato(Agenda contatos[]) {
    char entrada[129];
    printf("\nDigite os dados de alguém: ");
    scanf("%s", entrada);

    int quantidade_contatos = 0;
    int id_final = 100;
    double entrada_num = atoi(entrada);

    // procura contato
    for (int i = 0; i < n_contatos; i++) {
        if (entrada_num == contatos[i].telefone || entrada_num == contatos[i].id || strcmp(entrada, contatos[i].nome) == 0) {
            quantidade_contatos++;
            printf("\n-----------------------------------");
            id_final = contatos[i].id;
            printf("\nNome: %s\nId:%d\nTelefone:%d", contatos[i].nome, contatos[i].id, contatos[i].telefone);
        }
    }

    if (quantidade_contatos == 0) {
        printf("\nNenhum contato encontrado.");
    } else if (quantidade_contatos == 1) {
        printf("\nContato encontrado, deletando...");
    } else {
        int entrada_id;
        printf("\n%d contatos encontrados, deseja deletar qual deles? (use o id)\n", quantidade_contatos);
        scanf("%d", &entrada_id);
        for (int i = 0; i < n_contatos; i++) {
            if (entrada_id == contatos[i].id) {
                printf("\n-----------------------------------");
                id_final = contatos[i].id;
                printf("\nNome: %s\nId: %d\nTelefone: %d", contatos[i].nome, contatos[i].id, contatos[i].telefone);
            }
        }
    }

    // marca contato como -1(deixa inativo fi)
    contatos[id_final - 1].id = -1;
}

// função para buscar contato
void buscar_contato(Agenda contatos[]) {
    char pesquisa[129];
    printf("\nDigite os dados de alguém: ");
    scanf("%s", pesquisa);

    double pesquisa_num = atoi(pesquisa);

    for (int i = 0; i < n_contatos; i++) {
        if (pesquisa_num == contatos[i].telefone || strcmp(pesquisa, contatos[i].nome) == 0) {
            printf("\n-----------------------------------");
            printf("\nNome: %s\nId: %d\nTelefone: %d", contatos[i].nome, contatos[i].id, contatos[i].telefone);
        }
    }
}

// função para listar os trem 
void listar_contatos(Agenda contatos[]) {
    for (int i = 0; i < n_contatos; i++) {
        printf("\n-------------------------------");
        if (contatos[i].id > 0) { // só mostra contatos ativos
            printf("\nNome: %s\nId: %d\nTelefone: %d", contatos[i].nome, contatos[i].id, contatos[i].telefone);
        }
        
    }
}
//tudo organizadinho aqui embaixo
int main() {
    Agenda contatos[100] = {0};
    int menu = 0;

    do {
        printf("\n-------------MENU-------------");
        printf("\n1) Inserir um novo contato\n");
        printf("2) Apagar um contato\n");
        printf("3) Buscar por um contato seja por telefone ou nome\n");
        printf("4) Listar os contatos\n");
        printf("5) Sair\n");
        printf("Escolha: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                inserir_contato(contatos);
                menu = 0;
                break;
            case 2:
                apagar_contato(contatos);
                menu = 0;
                break;
            case 3:
                buscar_contato(contatos);
                menu = 0;
                break;
            case 4:
                listar_contatos(contatos);
                menu = 0;
                break;
            case 5:
                break;
        }
    } while (menu > 5 || menu < 1);

    return 0;
}
/*
  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⠛⣿⠀⠀⠀⠀⣤⣿⢻⡇⠀
⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⣤⣿⡛⠀⣤⣿⣿⣤⣤⣿⣿⣤⢸⡇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀  
⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡗⠀
⢠⣼⣿⣿⣿⣿⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷
⢸⣿⣿⡟⠛⠛⢿⣿⣿⣿⣿⣿⣿⣿⣤⣤⣤⣿⣿⣿⣿⣤⣤⣼⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠋⠀   

           █▀█ ▄▀█ █▀█ █ █▀█ █▀█    
           █▀▀ █▀█ █▀▀ █ █▀▄ █▄█    
*/
