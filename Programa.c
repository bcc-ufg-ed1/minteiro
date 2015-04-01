#include<stdlib.h>
#include<stdio.h>
#include "MInteiro.h"

int main() {
    int v[] = {1, 1, 3, 5, 7, 8, 9};
    int menor = 0, maior = 0, soma = 0,tam = 0,frequencia = 1,amplitude = 0;
    float media = 0;

    Dados *meusDados = inicializarDados();
    carregarDados(meusDados, v, 7);
    obterSoma(meusDados, &soma);
    obterMenor(meusDados, &menor);
    obterMaior(meusDados, &maior);
    obterFrequencia(meusDados,&frequencia);
    obterTamanho(meusDados, &tam);
    obterMedia(meusDados, &media);
    obterAmplitude(meusDados, &amplitude);
    if (Pertence(meusDados,1)==TRUE)
        printf("pertence\n");
    printf("Soma = %d, Menor = %d, Maior = %d, tamanho = %d, Frequencia = %d, media = %.2f, amplitude = %d\n",
           soma, menor, maior,tam,frequencia,media,amplitude);
    descartarDados(meusDados);

    return EXIT_SUCCESS;
}
