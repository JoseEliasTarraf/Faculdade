#include <stdio.h>
#include<locale.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

int count = 0,i = 0;

struct usuarios_infos  {
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

void menuFuncionario(){
        setlocale(LC_ALL, "Portuguese");
        system("chcp 65001");
        system("cls");
        printf("*************************************\n\n");
        printf("************PROGRAMA PIM*************\n\n");
        printf("*************************************\n\n");
        printf("[1] Lista de Estoque\n");
        printf("[2] Perfil \n");
        printf("[3] Presen�a\n");
        printf("[4] Lista de Tarefas\n");
        printf("[0] Sair \n");
        printf("Menu:");
}

void telaLogin(){
    int total_contas = 0, arq_tamanho = 0, op = 0, i;

    FILE *logs;

    while (op != 3)
    {
        printf("\n[1]Cadastrar nova conta\n");
        printf("[2]Fazer login\n");

        printf("\nOpcao: ");
        scanf("%d%*c", &op);

        switch(op){
            case 1:
                system("cls");
                logs = fopen ("C:\\Users\\Nasko\\Desktop\\Arquivos\\contas.txt","a");
                if(logs == NULL)
                {
                    printf("\nErro ao tentar abrir o arquivo.\n\n");
                }
                else
                {
                    puts("********CADASTRO********");
                    memset(&usuario_cadastrado,0,sizeof(struct usuarios_infos));
                    printf("Cadastrar usuario: ");
                    scanf("%s", usuario_cadastrado.login);
                    printf("Cadastrar senha: ");
                    scanf("%s", usuario_cadastrado.senha);
                    fwrite(&usuario_cadastrado, sizeof usuario_cadastrado, 1, logs);
                    fclose(logs);
                }
                break;

            case 2:
                system("cls");
                memset(&usuario_cadastrado, 0, sizeof(struct usuarios_infos));
                printf("LOGIN: ");
                scanf("%s", usuario_cadastrado.login);
                printf("SENHA: ");
                scanf("%s", usuario_cadastrado.senha);

                logs = fopen ("C:\\Users\\Nasko\\Desktop\\Arquivos\\contas.txt","r");
                if(logs == NULL)
                {
                    printf("\nErro ao tentar abrir o arquivo.\n\n");
                }
                else
                {
                    fseek(logs,0,SEEK_END);
                    arq_tamanho = ftell(logs);
                    total_contas = arq_tamanho / sizeof (struct usuarios_infos);
                    rewind(logs);
                    lista_de_contas = malloc(arq_tamanho);
                    if(fread(lista_de_contas, sizeof usuario_cadastrado, total_contas, logs) != total_contas)
                    {
                        printf("Falha ao tentar ler contas\n");
                        fclose(logs);
                        free(lista_de_contas);
                        return 1;
                    }
                    fclose(logs);
                    for (i=0; i<total_contas; i++){
                        if(memcmp(&usuario_cadastrado, &lista_de_contas[i], sizeof(struct usuarios_infos)) == 0)
                        {
                            printf("\n LOGADO COM SUCESSO\n");
                            break;
                        }
                    }
                    if(i == total_contas)
                    {
                        printf("\n NEGADO\n");
                        exit(0);
                    }
                    free(lista_de_contas);
                }
                break;

            case 3:
                break;

            default:
                printf("\n Opcao invalida!\n");
        }
        return 0;
    }

}

void registroEstoque(){
	int cad;
	printf("Quantos componentes deseja registrar:");
    scanf("%d",&cad);
        for(i = 0; i < cad; i++){
        printf("NOME:");
        scanf("%s",&estoque[i].nome);
        printf("QUANTIDADE:");
        scanf("%s",&estoque[i].quantidade);
        printf("PREÇO:");
        scanf("%d",&estoque[i].preco);
        count++;
        system("cls");
	}
}

void menuEstoque(){
            int op;
            FILE *est;

            est = fopen("C:\\Users\\Nasko\\Desktop\\Arquivos\\estoque.txt","r");

            system("cls");
            printf("********************************\n\n");
            printf("************ESTOQUE*************\n\n");
            printf("********************************\n\n");
            puts("[1]Registar no Estoque");
            puts("[2]Listar Estoque");
            puts("MENU:");
            scanf("%d",&op);
            switch(op){
            case 1:
                registroEstoque();
                break;
            case 2:
                puts("**********LISTA ESTOQUE********");
                for(i = 0; i<count;i++){
                    printf("NOME:%s\n",estoque[i].nome);
                    printf("QUANTIDADE:%d",estoque[i].quantidade);
                    printf("PREÇO:%f",estoque[i].preco);
                    puts("--------------------------");
                }
                break;
            }
}

void perfil(){
    setlocale(LC_ALL, "Portuguese");
    puts("*********PERFIL*********");
    printf("CONECTADO : %s\n",usuario_cadastrado.login);
    printf("FUNÇÃO: %s\n",usuario_cadastrado.id);
    printf("Presença : 0\n");
}

void menuGerente(){
        setlocale(LC_ALL, "Portuguese");
        printf("***********************************\n\n");
        printf("************GERENCIA*************\n\n");
        printf("***********************************\n\n");
        printf("[1] Lista de Funções\n");
        printf("[2] Perfil \n");
        printf("[3] Estoque\n");
        printf("[4] Entregas\n");
        printf("[0] Sair \n");
        printf("Menu:");
}

void CHEFE(){
 int opcao,qtd,salarioF,salarioG;
 char nome[20];
 FILE *ler;
    do
    {
        system("cls");
        printf("*************************************\n\n");
        printf("************PROGRAMA PIM*************\n\n");
        printf("*************************************\n\n");
        printf("[1] Registro de Funcionarios \n");
        printf("[2] Lista de Salarios \n");
        printf("[0] Sair \n");
        printf("Menu:");
        scanf("%d",&menu);
        switch (menu){
            do{
        case 1:
             system("cls");
             printf("********************************************************\n\n");
             printf("************REGISTRO DE FUNCIONARIO*************\n\n");
             printf("*******************************************************\n\n");
             printf("Digite a quantidade: ");
             scanf("%d", &qtd);
                for(int i = 0;i < qtd; i++){
                    ler = fopen("C:\\Users\\Nasko\\Desktop\\Arquivos\\contas.txt","a");
                    printf("Digite o Login: ");
                    scanf("%s",&usuario_cadastrado.login);
                    printf("Digite a Senha");
                    scanf("%s",&usuario_cadastrado.senha);
                    fclose(ler);
                }
                printf("Deseja continuar?: \n");
                printf("[1]Sim / [0]Nao \n");
                scanf("%d", &opcao);
            }while (opcao != 0);
        case 2:
            system("cls");
            printf("********************************\n\n");
            printf("************LISTA DE SALARIOS*************\n\n");
            printf("********************************\n\n");
            printf("Escolha a funcao: \n");
            printf("[1]Funcionario / [2]Gerente:");
            scanf("%d",&menu);
             switch (menu){
               do{
                case 1:
                    printf("Salario do Funcionario: ");
                    scanf("%d", &salarioF);
                    printf("[0]SAIR: \n");
                    scanf(" %d", &opcao);
                    break;
               }while (opcao != 0);
               do{
                case 2:
                    printf("Salario do Gerente: ");
                    scanf("%d", &salarioG);
                    printf("[0]SAIR: \n");
                    scanf(" %d", &opcao);
                    break;
               }while (opcao != 0);
        }
    } while (opcao != 0);
}while (menu != 0);
}
