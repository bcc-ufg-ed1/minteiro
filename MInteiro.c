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

    if (!vazio(dados))
        return ERRO_CONJUNTO_NAO_VAZIO;

    if (n > TAM_MAX)
        return ERRO_CAPACIDADE_INSUFICIENTE;

    dados->nElementos = n;
    int i;
    for( i= 0; i < n; i++) {
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
    int i;
    for( i = 0; i < dados->nElementos; i++) {
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
    int i;
    for(i = 1; i < dados->nElementos; i++) {
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
    int i;
    for(i = 1; i < dados->nElementos; i++) {
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

int Pertence(Dados* dados, int pertence){

  if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

  if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

    int i;
    for(i = 0; i < dados->nElementos; i++){
        if (pertence == dados->elementos[i])
            return TRUE;
        return FALSE;

    }
      return OK;
}

int obterTamanho (Dados *dados, int* tam){
 if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

  if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;
        *tam = dados->nElementos;

    return OK;
}

int obterFrequencia (Dados* dados, int *frequencia){

if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

  if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

        int contador = 0;

        int i;
         for(i = 0; i < dados->nElementos; i++){
            if(*frequencia == dados->elementos[i])
                contador++;

         }
*frequencia = contador;

return OK;
}

float obterMedia(Dados *dados, float *media){
if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

  if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

        int soma = 0;
      obterSoma(dados, &soma);
      *media = soma/dados->nElementos;

        return OK;
}
int obterAmplitude(Dados *dados, int *amplitude){
    if (dados == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

  if (vazio(dados))
        return ERRO_CONJUNTO_VAZIO;

      int maior, menor;
    obterMaior(dados,&maior);
    obterMenor(dados,&menor);

*amplitude = maior - menor;

return OK;
}
