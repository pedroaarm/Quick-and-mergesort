#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"Ordenaxaocomplexa.h"


 // parte de desenvolvimento do QuickSorte
 
 //funcao de cadastro de funcionaro
funcionario* cadastrar(){
    funcionario *func = (funcionario*)malloc(sizeof(funcionario));
    
   printf("\nDigite o nome do funcionario: ");
   scanf("%s",func->Nome);
    printf("\nDigite o numero da matricula: ");
    scanf("%d",&func->Matricula);
   printf("\nDigite o cpf");
   scanf("%s",func->CPF);
   printf("\nDigite o salario: ");
   scanf("%lf",&func->Salario);
    return func;
}
// reforna o tamanho da lista
 int tamanhodalista(funcionario *func) 
{       funcionario *aux = func;
	int contador = 0;
	while(aux!=NULL) {
		++contador;
                aux= aux->prox;
	}
	return contador;
}
 

 funcionario *encontrarpivo(funcionario *func) // essa funcao serve para encontrar o pivo no Quick, usando a media de 3 escolhas
 {
	int listatamanho = tamanhodalista(func);
        srand(time(NULL));
        
	int posicaopivo[3];
        posicaopivo[0] = rand() % listatamanho;
        posicaopivo[1] = rand() % listatamanho;
          posicaopivo[2] = rand() % listatamanho;
          int mediapivo = (posicaopivo[0]+posicaopivo[1] + posicaopivo[2])/3; // aqui é calculado a media do pivo para encontrar o pivo correto
        

	for (int i = 0; i < mediapivo; i++)// a lista é deslocada para o elemento do pivo escolhido
	{
            func = func->prox;
	}
	return func;
}
 
 //essa funcao serve para encontrar o ultimo elemento da lista
 funcionario *ultimono(funcionario *func){
     funcionario *aux = func;
     for (; aux->prox != NULL; aux= aux->prox);
	
     return aux;
     
 }
 
 // apos a lista ser dividida de 2, essa funcao faz a juncao dessas duas parte,
 funcionario *juncaoQuick(funcionario* a, funcionario * pivo, funcionario *b)
{
	pivo->prox = a; // lista do lado direito

	if (b == NULL)	{ // se o lado esquerdo for nulo, retorna o pivo (lado direito)
            return pivo; // retorna o pivo, ou a parte a
        }
	funcionario * esquerda_fim = ultimono(b); // encontrando o ultimo no lista esquerda;
	esquerda_fim->prox = pivo; // lado direito vai apontar pro pivo

	return esquerda_fim; // retorna a lista completa ja juntada
}
 // essa funcao é a funcao principal do kick, utiliza todas as funcoes anteriores
 funcionario *Quicksort(funcionario *func){//tem como parametro a lista de funcionarios
    if (func == NULL || func->prox == NULL) {// caso a lista esteja vazia, retornaremos apenas a lista, pois nao tem necessidade de fazer ordenacao
         return func; // retornando a lista
    }

    funcionario *pivo = encontrarpivo(func); // aqui encontramos o pivo para fazer as comparacoes

	funcionario *lista_esquerda = NULL, *lista_direita = NULL; // variaveis para dividir a lista em 2, lado direito e lado esquerdo

	for (funcionario * noatual = func; noatual != NULL;) // esse for percorre toda a lista
	{
		funcionario* proximono = noatual->prox; // captura o no atual para comparacoes no futuro

		if (noatual != pivo)// verifica se o noatual é diferente do pivo
		{
			if (noatual->Matricula <= pivo->Matricula)  // verifica de no atual é maior que o pivo, com o intuito de fazer trocas
                        {
				noatual->prox = lista_esquerda;//se noatual for menos, entao ele passara a apontar seu proximo elemento pra lista esquerda
				lista_esquerda = noatual; // lista esquerda vai ser igual a lista atual, fazendo assim a troca
			}
			else //caso contrario
			{
				noatual->prox = lista_direita; // o no atual vai apontar pra lista direita
				lista_direita = noatual; //lista direita aponta para atual
			}
		}
		noatual = proximono; // noatual vai ser igual ao proximono.
	}
        return juncaoQuick(Quicksort(lista_esquerda), pivo, Quicksort(lista_direita)); //aqui temos um retorno no tipo recurssao onde sera feita a jucao e comparacao dos numeros na lista
 }
 
 // Funcao do MergeSort 
 
