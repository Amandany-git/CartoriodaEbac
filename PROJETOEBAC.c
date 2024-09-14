#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória		
#include <locale.h> // bliblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro () // nome, cpf, cargo
{
	char arquivo [50];
	char cpf [50];
	char nome [50];
	char sobrenome [50];
	char cargo [50];
	
	setlocale (LC_ALL, "Portuguese");
	
	
	printf("Informe o CPF a ser cadastrado: ");
	scanf ("%s", cpf);
	
	strcpy(arquivo, cpf); //Rsponsável por copiar os valores das strings
	
	FILE *file; //COMANDO para criar o arquivo -> CRIAR O ARQUIVO
	file = fopen (arquivo, "w"); // Abrir o arquivo e W de escrever -> CRIAR O ARQUIVO
	fprintf(file,cpf); // Salvo o valor da variável
	fclose(file); // Fecho o arquivo
	
	file = fopen(arquivo, "a"); // O "a" significa atualizar a informação
	fprintf(file, ",");
	fclose(file);
	
	printf("Informe o nome a ser cadastrado: ");
	scanf ("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf (file, nome);
	fclose (file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Informe o sobrenome a ser cadastrado: ");
	scanf ("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file, sobrenome);
	fclose (file);
		
	file = fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
		
	printf ("Informe o cargo a ser cadastrado: ");
	scanf ("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose (file);
		
	file = fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
}

int consulta ()
{
	char cpf [50];
	char conteudo [200];
	
	setlocale(LC_ALL, "Portuguese");
	
	
	printf("Informe um CPF a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE * file;
	file = fopen(cpf, "r");// "r" significa ler o arquivo
	
	if(file == NULL)
	{
		printf ("\n\n\ Arquivo não localizado! \n\n");
	}
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("Pause");
}

int deletar ()
{
	char cpf [50];
	
	printf("Informe o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove (cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	if (file==NULL)
	{
		printf("\n\n O usuário não se encontra cadastrado no sistema! \n\n");
		system("pause");
	}
	else
	{
		printf("\n\n Usuário deletado com SUCESSO! \n\n");
		system("pause");
	}
	
}

int main () // Função principal 
	{
	int opcao = 0; // Definindo as varáveis
	int laco = 1;
	
	for (laco=1; laco=1;)
	{
		
		system("cls"); 
		
		setlocale(LC_ALL, "Portuguese"); // Informando ao computador que está sendo feito em português e definindo a linguagem
	
		printf("### CARTÓRIO_E.B.A.C ###\n\n"); // Inicio do menu
		printf("Escolha a opção do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n"); 
		
		printf("Opção: ");// Fim do menu
		scanf("%d", &opcao); // Para armazenar uma variável do TIPO INTEIRO '%d' e para referenciar a variável, usa-se o & 
	
		system("cls"); // função de limpar a tela (Informações anteriores a tomada de decisão do usuário
	
		switch (opcao) // Não precisa colocar ; pois não é uma instrução/comando - Inicio das seleções
		{
			case 1:
			registro ();
			break;
			
			case 2:
			consulta ();
			break;
			
			case 3:
		 	deletar ();
			break;
			
			
			default:
			printf("A opção escolhida não está disponível! \n\n");
			system("Pause");
			break;
		}
	}
	printf("Esse software foi desenvolvido por Amanda Naomi Yoshitake \n");	
}
