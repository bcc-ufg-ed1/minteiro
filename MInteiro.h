#ifndef MINTEIRO_H
#define MINTEIRO_H

#define TRUE 1
#define FALSE 0
#define TAM_MAX 50

#define OK 0
#define ERRO_DADOS_NAO_INICIALIZADOS -1
#define ERRO_CAPACIDADE_INSUFICIENTE -2
#define ERRO_CONJUNTO_VAZIO -3
#define ERRO_CONJUNTO_NAO_VAZIO -4

typedef struct {
    int elementos[TAM_MAX];
    int nElementos;
} Dados;

Dados* inicializarDados();
int carregarDados(Dados* dados, int v[], int n);
int descartarDados(Dados* dados);
int obterSoma(Dados* dados, int *soma);
int obterMaior(Dados* dados, int *maior);
int obterMenor(Dados* dados, int *menor);
int Pertence(Dados* dados, int pertence);
int obterTamanho (Dados *dados, int *tam);
int obterFrequencia (Dados *dados, int *frequencia);
int obterAmplitude(Dados *dados, int *amplitude);
float obterMedia(Dados *dados, float *media);
int vazio(Dados* dados);

#endif // MINTEIRO_H
