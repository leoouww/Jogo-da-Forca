#include <stdio.h>
#include <stdlib.h>
#include <math.h> // rand() est� na biblioteca math.h
#include <locale.h>
#include <time.h> //inclu�da a fun��o para que se possa utilizar o rand mais apropriadamente aleat�rio
#define TAM 50	//TAM foi escolhida para definir o tamanho m�ximo da string. Com folga, caber� as palavras mais o zero terminador.
#define FIM 6 //indica o fim do jogo quando o jogador erra 6 vezes e o procedimento "mostra_forca" se revela com a forma��o de todos os membros corp�reos
#define NPALAVRAS 6 //Para utilizarmos nas matrizes com banco de 5 palavras
#define NLETRAS 9 //Para utilizarmos nas matrizes cujas palavras poder�o ir at� 8 caracteres
#define FACIL 4 //Para utilizarmos no Nivel de dificuldade Facil com 4 letras
#define MEDIO 6 //Para utilizarmos no Nivel de dificuldade Medio com 6 letras 
#define DIFICIL 8 //Para utilizarmos no Nivel de dificuldade Dificl com 8 letras

/* 
	TRABALHO 1 - JOGO DA FORCA
	LEONARDO RODRIGUES DE CASTRO
	PT3008479 
*/


// O programa poderia ser melhorado com uso de mais
// fun��es para evitar c�digos repetitivos. Mas eu precisaria
// usar ponteiros para modificar algumas vari�veis como por exemplo
// a variavel tentativa. No entanto, a gente ainda n�o aprendeu ponteiros nas aulas.
// Ent�o, eu o deixei mais longo, mesmo.
 
void mostra_forca (int qtd_erros){ //Procedimento que recebe o par�metro da quantidade de erros e desenha o atual estado da forca
	printf("\n");
	switch(qtd_erros){
	case 0: 
		printf(" _________\n|         |\n|\n|\n|\n|\n|\n|\n"); //escreve na tela a forca com nenhum membro corp�reo, ou seja, 0 erros
		break;
	case 1:
		printf(" _________\n|         |\n|         0\n|\n|\n|\n|\n|\n"); //escreve na tela a forca com apenas a cabe�a, ou seja, 1 erro
		break;
	case 2:
		printf(" _________\n|         |\n|         0\n|         |\n|\n|\n|\n|\n"); //escreve na tela a forca com cabe�a e corpo, ou seja, 2 erros
		break;
	case 3:
		printf(" _________\n|         |\n|         0\n|        /|\n|\n|\n|\n|\n"); //escreve na tela a forca com cabe�a, corpo e bra�o esquerdo, ou seja, 3 erros
		break;
	case 4:
		printf(" _________\n|         |\n|         0\n|        /|\\ \n|\n|\n|\n|\n");//escreve na tela a forca com cabe�a, corpo, bra�o esquerdo e bra�o direito, ou seja, 4 erros
		break;
	case 5:
		printf(" _________\n|         |\n|         0\n|        /|\\ \n|        /\n|\n|\n|\n"); //escreve na tela a forca com cabe�a, corpo, bra�os e perna esquerda ou seja, 5 erros
		break;
	case 6:
		printf(" _________\n|         |\n|         0\n|        /|\\ \n|        / \\ \n|\n|\n|\n"); //escreve na tela a forca com cabe�a, corpo, bra�os e pernas ou seja, 6 erros; sendo revelada apenas quando o jogador perde o jogo
		break;
	}
}

