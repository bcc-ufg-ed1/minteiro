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

int pertence(Dados* d, int el) {
    if (d == NULL)
        return ERRO_DADOS_NAO_INICIALIZADOS;

    if (vazio(d))
        return FALSE;

    for(int i = 0; i < d->nElementos; i++) {
        if (d->elementos[i] == el)
            return TRUE;
    }
    return FALSE;
}
