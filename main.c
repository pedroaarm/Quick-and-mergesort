
/*
 Trabalho valendo 1 ponto na matéria de Estrutura de Dados I - 2018.2
 * Universidade Federal do Piaui - Campus Picos;
 * Autor: Pedro Augusto Alcantara Ribeiro Moraes
 */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Ordenaxaocomplexa.h"


//funcao principal
int main(int argc, char** argv) {
   
    funcionario *func = criar();

    int op;
       int idfuc;
    //as proximas duas variaveis sao uteis para marcar o tempo de cada algoritmo de ordenacao
    clock_t tempomerge[2]; 
    clock_t tempoQuick[2];
    double tempo;


    
    do{
        
        op = menu();
        switch(op){
        case 1:
        func = adicionar(func);
            break;
       
       case 2:
           tempoQuick[0] = clock();
           func = Quicksort(func);
           tempoQuick[1] = clock();
           tempo = (tempoQuick[0]+tempoQuick[2]*1000/CLOCKS_PER_SEC);
                           printf("\nO tempo de ordenacao (em ms) do Quicksort eh:%g\n",tempo);
           break;
      case 3:
       tempomerge[0] = clock();
       MergeSort(&func); 
       tempomerge[1] = clock();
       tempo = (tempomerge[1] - tempomerge[0])* 1000/CLOCKS_PER_SEC;
       printf("\nO tempo de ordenacao (em ms) do MergeSort eh:%g\n",tempo);
       break;
       case 4:
        
           printf("\nDigite o ID: ");
           scanf("%d",&idfuc);        
           mostrarfuncionario(func,idfuc);
           break;
           case 5:
           imprimir(func);
           break;
           case 6:
           printf("\nO tempo de ordenacao (em ms) do Quicksort eh:%g\n",tempo);
           break;
          case 7:
            printf("\nO tempo de ordenacao (em ms) do MergeSort eh:%g\n",tempo);
            break;
            default:
                printf("\nOpcao invalida");
                break;
        }
    }while(op!=0);
    return 0;
}