void jogadorvsjogador(char nome_jogador1[TAM]){ //Procedimento que ser� utilizada quando usuario digitar a op��o 1 de jogadorvsjogador
	char palavra_passe[TAM], //vetor que armazenar� a palavra-passe a ser descoberta
		 letras_escolhidas[TAM] = {'\0'}, //vetor que armazenar� todas as letras digitadas pelo usuario (certas e/ou erradas)
		 revelacao[TAM], //vetor que ser� inicializado com o caractere '*' nas n primeiras posi��es, onde n � a quantidade de elementos da string palavra-passe
		 nome_jogador2[TAM]; //Como o jogador2 ocorre apenas quando a modalidade do jogo � jogadorvsjogador, aqui necessita-se declar�-la
	int qtd_erros = 0, //variavel parametro para a funcao mostra_forca (aquela que desenha o atual estado do jogo)
		tentativa = 0,//variavel que armazena quantas tentativas o usuario ja fez (certas e/ou erradas)
		j; //variavel auxilio para percorrer vetores.
	printf("\nDigite o nome do jogador 2: ");
	scanf("%s", nome_jogador2);
	printf("\n\n%s, insira a palavra passe: ", nome_jogador1);
	scanf("%s", palavra_passe);
	system("cls"); //Ap�s o jogador 1 escrever a palavra-passe, ela � apagada para que o jogador 2 n�o a veja.
	for(j = 0;palavra_passe[j]; ++j) //inicializacao do vetor revelacao com asteriscos mais zero terminador
		revelacao[j] = '*';
	revelacao[j] = '\0';
	char verifica_letra, //Variavel criada para verificar se o usuario ja a digitou anteriormente.
		 acerto, //Variavel que indica se letra digitada pertence � palavra-passe
		 continuar_loop; //Variavel que controla a continuidade do la�o de entrada de letra. 
	fflush(stdin); 
	do{
		continuar_loop = 'n';
		mostra_forca(qtd_erros);
		if(tentativa == 0)
			printf("\n     %s\n\n", revelacao);
		do{ //la�o cuja condi��o � a variavel verifica_letra ser ' '. Somente sair� do la�o se o jogador digitar uma letra ainda n�o digitada
			printf("\nDigite uma letra: ");
			scanf("%c", &verifica_letra);
			fflush(stdin);
			for(j = 0;letras_escolhidas[j]; j++){
				if(verifica_letra == letras_escolhidas[j]){
					printf("Letra %c j� utilizada. Tente novamente\n\n\n", verifica_letra);
					verifica_letra = ' ';
				}
			}	
		}while(verifica_letra == ' ');
		letras_escolhidas[tentativa] = verifica_letra;
		acerto = 'f';
		for(j = 0;palavra_passe[j]; ++j){ //la�o que percorre a palavra passe para saber se a letra digitada faz parte. Em caso positivo, revelacao recebe as letras descobertas nos respectivos indices do vetor
			if(letras_escolhidas[tentativa] == palavra_passe[j]){
				revelacao[j] = letras_escolhidas[tentativa];
				acerto = 'v';
			}
		}
		if(acerto == 'f')
			qtd_erros++;
		printf("PALAVRA:   %s", revelacao);
		printf("\nLetras inseridas: ");
		for(j = 0;letras_escolhidas[j]; ++j){ //la�o que escreve as letras j� digitadas na tela
			if(j == 0)
				printf("%c", letras_escolhidas[j]);
			else printf(" - %c", letras_escolhidas[j]);	
		}
		tentativa++; //atualiza��o da variavel tentativa para o proximo loop, caso a palavra nao tenha sido descoberta ainda ou o jogador nao tenha errado 6 vezes. Como se inicializa em 0, n�o tem problema ela atualizar antes de mostrar o resultado
		for(j = 0;revelacao[j]; j++){
			if(revelacao[j] == '*') 
				continuar_loop = 's';
		}
		if(continuar_loop == 'n')
			printf("\n\n\nVIT�RIA, %s, VOC� ACERTOU EM %d TENTATIVA(S) A PALAVRA %s COM %d ERRO(S)!",nome_jogador2, tentativa, palavra_passe, qtd_erros);
		if(qtd_erros == FIM){
			continuar_loop = 'n';
			printf("\n\n\nDERROTA, %s; %d ERRO(S) / %d TENTATIVA(S). A PALAVRA ERA %s",nome_jogador2, qtd_erros, tentativa, palavra_passe);
			mostra_forca(qtd_erros);		
		}
	}while(continuar_loop == 's');
}

