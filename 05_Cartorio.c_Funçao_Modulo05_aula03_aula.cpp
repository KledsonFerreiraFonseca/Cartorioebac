#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

//inicio do controle do banco de dados
int registro() //Função responsável por cadastrar os usuários no sistema
{
	// inicio criação de variáveis/string
	char arquivo[40]; //OBS: variavel "char" pos é um caracter, um texto.
	char cpf[40]; //o "CPF" vai ser o nome do arquivo chave onde ficara armazenado todas as informações do banco de dados.
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //função string copy, que vai fazer uma copia do cpf para o arquivo que são os valores das sting
	
	FILE *file; //(CRIAR O ARQUIVO) "FILE" pede para procura no sistema nas nossas bibliotecas, já "*file" é o nome do arquivo 
	file = fopen(arquivo,"w"); // (CRIAR O ARQUIVO)"file"é o arquivo/"fopen" abrir o arquivo/"arquivo" é o nome da variável arquivo que o mesmo valor do CPF/"w" comando cria o arquivo
	fprintf(file,cpf); //(SALVAR O VALOR DA VARIÁVEL)"f-printf" este comando o sistema está salvando no arquivo.Então salva o arquivo"file" na variável "cpf".
	fclose(file); // (FECHA O ARQUIVO) "f-close" fecha as informações do arquivo "file" na variavel cpf.
	
	file = fopen(arquivo, "a"); // ("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a "," para separar as informações no sistema.
	fprintf(file,",");// comando abrir o arquivo
	fclose(file); //comando fecha o arquivo
	
	printf("Digite  o nome a ser cadastrado: ");// perguntado para o usuário para colocar o "nome".
	scanf("%s", nome);// salvando na "%s" string na variavel "nome"
	
	file = fopen(arquivo, "a");//("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a variavel "nome" dentro do arquivo.
	fprintf(file,nome);// comando abrir o arquivo
	fclose(file);//comando fecha o arquivo
	
	file = fopen(arquivo, "a");// ("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a "," para separar as informações no sistema.
	fprintf(file,",");// comando abrir o arquivo
	fclose(file);// comando feche o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");// perguntado para o usuário para colocar o "sobrenome".
	scanf("%s",sobrenome);// salvando na "%s" string na variavel "sobrenome"
	
	file = fopen(arquivo, "a");//("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a variavel "sobrenome" dentro do arquivo.
	fprintf(file,sobrenome);//comando abrir o arquivo
	fclose(file);//comando fecha o arquivo
	
	file = fopen(arquivo, "a");// ("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a "," para separar as informações no sistema.
	fprintf(file,",");// comando abrir o arquivo
	fclose(file);// comando feche o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");// perguntado para o usuário para colocar o "cargo"
	scanf("%s",cargo);// salvando na "%s" string na variavel "cargo"
		
	file = fopen(arquivo, "a");//("a" abrir arquivo) Esta abrindo o arquivo "file" para salvar a variavel "cargo" dentro do arquivo.
	fprintf(file,cargo);// comando abrir o arquivo
	fclose(file);// comando feche o arquivo
	
	system("pause");// comando para dar um pause para o usuário ler a mensagem
	
}

