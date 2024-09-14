#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria		
#include <locale.h> // bliblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

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
	
	strcpy(arquivo, cpf); //Rspons�vel por copiar os valores das strings
	
	FILE *file; //COMANDO para criar o arquivo -> CRIAR O ARQUIVO
	file = fopen (arquivo, "w"); // Abrir o arquivo e W de escrever -> CRIAR O ARQUIVO
	fprintf(file,cpf); // Salvo o valor da vari�vel
	fclose(file); // Fecho o arquivo
	
	file = fopen(arquivo, "a"); // O "a" significa atualizar a informa��o
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
		printf ("\n\n\ Arquivo n�o localizado! \n\n");
	}
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("Pause");
}

int deletar ()
{
	char cpf [50];
	
	printf("Informe o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove (cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	if (file==NULL)
	{
		printf("\n\n O usu�rio n�o se encontra cadastrado no sistema! \n\n");
		system("pause");
	}
	else
	{
		printf("\n\n Usu�rio deletado com SUCESSO! \n\n");
		system("pause");
	}
	
}

int main () // Fun��o principal 
	{
	int opcao = 0; // Definindo as var�veis
	int laco = 1;
	
	for (laco=1; laco=1;)
	{
		
		system("cls"); 
		
		setlocale(LC_ALL, "Portuguese"); // Informando ao computador que est� sendo feito em portugu�s e definindo a linguagem
	
		printf("### CART�RIO_E.B.A.C ###\n\n"); // Inicio do menu
		printf("Escolha a op��o do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n"); 
		
		printf("Op��o: ");// Fim do menu
		scanf("%d", &opcao); // Para armazenar uma vari�vel do TIPO INTEIRO '%d' e para referenciar a vari�vel, usa-se o & 
	
		system("cls"); // fun��o de limpar a tela (Informa��es anteriores a tomada de decis�o do usu�rio
	
		switch (opcao) // N�o precisa colocar ; pois n�o � uma instru��o/comando - Inicio das sele��es
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
			printf("A op��o escolhida n�o est� dispon�vel! \n\n");
			system("Pause");
			break;
		}
	}
	printf("Esse software foi desenvolvido por Amanda Naomi Yoshitake \n");	
}
