#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
  char codigo[3];
  char artista[100];

} Registro;

Registro parseRegistro(char *s)
{
  Registro registro;
  sscanf(s, "%2[^;];%s", registro.codigo, registro.artista);

  return registro;
}

typedef struct Celula 
{
  Registro elemento;
  struct Celula *prox;
  struct Celula *ant;
} Celula;

typedef struct
{
  Celula *primeiro;
  Celula *ultimo;
} Lista;

void iniciarLista(Lista *lista)
{
  lista -> primeiro = malloc(sizeof(Celula));
  lista -> primeiro -> prox = NULL;
  lista -> primeiro -> ant = NULL;
  lista -> ultimo = lista -> primeiro;
}

void inserirInicio(Lista *lista, Registro x)
{
  Celula *nova = malloc(sizeof(Celula));
  
  nova -> elemento = x;
  
  nova -> ant = lista -> primeiro;
  nova -> prox = lista -> primeiro -> prox;
  

  if(lista -> primeiro == lista -> ultimo)
  {
    lista -> ultimo = nova;
  }
  else 
  {
    lista ->primeiro -> prox -> ant = nova;
  }

  lista -> primeiro -> prox = nova;
   
}

void inserirFim(Lista *lista, Registro x)
{
  Celula *nova = malloc(sizeof(Celula));
 
  nova -> elemento = x;
  nova -> prox = NULL;
  nova -> ant = lista -> ultimo;
  
  lista -> ultimo -> prox = nova;
  lista -> ultimo = nova;
}

void inserirPos(Lista *lista, Registro x, int pos)
{
  Celula *anterior = lista -> primeiro; 

  for (int i = 0 ;i < pos; i++) 
  {
    //posicao invalida
    if(anterior -> prox == NULL)
    {
      return;
    }
    anterior = anterior -> prox;
  }

  Celula *nova = malloc(sizeof(Celula));

  nova -> elemento = x;

  nova -> ant = anterior; //anterior de nova = anterior
  nova -> prox = anterior -> prox; // prox de nova = proximo de anterior

  //se nao tiver no ultimo da lista
  if(anterior != lista -> ultimo)
  {
    anterior-> prox -> ant = nova;
  }
  else 
  {
    lista -> ultimo = nova;
  }
  
  anterior -> prox = nova;
}

Registro removerFim(Lista *lista)
{
  //verifica se lista esta vazia
  if(lista -> ultimo == lista -> primeiro)
  {
    Registro vazio = {0};
    return vazio;
  }

  Celula *tmp = lista -> ultimo;
  Registro resp = lista -> ultimo -> elemento;

  lista -> ultimo = lista -> ultimo -> ant;
  lista -> ultimo -> prox = NULL;

  free(tmp);
  return resp;
}

Registro removerInicio(Lista *lista)
{
  if(lista -> primeiro == lista -> ultimo)
  {
    Registro vazio = {0};
    return vazio;
  }

  Celula *tmp = lista -> primeiro -> prox;
  Registro resp = tmp -> elemento;

  lista -> primeiro -> prox = tmp -> prox;

  if(tmp != lista -> ultimo)
  {
    lista -> primeiro -> prox -> ant = lista -> primeiro; 
  }
  else 
  {
    lista -> ultimo = lista -> primeiro;
  }
  
  free(tmp);
  
  return resp; 
}

Registro removerPos(Lista *lista, int pos)
{
  if(lista -> primeiro == lista -> ultimo)
  {
    Registro vazio = {0};
    return vazio;
  }

  Celula *antes = lista -> primeiro; 
  for (int i = 0; i < pos; i ++) 
  {
    //posicao invalida
    if(antes -> prox == NULL)
    {
      registro vazio = {0};
      return vazio;
    }
    antes = antes -> prox;
  }

  if(antes -> prox == NULL) 
  {
    registro vazio = {0};
    return vazio; 
  }

  Celula *tmp = antes -> prox;
  Registro resp = tmp -> elemento;

  antes->prox = tmp->prox;

  if(tmp == lista -> ultimo)
  {
    antes -> prox -> ant = antes;
  }
  else 
  {
    tmp -> prox -> ant = antes;
  }

  free(tmp);

  return resp;
}

int main(int argc, char *argv[])
{
  Lista lista;
  iniciarLista(&lista);
}


