/*
Pablo dos Santos Garaju - RU: 3560344

Exercício 1:
Faça um algoritmo em linguagem C que emule as características de um player de músicas sendo executado em modo texto, via prompt de comando.
1. Deve-se criar uma playlist das músicas utilizando uma lista encadeada. A lista encadeada poderá ser simples ou dupla, circular ou não circular. Fica a critério do aluno decidir.
2. Deve-se armazenar o nome de cada música, do artista/banda e a duração da faixa. Para o armazenamento utilize uma estrutura heterogênea de dados.
3. Para inserção dos dados, você pode criar uma leitura dos dados através de um menu na tela ou já deixá-los armazenados em um arquivo texto no seu computador e só carregar este arquivo ao executar o programa. Ou ambas soluções. Decida também como você irá implementar a inserção (no início, no fim ou no meio da lista encadeada);
4. Deve existir um menu na tela. Este menu deve permitir a inserção de novas músicas (caso optado pela inserção manual de dados), deve ter a opção de listar todas as músicas da playlist (listagem de uma lista encadeada) na tela e encerrar o programa;
Utilize como base o código de listas da AULA PRÁTICA 2 da disciplina. Código está disponível no Github do professor. O link está na aula prática 2;
*/

#include <stdio.h>
#include <stdlib.h>

// anunciado as minha funções
int menu(); 
void Imprimir();
void InserirInicio(); 

// estrutura de musicas
struct Lista_de_Musicas{
  char titulo[30], artista[30]; 
  float duracao; 
  struct Lista_de_Musicas *proximo;
} *Head;

// funcao principal
int main() {
  int c, opcao; //variaveis de menu

  while (1){
    opcao= menu(); 

    switch(opcao){
      case 1: 
        InserirInicio();
        break;
      
      case 2: 
        Imprimir();
        break;
      
      case 3: 
        return 0;
      
      default: 
	printf("\nOpção inválida. Tente novamente.\n\n");

    }
  }

  return 0;
}

int menu(){ 
  int escolha, c;

  printf("-------------- MENU --------------\n");
  printf("1. Inserir nova música.\n");
  printf("2. Mostrar lista de músicas.\n");
  printf("3. Sair do progrma.\n");
  printf("----------------------------------\n");
  printf("Digite sua opção:\n>> ");

  scanf("%d", &escolha); 
  while ((c=getchar()) != '\n' && c != EOF) {} // limpando buffer de memoria

  return escolha;
}

// funcao que insere no inicio
void InserirInicio(){ 
  int c; 

  struct Lista_de_Musicas *NovaMusica;
  
  NovaMusica = (struct Lista_de_Musicas *)malloc(sizeof(struct Lista_de_Musicas));
  
  printf("Digite o nome da música: \n>> ");
  scanf("%s", NovaMusica->titulo); 
  while ((c=getchar()) != '\n' && c != EOF) {}
  
  printf("Nome do artista ou da banda: \n>> ");
  scanf("%s", NovaMusica->artista); 
  while ((c=getchar()) != '\n' && c != EOF) {} 
  
  printf("Tempo da faixa musical:  \n>> ");
  scanf("%f", &NovaMusica->duracao); 
  while ((c=getchar()) != '\n' && c != EOF) {} 

// inserindo na lista 
  if (Head == NULL)
  {
    Head = NovaMusica;
    Head->proximo = NULL; 
  }
  else 
  {
    NovaMusica->proximo = Head;
    Head = NovaMusica;
  }
}

void Imprimir(){ 

  struct Lista_de_Musicas *ElementoVarredura;
  ElementoVarredura = (struct Lista_de_Musicas *)malloc(sizeof(struct Lista_de_Musicas)); 

  ElementoVarredura = Head; 

  printf("\n---------- Lista de Músicas ----------\n\n");

  if (ElementoVarredura == NULL){ 
    printf("Você ainda não inseriu nenhuma música na lista:(\n\n");
    return;
  }
  while (ElementoVarredura != NULL){ 
    printf("Título: %s \n", ElementoVarredura->titulo);
    printf("Artista ou Banda: %s \n", ElementoVarredura->artista);
    printf("Duração: %.2f \n\n", ElementoVarredura->duracao);
    
    ElementoVarredura = ElementoVarredura->proximo;

  }
  printf("\n");

  return;
}