#include<stdlib.h>
#include<stdio.h>
#include "MInteiro.h"

int main() {
    int v[] = {5, 3, 9, 7, 1};
    int menor = 0, maior = 0, soma = 0;

    Dados *meusDados = inicializarDados();
    carregarDados(meusDados, v, 5);
    obterSoma(meusDados, &soma);
    obterMenor(meusDados, &menor);
    obterMaior(meusDados, &maior);
    printf("Soma = %d, Menor = %d, Maior = %d\n",
           soma, menor, maior);
    descartarDados(meusDados);

    return EXIT_SUCCESS;
}
