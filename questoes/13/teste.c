#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{
  int elemento;
  struct Celula *prox;
} Celula;

Celula *primeiro;
Celula *ultimo;

Celula novaCelula(int elemento)
{
  Celula *nova = (Celula*) malloc(sizeof(Celula));
  if(nova == NULL)
  {
    printf("Erro de memoria\n");
    exit(1);
  }

  nova -> elemento = x;
  nova -> prox = NULL;

  return nova;
}

void inicio()
{
  primeiro = novaCelula(-1);
  ultimo = primeiro;
}

int tamanho()
{
  int tam = 0;

  Celula *i;

  for (i = primeiro -> prox; i != NULL; i = i -> prox) 
  {
    tam++;
  }

  return tam;
}

void inserirInicio(int x)
{
  Celula *tmp = novaCelula(x);

  tmp -> prox = primeiro -> prox;
  primeiro -> prox = tmp;

  if(primeiro == ultimo)
  {
    ultimo = tmp;
  }

  tmp = NULL;
}


