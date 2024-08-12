#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

//inicio do controle do banco de dados
int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// inicio cria��o de vari�veis/string
	char arquivo[40]; //OBS: variavel "char" pos � um caracter, um texto.
	char cpf[40]; //o "CPF" vai ser o nome do arquivo chave onde ficara armazenado todas as informa��es do banco de dados.
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //fun��o string copy, que vai fazer uma copia do cpf para o arquivo que s�o os valores das sting
	
	FILE *file; //(CRIAR O ARQUIVO) "FILE" pede para procura no sistema nas nossas bibliotecas, j� "*file" � o nome do arquivo 
	file = fopen(arquivo,"w"); // (CRIAR O ARQUIVO)"file"� o arquivo/"fopen" abrir o arquivo/"arquivo" � o nome da vari�vel arquivo que o mesmo valor do CPF/"w" comando cria o arquivo
	fprintf(file,cpf); //(SALVAR O VALOR DA VARI�VEL)"f-printf" este comando o sistema est� salvando no arquivo.Ent�o salva o arquivo"file" na vari�vel "cpf".
	fclose(file); // (FECHA O ARQUIVO) "f-close" fecha as informa��es do arquivo "file" na variavel cpf.
	
	file = fopen(arquivo, "a"); // ("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a "," para separar as informa��es no sistema.
	fprintf(file,",");// comando abrir o arquivo
	fclose(file); //comando fecha o arquivo
	
	printf("Digite  o nome a ser cadastrado: ");// perguntado para o usu�rio para colocar o "nome".
	scanf("%s", nome);// salvando na "%s" string na variavel "nome"
	
	file = fopen(arquivo, "a");//("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a variavel "nome" dentro do arquivo.
	fprintf(file,nome);// comando abrir o arquivo
	fclose(file);//comando fecha o arquivo
	
	file = fopen(arquivo, "a");// ("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a "," para separar as informa��es no sistema.
	fprintf(file,",");// comando abrir o arquivo
	fclose(file);// comando feche o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");// perguntado para o usu�rio para colocar o "sobrenome".
	scanf("%s",sobrenome);// salvando na "%s" string na variavel "sobrenome"
	
	file = fopen(arquivo, "a");//("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a variavel "sobrenome" dentro do arquivo.
	fprintf(file,sobrenome);//comando abrir o arquivo
	fclose(file);//comando fecha o arquivo
	
	file = fopen(arquivo, "a");// ("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a "," para separar as informa��es no sistema.
	fprintf(file,",");// comando abrir o arquivo
	fclose(file);// comando feche o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");// perguntado para o usu�rio para colocar o "cargo"
	scanf("%s",cargo);// salvando na "%s" string na variavel "cargo"
		
	file = fopen(arquivo, "a");//("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a variavel "cargo" dentro do arquivo.
	fprintf(file,cargo);// comando abrir o arquivo
	fclose(file);// comando feche o arquivo
	
	system("pause");// comando para dar um pause para o usu�rio ler a mensagem
	
}

int consulta()//Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuquese"); //Definindo a linguagem / Definir para o sistema qual idioma estamos usado "portuguese", para cada fun��o, porque as fun��es s�o individuais no sistema.
	
	// inicio cria��o de vari�veis/string
	char cpf[40];// criar o arquivo "cpf" para consultar (LER)
	char conteudo[200];// criar variavel "conteudo"
	// final cria��o de vari�veis/string 
	
	printf("Digite o CPF a ser consultado: ");// perguntado para o usu�rio qual "cpf" deseja consutar
	scanf("%s",cpf);//salvando na "%s" string na variavel "cpf"
	
	FILE *file;//(CONSULTAR O ARQUIVO) "FILE" pede para procura no sistema nas nossas bibliotecas, j� "*file" � o nome do arquivo
	file = fopen(cpf,"r");// (CONULTAR O ARQUIVO)"file"� o arquivo/"fopen" abrir o arquivo/"arquivo" � o nome da vari�vel arquivo que o mesmo valor do CPF/"R" comando ler o arquivo
	
	//inicio do comando p/ valida��o do sistema
	if(file == NULL)// (COMANDO PARA VALIDAR AS INFORMA��ES) se o arquivo for = � "NULL",o arquivo n�o existe
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");//resposta do sistema p/ o usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Fun��o para salvar o arquivo, para isso usar o la�o de repeti��o o "while"(em quanto), "fgets"(vai buscar no arquivo)"conteudo" que este conte�do � a restri��o"200"vezes em quanto for diferente de "NULL"(nulo)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");//informar para o usu�rio o CONTEUDO das informa��es coletadas
		printf("%s", conteudo);//salvando na "%s" string na variavel "conteudo"
		printf("\n\n");//pulando linha
	//fim do comando p/ valida��o do sistema
	}
	system("pause");// comando para dar um pause para o usu�rio ler a mensagem



}

