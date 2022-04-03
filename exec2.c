/*
Pablo dos Santos Garaju - RU: 3560344

Exercício 2:
Faça um algoritmo em linguagem C que realiza a busca de um aluno da UNINTER no AVA. A busca deve ser realizada utilizando uma estrutura de dados bastante eficiente para esta tarefa.
Defina a estrutura de dados que você irá utilizar para fazer esta implementação e JUSTIFIQUE em texto porque você escolheu ela;
1. Deve-se armazenar o nome do aluno, seu e-mail e seu RU. Para o armazenamento utilize uma estrutura heterogênea de dados.
2. Não é necessário fazer a leitura dos dados dos dados dos alunos manualmente. Você já pode deixar pré-cadastrado os dados no seu código. Cadastre pelo menos uns 10 contatos de alunos na sua estrutura de dados. Um dos contatos deverá ser o seu próprio nome e o seu RU da UNINTER;
3. Em um menu na tela, peça para o usuário digitar um RU. O programa deverá realizar a busca por este RU na estrutura de dados e, caso localize o RU, deverá mostrar o nome correspondente do aluno e o e-mail deste contato. Caso não localize, uma mensagem de erro deve ser apresentada.
4. Para testar o programa, teste a busca com o seu RU e coloque a captura de dela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// estrutura de alunos
struct Aluno{ 
  char nome[20], email[30]; 
  int RU; 
  struct Aluno *proximo;
} *Head; //variável de escopo Global.

// escopo das minhas funcoes
void InserirAluno_Inicio(char n[20], char e[30], int r);
void Imprimir();
void Buscar(); 
void Menu();

int main(){
  int c, numRU; 

  //criando o cadastro de cada aluno.
  InserirAluno_Inicio("Teste1", "teste1@mail.com", 121);
  InserirAluno_Inicio("Teste2", "teste2@mail.com", 122);
  InserirAluno_Inicio("Teste3", "teste3@mail.com", 123);
  InserirAluno_Inicio("Teste4", "teste4@mail.com", 124);
  InserirAluno_Inicio("Teste5", "teste5@mail.com", 125);
  InserirAluno_Inicio("Teste6", "teste6@mail.com", 126);
  InserirAluno_Inicio("Teste7", "teste7@mail.com", 127);
  InserirAluno_Inicio("Teste8", "teste8@mail.com", 128);
  InserirAluno_Inicio("Teste9", "teste9@mail.com", 129);
  InserirAluno_Inicio("Pablo dos Santos", "pablo@mail.com", 3560344);
  
  Menu(); 
  
  return 0;
}

// estrutura de dados utilizada para fazer a implementação é a lista encadeada Simples não circular, devido ao pequeno tamanho da lista. Não se vê necessidade de ter ponteiros para o próximo e também para o antecessor uma vez que não há muita correlação entre os dados cadastrais dos alunos. 

void Menu(){
  int escolha, c;

  printf("------- Escolha sua opção: ------- \n");
  printf("1. Imprimir a lista de alunos cadastrados.\n");
  printf("2. Buscar aluno no cadastro.\n >> ");
  scanf("%d", &escolha); 
  while ((c=getchar()) != '\n' && c != EOF) {}

  switch(escolha){ 
    case 1: 
      Imprimir();
    break;
    case 2: 
      Buscar();
    break;
    default: 
      printf("Escolha Inválida.\nTente novamente.\n\n");
      Menu();
  } 
}

// insere aluno na lista
void InserirAluno_Inicio(char n[20], char e[30], int r){

  struct Aluno *NovoAluno; //cria uma novo aluno
  
  NovoAluno = (struct Aluno *)malloc(sizeof(struct Aluno)); 
  strcpy(NovoAluno->nome, n); 
  strcpy(NovoAluno->email, e); 
  NovoAluno->RU = r; 

  if (Head == NULL)
  {
    Head = NovoAluno; 
    Head->proximo = NULL; 
  }
  else 
  {
    NovoAluno->proximo = Head;  
    Head = NovoAluno; 
  }
}

void Imprimir(){ 
  
  struct Aluno *ElementoVarredura;
  ElementoVarredura = (struct Aluno *)malloc(sizeof(struct Aluno)); 

  ElementoVarredura = Head;
  if (ElementoVarredura == NULL){ 
    return;
  }
  while (ElementoVarredura != NULL){ 
    printf("\nNome: %s", ElementoVarredura->nome);
    printf("\nE-mail: %s", ElementoVarredura->email);
    printf("\nRu: %d\n", ElementoVarredura->RU);
    ElementoVarredura = ElementoVarredura->proximo;
  }
  printf("\n\n");

  return;
}


void Buscar (){

  int c, numRU; 

  printf("\n****** Procurar aluno ******\n");
  printf("Digite o RU do aluno que deseja buscar:\n>> ");
  scanf("%d", &numRU); 
  while ((c=getchar()) != '\n' && c != EOF);

  struct Aluno *ElementoVarredura;
  ElementoVarredura = (struct Aluno *)malloc(sizeof(struct Aluno)); 
  ElementoVarredura = Head;
  
  while(ElementoVarredura != NULL){ 
    if (ElementoVarredura->RU == numRU) {
      printf("\nAluno encontrado:\n");
			printf("\nNome: %s", ElementoVarredura->nome);
      printf("\nE-mail: %s", ElementoVarredura->email);
      printf("\n");
      return;
		}
		else { 
			ElementoVarredura = ElementoVarredura->proximo;
		} 
  }

  printf("\nAluno não encontrado.\n"); 

  return;
}