void jogador_escolhe(char nome_jogador1[TAM]){ //procedimento que ser� executado quando o usu�rio escolher a op��o jogadorvscomputador, em que o jogador escolhe a palavra para o compuatdor acertar
	int nivel, //a variavel nivel relaciona qual o tamanho da palavra para tentar advinhar
		tentativa = 0, //variavel que armazena quantas tentativas o usuario ja fez (certas e/ou erradas)
		j, //variavel auxilio para percorrer vetores.
		qtd_erros = 0; //variavel parametro para a funcao mostra_forca (aquela que desenha o atual estado do jogo)
	char palavra_passe[NLETRAS], //vetor que armazenar� a palavra-passe a ser descoberta 
		 revelacao[NLETRAS], //vetor que ser� inicializado com o caractere '*' nas n primeiras posi��es, onde n � a quantidade de elementos da string palavra-passe
		 letras_escolhidas[TAM]={'\0'}; //vetor que armazenar� todas as letras digitadas pelo usuario (certas e/ou erradas)
	printf("\nEscolha o n�vel de dificuldade:\n1-F�cil (4 letras);\n2-M�dio (6 letras);\n3-Dif�cil (8 letras)");
	scanf("%d", &nivel);
	if(nivel >= 1 && nivel <= 3){ //Ap�s escolhido o n�vel de dificuldade, o jogo somente continuar� se o usu�rio digitar um numero v�lido {1, 2 ou 3}
		printf("\n\n%s, insira a palavra passe de n�vel %d: ", nome_jogador1, nivel);
		scanf("%s", palavra_passe);
		for(j = 0;palavra_passe[j]; ++j)
			revelacao[j] = '*';
		revelacao[j] = '\0';
		system("cls");
		srand(time(0)); //garante que a funcao rand() quando chamada seja mais aleatoria
		char verifica_letra, //Variavel criada para verificar se o usuario ja a digitou anteriormente.
			 acerto, //Variavel que indica se letra digitada pertence � palavra-passe
			 continuar_loop; //Variavel que controla a continuidade do la�o de entrada de letra
		do{
			continuar_loop = 'n';
			mostra_forca(qtd_erros);
			if(tentativa == 0)
				printf("\n     %s\n\n", revelacao);
			do{
				printf("\n%d� Tentativa: ", tentativa+1);
				verifica_letra = 'a' + (rand() % 26); //garante que a letra escolhida pelo computador esteja no intervalo entre 'a' e 'z'.
				for(j = 0;letras_escolhidas[j]; j++){
					if(verifica_letra == letras_escolhidas[j]){
						printf("Letra %c j� utilizada. Tente novamente\n\n\n", verifica_letra);
						verifica_letra = ' ';
					}
				}	
			}while(verifica_letra == ' ');
			letras_escolhidas[tentativa] = verifica_letra;
			acerto = 'f'; 
			for(j = 0;palavra_passe[j]; ++j){
				if(letras_escolhidas[tentativa] == palavra_passe[j]){
					revelacao[j] = letras_escolhidas[tentativa];
					acerto = 'v';
				}
			}
			if(acerto == 'f')
				qtd_erros++;
			printf("PALAVRA:   %s", revelacao);
			printf("\nLetras inseridas: ");
			for(j = 0;letras_escolhidas[j]; ++j){
				if(j == 0)
					printf("%c", letras_escolhidas[j]);
				else printf(" - %c", letras_escolhidas[j]);	
			}
			tentativa++;
			for(j = 0;revelacao[j]; j++){
				if(revelacao[j] == '*') 
					continuar_loop = 's';
			}
			if(continuar_loop == 'n')
				printf("\n\n\nVIT�RIA, O COMPUTADOR ACERTOU EM %d TENTATIVA(S) A PALAVRA %s COM %d ERRO(S)!", tentativa, palavra_passe, qtd_erros);
			if(qtd_erros == FIM){
				continuar_loop = 'n';
				printf("\n\n\nDERROTA, %d ERRO(S) / %d TENTATIVA(S). A PALAVRA ERA %s", qtd_erros, tentativa, palavra_passe);
				mostra_forca(qtd_erros);
			}
		}while(continuar_loop == 's');
	}
	else printf("\nEscolha de n�vel errada: %d", nivel);
}
	
	
void computador_escolhe(char nome_jogador1[TAM]){ //procedimento que ser� executado quando o usu�rio escolher a op��o jogadorvscomputador, em que o computador escolhe a palavra para o jogador acertar
	int nivel, //a variavel nivel relaciona qual o tamanho da palavra para tentar advinhar
	    tentativa = 0, //variavel que armazena quantas tentativas o usuario ja fez (certas e/ou erradas)
		j, //variavel auxilio para percorrer vetores.
		qtd_erros = 0, //variavel parametro para a funcao mostra_forca (aquela que desenha o atual estado do jogo)
	    indice_aleatorio; //Vari�vel que vai determinar qual das 5 palavras das matrizes ser� escolhida 
	char palavra_passe[NLETRAS], //vetor que armazenar� a palavra-passe a ser descoberta
		 revelacao[NLETRAS], //vetor que ser� inicializado com o caractere '*' nas n primeiras posi��es, onde n � a quantidade de elementos da string palavra-passe
		 letras_escolhidas[TAM] = {'\0'}, //vetor que armazenar� todas as letras digitadas pelo usuario (certas e/ou erradas)
		 palavras_nivel1[NPALAVRAS][NLETRAS] = {"jaca","tatu","dedo","anos","ilha"}, //Matriz com 5 palavras de 4 letras - nivel1
		 palavras_nivel2[NPALAVRAS][NLETRAS] = {"jacare","lindas","cancer","papeis","comida"}, //Matriz com 5 palavras de 6 letras - nivel2
		 palavras_nivel3[NPALAVRAS][NLETRAS] = {"atolados","cobertor","computar","combater","refletir"}; //Matriz com 5 palavras de 8 letras - nivel3
	printf("\nEscolha o n�vel de dificuldade:\n1-F�cil (4 letras);\n2-M�dio (6 letras);\n3-Dif�cil (8 letras)");
	scanf("%d", &nivel);
	if(nivel >= 1 && nivel <= 3){//Ap�s escolhido o n�vel de dificuldade, o jogo somente continuar� se o usu�rio digitar um numero v�lido {1, 2 ou 3}
		srand(time(0)); //garante que a funcao rand() quando chamada seja mais aleatoria
		indice_aleatorio = rand()%5; //garante que o �ndice ser� 0,1,2,3 ou 4; assim, cobrindo todas as palavras das matrizes
		switch(nivel){ //Aqui ser� inicializada a palavra-passe considerando o respectivo nivel escolhido acima
		case 1:
			for(j = 0;j < FACIL;++j)
				palavra_passe[j] = palavras_nivel1[indice_aleatorio][j];
			palavra_passe[j] = '\0';
			break;
		case 2:
			for(j = 0;j < MEDIO;++j)
				palavra_passe[j] = palavras_nivel2[indice_aleatorio][j];
			palavra_passe[j] = '\0';
			break;
		case 3:
			for(j = 0;j < DIFICIL;++j)
				palavra_passe[j] = palavras_nivel3[indice_aleatorio][j];
			palavra_passe[j] = '\0';
			break;	
		}
		for(j = 0;palavra_passe[j]; ++j)
			revelacao[j] = '*';
		revelacao[j] = '\0';
		char verifica_letra, //Variavel criada para verificar se o usuario ja a digitou anteriormente.
			 acerto, //Variavel que indica se letra digitada pertence � palavra-passe
			 continuar_loop; //Variavel que controla a continuidade do la�o de entrada de letra
		fflush(stdin);
		do{
			continuar_loop = 'n';
			mostra_forca(qtd_erros);
			if(tentativa == 0)
				printf("\n     %s\n\n", revelacao);
			do{
				printf("\nDigite uma letra: ");
				scanf("%c", &verifica_letra);
				fflush(stdin);
				for(j = 0;letras_escolhidas[j]; j++){
					if(verifica_letra == letras_escolhidas[j]){
						printf("Letra %c j� utilizada. Tente novamente\n\n\n", verifica_letra);
						verifica_letra = ' ';
					}
				}	
			}while(verifica_letra == ' ');
			letras_escolhidas[tentativa] = verifica_letra;
			acerto = 'f';
			for(j = 0;palavra_passe[j]; ++j){
				if(letras_escolhidas[tentativa] == palavra_passe[j]){
					revelacao[j] = letras_escolhidas[tentativa];
					acerto = 'v';
				}
			}
			if(acerto == 'f')
				qtd_erros++;
			printf("PALAVRA:   %s", revelacao);
			printf("\nLetras inseridas: ");
			for(j = 0;letras_escolhidas[j]; ++j){
				if(j == 0)
					printf("%c", letras_escolhidas[j]);
				else printf(" - %c", letras_escolhidas[j]);	
			}
			tentativa++;
			for(j = 0;revelacao[j]; j++){
				if(revelacao[j] == '*') 
					continuar_loop = 's';
			}
			if(continuar_loop == 'n')
				printf("\n\n\nVIT�RIA, %s, VOC� ACERTOU EM %d TENTATIVA(S) A PALAVRA %s COM %d ERRO(S)!",nome_jogador1, tentativa, palavra_passe, qtd_erros);
			if(qtd_erros == FIM){
				continuar_loop = 'n';
				printf("\n\n\nDERROTA, %s; %d ERRO(S) / %d TENTATIVA(S). A PALAVRA ERA %s",nome_jogador1, qtd_erros, tentativa, palavra_passe);
				mostra_forca(qtd_erros);		
			}
		}while(continuar_loop == 's');
	}
	else printf("\nEscolha de n�vel errada: %d", nivel);
}


