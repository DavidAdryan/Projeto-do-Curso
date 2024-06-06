#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings





int registrar()
{
	
	setlocale(LC_ALL, "Portuguese"); //definir linguagem
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	

		
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" ,cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");
}


int consultar()
{
	
	setlocale(LC_ALL, "Portuguese"); //definir linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		
		printf("Não foi possivel abrir o arquivo, não encontrado no banco de dados.");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		
		printf("\nEssas são as informações do usuário:  ");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");
	}
	
	
}


int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definir linguagem
	
	char cpf[40];
	
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	
	if(cpf||NULL){
		printf("CPF encontrado, deseja realmente deleta-lo ?\n");
		system("pause");
	}
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL){
		
		printf("O CPF não está no banco de dados.\n\n");
		system("pause");
		
		

		
	}
	
	
	
}







int main()
{
	
	int opcao=0;
	int x=1;
	
	
	for(x=1; x=1;)
	{		
		
					
		setlocale(LC_ALL, "Portuguese"); //definir linguagem
	
	
	
		printf("*****Cartório da Empresa*****\n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opcão: ");
	
	

		scanf("%d", &opcao);  // scanf=(guardar o que o usuario digitar) (%d guarda um valor na variavel &)  &opcao=(para alterar o valor da variavel opcao)
	
		system("cls"); // comando para limpar a tela apos o comando do usuario
	
		switch(opcao){
			
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
		
			
			default:
			printf("Esta opção não está disponível\n\n");
			system("pause");
			break;
		}
		
	
		

	
		system("cls");
	
	}
}