int deletar()//Fun��o respons�vel por deletar os usu�rios no sistema
{
	// inicio cria��o de vari�veis/string
	char cpf[40];//criar o arquivo "cpf" para deletar (delete)
	// final cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");// perguntado para o usu�rio qual "cpf" deseja deletar
	scanf("%s",cpf);// //salvando na "%s" string na variavel "cpf". Este comando vai varrer tudo que o usu�rio digitou e salvar o que vc pedir deletando o que foi solicitado.
	
	remove(cpf);// "remove" est� fun��o � apenas para deletar.
	
	//inicio do comando p/ valida��o do sistema
	FILE *file;// usamos "FILE" para acessar o parametro arquivo "*file".
	file = fopen(cpf,"r");// (ABRIR O ARQUIVO)"file"� o arquivo/"fopen" abrir o arquivo/"arquivo" � o nome da vari�vel arquivo que o mesmo valor do CPF/"r" comando ler o arquivo
	
	if(file == NULL)// (COMANDO PARA VALIDAR AS INFORMA��ES) se o arquivo for = � "NULL",o arquivo n�o existe
	{
		printf("O usu�rio n�o se encontra no sistema!.\n ");//resposta do sistema p/ o usu�rio
		system("pause");// comando para dar um pause para o usu�rio ler a mensagem.
	//fim do comando p/ valida��o do sistema
	}
}
//fim do controle do banco de dados

int main()//"fun��o principal" esta � o inicio do cabe�alho do programa
{
	int opcao=0; //Definindo vari�veis. Para locar um espa�o na mem�ria.
	int laco=1;// vari�vel do (FOR) "laco"
	
	for(laco=1;laco=1;) //chamada do la�o de repeti��o "FOR"
	{
	
		system("cls");//responsavel por limpar a tela
		
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem / Definir para o sistema qual idioma estamos usado "portuguese".
	
		printf("###  Cart�rio da EBAC  ###\n\n"); //Inicio do menu/"printf" comando que aparece a mensagem para o usu�rio vindo com "\n\n" para pular linha
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registra nomes\n");// "\t" e para dar espa�amento no inicio da linha.
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o:"); //Fim do menu
	
		scanf("%d",&opcao); //"scanf"armazenar, "%d" para armazenar do tipo inteiro(int), referenciar na vari�vel "&op��o". Armazenando o que o usu�rio coloca no sistema.
	
		system("cls"); //responsavel por limpar a tela
		
		
		switch(opcao) //inicio da sele��o do menu. switch case(estrutura de comando p/ vari�vel)
		{
			case 1:// caso 01
			registro(); //chamada de fun��es registro
			break;
			
			case 2:// caso 02
			consulta();//chamada de fun��es consulta
			break;
			
			case 3:// caso 03
			deletar();//chamada de fun��es deletar
			break;
			
			default://op��o invalida
			printf("Essa op��o n�o est� disponivel!\n\n");
			system("pause");
			break;// Fim da sele��o
		}
			printf("Esse softare � de livre uso dos alunos\n\n");		
	}
}//"fun��o" esta � o fim do cabe�alho do programa
	
