#include <stdio.h> // biblioteca de comunicação com usuário
#include <stdlib.h> // biblioeca de alocação de espaço de memoria 
#include <locale.h> //biblioteca de alocação de linguagem por região (para o computador conseguir indentiicar acentos)
#include <string.h> // biblioteca responsavel pelas strings

int registro() // função responsavel por cadastrar o Usuário.
{

	// incio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação das variaveis/string
	
	printf("escreva o CPF a ser cadastrado :"); // coletando as informações do usuário
	scanf("%s",cpf); //  armazenando essa informção("%s" e referente a string)
	
	strcpy(arquivo,cpf); // serve para copiar os valores da string 
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");// cria o arquivo ("w" siguinifica escrever)
	fprintf(file,cpf); // vai salvar o valor da varivel dentro do aqruivo
	fclose(file); // vai fechar o arquivo
	
	
	file = fopen(arquivo, "a"); //\ "a" serve para atualizar
	fprintf(file,",");
	fclose(file);


	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser registrado :");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{	
	setlocale(LC_ALL,"portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado :");
	scanf("%s",cpf);
	
	FILE* file;
	file = fopen(cpf, "r"); // "r" read(ler)
	
	
	
	
	if (file == NULL) // se não encontrar o arquivo = null
	{
		printf("não foi possivel achar esse CPF.\n");
	}
	
	
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("essas são as informações do usuário:  ");
		printf("%s", conteudo);
		printf("\n\n");

	}
	
	system("pause");
	
	
	
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("digite o CPF do usuário a ser deletado :");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE* file;
	file=fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário nao encontrado.\n");
		system("pause");
		
	}
	
		
}



int main()


{
	int laco=1;
	int opcao=0;  // defenindo a variavel (INT= tipo inteiro)
	for (laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL,"portuguese"); // localizando para portugues para usar acentos etc
		printf("###Lista de Nomes EBAC ###\n\n"); // N\ serve para pular uma linha, para ficar mais facil o entedimento pro usuario
		printf("\tescolha uma das opções a seguir:\n\n"); // \T serve para dar espaço
		printf("\t1 - registrar nomes \n");
		printf("\t2 -consultar nomes \n");
		printf("\t3 - apagar nomes \n");
		printf("\t4 - Sair da tela de menu\n");
		printf("opção: ");

		scanf("%d", &opcao); // armazenando informações da varaivel( a escolha do usuário
	
		system("cls"); // serve para limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Obrigado por usar nosso sistema\n");
			return 0;
			break;
			
			default: // caso a opção não exista 
			printf("opção invalida \n");
			system("pause");
			break;
		}
	
	}
}
