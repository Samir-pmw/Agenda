#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//variável global
int n_contatos=0;
//structs
typedef struct{
    char nome[129];
    int id, telefone;
} Agenda;


int main()
{
    Agenda contatos[100]={0}; 
    int menu=0;
    
    
    do{
        printf("\n\n1) Inserir um novo contato\n");
        printf("2) Apagar um contato\n");
        printf("3) Buscar por um contato seja por telefone ou nome\n");
        printf("4) Listar os contatos\n");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                int contato_vago;
                for(int i=0;i<=n_contatos;i++){
                    if(contatos[i].id==-1){
                        n_contatos--;
                        contato_vago=i;
                        break;
                    }else if(i==n_contatos){
                        contato_vago=i;
                        break;
                    }
                }
                //nome contato
                do{
                    printf("\nQual o nome do contato? ");
                    scanf("%s", contatos[contato_vago].nome);
                } while(strlen(contatos[contato_vago].nome) < 0 || strlen(contatos[contato_vago].nome) > 128);
                contatos[contato_vago].id=contato_vago+1;
                //telefone
                int telefone_existente;
                do{
                    telefone_existente=0;
                    printf("\nQual é o telefone do contato? ");
                    scanf("%d", &telefone_existente);
                    for(int i=0; i<n_contatos; i++){
                        if(telefone_existente==contatos[i].telefone){
                            telefone_existente=1;
                        }
                    }
                }while(contatos[n_contatos].telefone>1000000000000000 || contatos[n_contatos].telefone<10000000 & telefone_existente==1);
                contatos[contato_vago].telefone=telefone_existente;
                printf("-----------resumo-----------\n");
                printf("Nome: %s\nId:%d\nTelefone: %d", contatos[contato_vago].nome, contatos[contato_vago].id, contatos[contato_vago].telefone);
                n_contatos++;
                menu=0;
                break;
            case 2:
                char entrada[129];
                printf("\nDigite os dados de alguém: ");
                scanf("%s", entrada);
                int quantidade_contatos=0;
                int id_final=100;
                double entrada_num=atoi(entrada);
                for(int i=0; i<n_contatos; i++){
                    if(entrada_num == contatos[i].telefone ||entrada_num == contatos[i].id||strcmp(entrada, contatos[i].nome)==0){
                        quantidade_contatos++;
                        printf("\n-----------------------------------");
                        id_final=contatos[i].id;
                        printf("\nNome: %s\nId:%d\nTelefone:%d", contatos[i].nome, contatos[i].id, contatos[i].telefone);
                    }
                }
                if(quantidade_contatos==0){
                    printf("\nNenhum conato encontrado.");
                }else if(quantidade_contatos==1){
                    printf("\nContato encontrado, deletando...");
                }else{
                    int entrada;
                    printf("\n%d contatos encontrados, deseja deletar qual deles? (use o id)\n", quantidade_contatos);
                    scanf("%d", &entrada);
                    for(int i=0; i<n_contatos; i++){
                        if(entrada == contatos[i].id){
                            printf("\n-----------------------------------");
                            id_final=contatos[i].id;
                            printf("\nNome: %s\nId: %d\nTelefone: %d", contatos[i].nome, contatos[i].id, contatos[i].telefone);
                            }
                    }
                }
                contatos[id_final-1].id=-1;
                
                menu=0;
                break;
            case 3:
                char pesquisa[129];
                printf("\nDigite os dados de alguém: ");
                scanf("%s", pesquisa);
                double pesquisa_num=atoi(pesquisa);
                for(int i=0; i<n_contatos; i++){
                    if(pesquisa_num == contatos[i].telefone||strcmp(pesquisa, contatos[i].nome)==0){
                        printf("\n-----------------------------------");
                        printf("\nNome: %s\nId: %d\nTelefone: %d", contatos[i].nome, contatos[i].id, contatos[i].telefone);
                    }
                }
                menu=0;
                break;
            case 4:
                for(int i=0; i<n_contatos; i++){
                    if(contatos[i].id>0){
                        printf("\n-----------------------------------");
                        printf("\nNome: %s\nId: %d\nTelefone: %d", contatos[i].nome, contatos[i].id, contatos[i].telefone);
                    }
                }
                menu=0;
                break;
        }
    }while(menu>4 || menu<1);

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