int consulta()//Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuquese"); //Definindo a linguagem / Definir para o sistema qual idioma estamos usado "portuguese", para cada função, porque as funções são individuais no sistema.
	
	// inicio criação de variáveis/string
	char cpf[40];// criar o arquivo "cpf" para consultar (LER)
	char conteudo[200];// criar variavel "conteudo"
	// final criação de variáveis/string 
	
	printf("Digite o CPF a ser consultado: ");// perguntado para o usuário qual "cpf" deseja consutar
	scanf("%s",cpf);//salvando na "%s" string na variavel "cpf"
	
	FILE *file;//(CONSULTAR O ARQUIVO) "FILE" pede para procura no sistema nas nossas bibliotecas, já "*file" é o nome do arquivo
	file = fopen(cpf,"r");// (CONULTAR O ARQUIVO)"file"é o arquivo/"fopen" abrir o arquivo/"arquivo" é o nome da variável arquivo que o mesmo valor do CPF/"R" comando ler o arquivo
	
	//inicio do comando p/ validação do sistema
	if(file == NULL)// (COMANDO PARA VALIDAR AS INFORMAÇÕES) se o arquivo for = à "NULL",o arquivo não existe
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");//resposta do sistema p/ o usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Função para salvar o arquivo, para isso usar o laço de repetição o "while"(em quanto), "fgets"(vai buscar no arquivo)"conteudo" que este conteúdo é a restrição"200"vezes em quanto for diferente de "NULL"(nulo)
	{
		printf("\nEssas são as informações do usuário: \n");//informar para o usuário o CONTEUDO das informações coletadas
		printf("%s", conteudo);//salvando na "%s" string na variavel "conteudo"
		printf("\n\n");//pulando linha
	//fim do comando p/ validação do sistema
	}
	system("pause");// comando para dar um pause para o usuário ler a mensagem



}

int deletar()//Função responsável por deletar os usuários no sistema
{
	// inicio criação de variáveis/string
	char cpf[40];//criar o arquivo "cpf" para deletar (delete)
	// final criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: ");// perguntado para o usuário qual "cpf" deseja deletar
	scanf("%s",cpf);// //salvando na "%s" string na variavel "cpf". Este comando vai varrer tudo que o usuário digitou e salvar o que vc pedir deletando o que foi solicitado.
	
	remove(cpf);// "remove" está função é apenas para deletar.
	
	//inicio do comando p/ validação do sistema
	FILE *file;// usamos "FILE" para acessar o parametro arquivo "*file".
	file = fopen(cpf,"r");// (ABRIR O ARQUIVO)"file"é o arquivo/"fopen" abrir o arquivo/"arquivo" é o nome da variável arquivo que o mesmo valor do CPF/"r" comando ler o arquivo
	
	if(file == NULL)// (COMANDO PARA VALIDAR AS INFORMAÇÕES) se o arquivo for = à "NULL",o arquivo não existe
	{
		printf("O usuário não se encontra no sistema!.\n ");//resposta do sistema p/ o usuário
		system("pause");// comando para dar um pause para o usuário ler a mensagem.
	//fim do comando p/ validação do sistema
	}
}
//fim do controle do banco de dados

int main()//"função principal" esta é o inicio do cabeçalho do programa
{
	int opcao=0; //Definindo variáveis. Para locar um espaço na memória.
	int laco=1;// variável do (FOR) "laco"
	
	for(laco=1;laco=1;) //chamada do laço de repetição "FOR"
	{
	
		system("cls");//responsavel por limpar a tela
		
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem / Definir para o sistema qual idioma estamos usado "portuguese".
	
		printf("###  Cartório da EBAC  ###\n\n"); //Inicio do menu/"printf" comando que aparece a mensagem para o usuário vindo com "\n\n" para pular linha
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registra nomes\n");// "\t" e para dar espaçamento no inicio da linha.
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:"); //Fim do menu
	
		scanf("%d",&opcao); //"scanf"armazenar, "%d" para armazenar do tipo inteiro(int), referenciar na variável "&opção". Armazenando o que o usuário coloca no sistema.
	
		system("cls"); //responsavel por limpar a tela
		
		
		switch(opcao) //inicio da seleção do menu. switch case(estrutura de comando p/ variável)
		{
			case 1:// caso 01
			registro(); //chamada de funções registro
			break;
			
			case 2:// caso 02
			consulta();//chamada de funções consulta
			break;
			
			case 3:// caso 03
			deletar();//chamada de funções deletar
			break;
			
			default://opção invalida
			printf("Essa opção não está disponivel!\n\n");
			system("pause");
			break;// Fim da seleção
		}
			printf("Esse softare é de livre uso dos alunos\n\n");		
	}
}//"função" esta é o fim do cabeçalho do programa
	