void jogadorvscomputador(char nome_jogador1[TAM]){ //Procedimento para a escolha de jogo contra o computador
	char quem_escolhe = ' ';//variavel que indica se o jogador ou computador escolhe a palavra-passe.
	do{ //la�o que garante que uma das op��es a ou b seja definida
		fflush(stdin);
		printf("\n\nEscolha dentre as op��es: \n[a] Jogador escolhe a palavra;\n[b] Computador escolhe a palavra\n");
		scanf("%c", &quem_escolhe);
	}while(quem_escolhe != 'a' && quem_escolhe != 'b');
	switch(quem_escolhe){ //switch que determina qual procedimento ser� chamado
	case 'a':
		jogador_escolhe(nome_jogador1);
		break;
	case 'b':
		computador_escolhe(nome_jogador1);
		break;
	}
}

int main(int argc, char *argv[]) { //A main vai chamar os procedimentos acima de acordo com o que o Jogador 1 definir
	setlocale(LC_ALL, ""); //utilizado para que se possam usar na funcao printf acentos e caracteres especiais
	char nome_jogador1[TAM];//nome do jogador 1 ser� defenido na main, enquanto o jogador 2 ser� definido apenas dentro da funcao jogadorvsjogador
	int modalidade; //Modalidade vai definir se o usuario vai jogar contra outra pessoa ou contra outra m�quina.
	
	printf("JOGO DA FORCA\nATEN��O: N�o utilizar caracteres especiais, n�meros ou letras mai�sculas!\n\n");
	printf("\nDigite o nome do jogador 1: ");
	scanf("%s", nome_jogador1);
	printf("\nEscolha a op��o de jogo:\n1) jogador vs jogador;\n2) jogador vs computador\n");
	scanf("%d", &modalidade);
	switch (modalidade){ //switch que determina qual procedimento ser� chamado. Em caso de erro de entrada, o programa se encerra com uso do default
	case 1:
		jogadorvsjogador(nome_jogador1); 
		break;
	case 2:
		jogadorvscomputador(nome_jogador1);
		break;
	default:
		printf("\nOP��O INV�LIDA!\n");
	}
	return 0;
}