funcionario* junta(funcionario* a, funcionario* b){ // essa funcao tem como proposito juntar as duas partes da funcao
funcionario *result = NULL; // inicializa uma variavel result como nula
// Casos Base
if (a == NULL)//se a for nulo, apenas retorna o elemento b;
	return(b);

else if (b==NULL)//se b for nulo, ira retornar o elemento a
	return(a);

// escolhe a ou b e chamaa função recursiva 
if (a->Matricula >= b->Matricula){ //verifica se a é maior ou igual que b
        result = a; // se sim o valor de result vai se a
	result->prox = junta(a->prox, b);}// o proximo valor de resultado vai ser a juncao do proximo de a com b;

else{
        result = b; // result recebe b (identido ao if anterior)
	result->prox = junta(a, b->prox);} // faz a juncao;

return(result); // retorna o resultado, ou seja, retorna as duas partes juntas
}


void particionar(funcionario *func, funcionario **frente, funcionario **pos){ //ao contrario da funcao dividi em partes
	funcionario* avanca;//declarado funcao
	funcionario* tarta;//declarado funcao
	tarta = func; //variavel tarta vai ser igua a func ((lista original))
	avanca = func->prox; // avanca vai ser igual ao proximo elemento de funcao

	/* Avança 'avanca' dois nós, e avança 'tarta' um nó */
	while (avanca != NULL){
	avanca = avanca->prox;
	if (avanca != NULL){
		tarta = tarta->prox;
		avanca = avanca->prox;}
        }

	/* 'tarta' é antes do ponteiro do meio da lista, e vai dividí-lo em dois
	no mesmo ponto. */
	*frente = func;
	*pos =tarta->prox;
	tarta->prox = NULL;
}


void MergeSort(funcionario** func){ // funcao que utiliza as funcoes declaradas anteriormente
funcionario *aux = *func; // declara duas variaceis
funcionario *a = NULL;// declara e inicializa em Numm
funcionario *b = NULL;// idem
// caso base, nao retorna nada caso a lista esteja vazia ou contenha apenas 1 elemento
if ((aux == NULL) || (aux->prox == NULL)){
	return ;
    }else{
    // divide a lista em duaspartes
    particionar(*func, &a, &b); 

//Recursivamente ordena as sublistas
MergeSort(&a);
MergeSort(&b);

// Mescla as duas sublistas
*func = junta(a,b); 
    
    }
 } 

//essa funcao adiciona um novo elemento
funcionario * adicionar(funcionario *func){
    funcionario* novo = cadastrar();


    
    if(func == NULL){
        novo->prox=NULL;
        return novo;
    }else{
        novo->prox = func;
        return novo;
    }
     
}

//imprime os dados cadastrados
void imprimir(funcionario *func){
    funcionario *aux = func;
    
    while(aux!=NULL){

       printf("\nMatricula: %d |Nome: %s |Salario: %lf |CPF: %s", aux->Matricula,aux->Nome, aux->Salario, aux->CPF);
        aux = aux->prox;
    }
}
//cria um novo funcionario
funcionario* criar (){
    
    return NULL;
}
//funcao de menu

int menu(){
    int op;
    printf("\n\n1-Adicionar Funcionario\n2-Ordenar por QuickSort\n3-Ordenar usando MergeSort\n4-Mostrar Funcionarios\n5-Listar todos os funcionários \n6-Mostrar tempo de ordenação QuickSort\n7-Mostrar tempo de ordenação MergeSort\n0-sair\n");
    scanf("%d",&op);
    return op;
}
void mostrarfuncionario(funcionario *func, int id){
    funcionario *aux = func;
    while(aux->prox!= NULL && aux->Matricula!=id){
        if(aux->Matricula == id){
 
   printf("\nMatricula: %d |Nome: %s |Salario: %lf |CPF: %s\n", aux->Matricula,aux->Nome, aux->Salario, aux->CPF);

        }
        aux = aux->prox;
    }
    printf("\nFuncionario nao encontrado\n");
}
