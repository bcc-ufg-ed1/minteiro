#include<stdio.h>
#include<stdlib.h>
#include "MInteiro.h"

Dados* inicializarDados() {
    Dados *dados;
    if ((dados = (Dados*) malloc(sizeof(Dados))) == NULL)
        return NULL;

    dados->nElementos = 0;
    return dados;
}

int carregarDados(Dados* dados, int v[], int n) {
    if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

    if (!vazio(dados))//tava so um "d"
        return ERRO_CONJUNTO_NAO_VAZIO;

    if (n > TAM_MAX)
        return ERRO_CAPACIDADE_INSUFICIENTE;

    dados->nElementos = n;
    for(int i = 0; i < n; i++) {
        dados->elementos[i] = v[i];
    }
    return OK;
}

int descartarDados(Dados* dados) {
    if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

    free(dados);
    dados = NULL;
}

int obterSoma(Dados* dados, int *soma) {
    if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

    *soma = 0;
    for(int i = 0; i < dados->nElementos; i++) {
        *soma = *soma + dados->elementos[i];
    }
    return OK;
}

int obterMaior(Dados* dados, int *maior) {
    if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

    if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

    *maior = dados->elementos[0];
    for(int i = 1; i < dados->nElementos; i++) {
        if (dados->elementos[i] > *maior)
            *maior = dados->elementos[i];
    }

    return OK;
}

int obterMenor(Dados* dados, int *menor){
    if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

    if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

    *menor = dados->elementos[0];
    for(int i = 1; i < dados->nElementos; i++) {
        if (dados->elementos[i] < *menor)
            *menor = dados->elementos[i];
    }
    return OK;
}

int vazio(Dados* dados) {
    if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

    return dados->nElementos == 0;
}

int obterPertence(Dados* dados, int *pertence){

  if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

  if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

    int i;
    for(i = 0; i < dados->nElementos; i++){
        if (*pertence == dados->elementos[i])
        printf("pertence ao conjunto de elementos = %d\n",*pertence);

    }
      return OK;
}

int obterTamanho (Dados *dados, int *tamanho){
 if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

  if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

        *tamanho = 0;
        int i;
         for(i = 0; i < dados->nElementos; i++){

            *tamanho = *tamanho + 1;
         }

    return OK;
}

int obterFrequencia (Dados *dados, int *frequencia){

if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

  if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

        int x = 0;
        int i;
         for(i = 0; i < dados->nElementos; i++){
            if(*frequencia == dados->elementos[i])
                x = x+1;

         }
*frequencia = x;
return OK;
}

float obterMedia(Dados *dados, float *media){
if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

  if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

        int soma = 0, i, quant =0;
        for(i = 0; i < dados->nElementos; i++){
            quant = quant + 1;
            soma = soma + dados->elementos[i];
        }

        *media = soma/quant;
        return OK;
}
int obterAmplitude(Dados *dados, int *amplitude){
    if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

  if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

        int i, maior, menor;
        maior = dados->elementos[0];
        menor = dados->elementos[0];

    for(i = 1; i < dados->nElementos; i++) {
        if (dados->elementos[i] < menor)
            menor = dados->elementos[i];

        if (dados->elementos[i] > maior)
            maior = dados->elementos[i];
    }
*amplitude = maior - menor;

return OK;
}
