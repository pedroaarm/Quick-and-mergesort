
/* 
 * File:   Ordenaxaocomplexa.h
 * Author: pedro
 *
 * Created on 25 de Novembro de 2018, 11:53
 */

#ifndef ORDENAXAOCOMPLEXA_H
#define ORDENAXAOCOMPLEXA_H
struct Funcionario{
    int Matricula; // parâmetro usado para a ordenação
    char Nome[30];
     char CPF[11];
    double Salario;
    struct Funcionario *prox;
};
typedef struct Funcionario funcionario;


funcionario* cadastrar();
int tamanhodalista(funcionario *func);
funcionario *encontrarpivo(funcionario *func);
funcionario *ultimono(funcionario *func);
funcionario *juncaoQuick(funcionario* a, funcionario * pivo, funcionario *b);
funcionario *Quicksort(funcionario *func);
funcionario* junta(funcionario* a, funcionario* b);
void particionar(funcionario *func, funcionario **frente, funcionario **pos);
void MergeSort(funcionario** func);
funcionario * adicionar(funcionario *func);
void imprimir(funcionario *func);
funcionario* criar();
int menu();


#endif /* ORDENAXAOCOMPLEXA_H */

