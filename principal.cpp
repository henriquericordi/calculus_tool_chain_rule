#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "bib.h"

using namespace std;

int main(){
    char op;
    do{
        limpatela();
        cabecalho();
        derivada(inserir_funcao());
        printf("Opções:\n1 - Novo Cálculo\n2 - Sair\n3 - Ver Exemplos\n\nDigite a Opção: ");
        cin >> op;
        cin.ignore();
        op = tolower(op);
        primaria = "";
        if (op == '3'){
            limpatela();
            cabecalho();
            cout << "\nDigite:\nf(x)=[Função Trigonométrica]([Expressão1*x]^[Expressão2])\n\n[Expressão Trigonométrica], podem ser -sen, -cos, sen ou cos\n[Expressão1] e [Expressão2], podem ser constituídos de inteiros,\nfrações(numero1/numero2), pi(pi) e euler(e), sendo que não podem conter x e são separados por *\n\nExemplo 1: \nf(x)=sen(x^2)\nf'(x)=cos(x^2)*2*x\n\nExemplo 2: \nf(x)=-cos(1/2*x^3*pi)\nf'(x)=sen(1/2*x^3*pi)*(1/2)*3*pi*x^3*pi-1\n";
            string c;
            cout << "\nPressione qualquer tecla para continuar...\n";
            getline(cin,c);
        }
    } while (op != '2');
    return 0;
}
