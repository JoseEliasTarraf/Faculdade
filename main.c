#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 100

struct usuarios_infos {
    char login[10];
    char senha[10];
    char id[5];
};

struct usuarios_infos usuario_cadastrado, *lista_de_contas;

struct Estoque{
    char nome[30];
    int quantidade;
    float preco;
};

struct Estoque estoque[MAX];

int menu;

int main()
{
     setlocale(LC_ALL, "Portuguese");

    system("cls");
    int opcao,functions,sn,quantidade,count = 0;
    puts("*********PIM*********");
    telaLogin();
    system("cls");
    puts("*********FUNÇÂO*********");
    puts("[1]FUNCIONARIO");
    puts("[2]GERENTE");
    puts("[3]CHEFE");
    scanf("%d",&functions);
  if(functions == 1){
    do{
            system("cls");
        menuFuncionario();
        scanf("%d",&opcao);
    switch(opcao){
    do{
         case 1:
            system("cls");
            menuEstoque();
            scanf("%d",&menu);
            break;
    }while(menu != 0);
    do{
        case 2:
            system("cls");
            perfil();
            scanf("%d",&menu);
            break;
    }while(menu != 0);
    }
    }while(opcao !=0);
  }
  else if (functions == 2){
    menuGerente();
    scanf("%d",&opcao);
    do{
        switch(opcao){
    do{
        case 1:
        system("cls");
        puts("Funções");
        puts("[]Funcionario");
        puts("[X]Gerente");
        puts("[]Chefe");
        puts("SAIR[0]:");
        scanf("%d",&menu);
        break;
    }while(menu !=0);
        do{
            case 2:
            system("cls");
            perfil();
            puts("SAIR[0]:");
            scanf("%d",&sn);
        }while(sn !=0);
        do{
            case 3:
                system("cls");
                puts("******ESTOQUE*****\n");
                puts("[1]Registrar no Estoque\n");
                puts("[2]Listar Estoque\n");
                puts("[0]SAIR\n");
                puts("MENU:");
                scanf("%d",&menu);
                switch(menu){
                do{
                    case 1:
                    system("cls");
                    puts("Digite quantos produtos deseja Registrar:");
                    scanf("%d",&quantidade);
                    for(int i = 0; i<quantidade;i++){
                        system("cls");
                        puts("Nome do Produto:");
                        scanf("%s",&estoque[i].nome);
                        puts("Digite a Quantidade no Estoque:");
                        scanf("%d",&estoque[i].quantidade);
                        puts("Digite o Preço:");
                        scanf("%f",&estoque[i].preco);
                        count++;
                    }
                    puts("[0]SAIR:");
                    scanf("%d",&sn);
                }while(sn !=0);
                    do{
                        case 2:
                        system("cls");
                        puts("Lista de Produtos");
                        for(int i = 0 ; i <count;i++){
                            printf("NOME:%s\n",estoque[i].nome);
                            printf("QUANTIDADE:%d\n",estoque[i].quantidade);
                            printf("PREÇO:%f\n",estoque[i].preco);
                            puts("--------------------------------------\n");
                        }
                        puts("[0]SAIR:");
                        scanf("%d",&sn);
                        break;
                    }while(sn != 0);
                }while(menu !=0);
        }while(menu != 0);
    }
    }while(opcao !=0);
  }
  else{
    CHEFE();
  }
}
