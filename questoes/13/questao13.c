#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char codigo[10];
  char carga[1000];
  
} Registro;

Registro parseRegistro(char *s)
{
  Registro registro;
  sscanf(s, "%9[^;];%s", registro.codigo, registro.carga);

  return registro;
}

typedef struct Celula 
{
  Registro elemento;
  struct Celula *prox;
} Celula;

typedef struct
{
  Celula *primeiro;
  Celula *ultimo;
} Lista; 

void iniciar(Lista *lista) 
{
  lista -> primeiro = (Celula*) malloc(sizeof(Celula));
  lista -> primeiro -> prox = NULL;
  lista -> ultimo = lista -> primeiro;
}

void inserirFim(Lista *lista, Registro x) 
{
  Celula *nova = malloc(sizeof(Celula));
  
  nova -> elemento = x;
  nova -> prox = NULL;

  lista -> ultimo -> prox = nova;
  lista -> ultimo = nova;
}

void inserirInicio(Lista *lista, Registro x)
{
  Celula *nova = malloc(sizeof(Celula));

  nova -> elemento = x;
  nova -> prox = lista -> primeiro -> prox;

  lista -> primeiro -> prox = nova;

  if(lista -> primeiro == lista -> ultimo)
  {
    lista -> ultimo = nova;
  }
}

void inserir(Lista *lista, int pos, Registro x)
{
  Celula *ant = lista -> primeiro;

  for (int i = 0; i < pos; i++) 
  {
    if(ant -> prox == NULL)
    {
      return;
    }
    ant = ant -> prox;
  }

  Celula *nova = malloc(sizeof(Celula));

  nova -> elemento = x;
  nova -> prox = ant -> prox;

  ant -> prox = nova;
  
  if(ant == lista -> ultimo)
  {
    lista -> ultimo = nova;
  }
}  

void removerInicio(Lista *lista)
{
  if(lista -> primeiro == lista -> ultimo)
  {
    printf("Erro: lista vazia\n");
    exit(1);
  }

  Celula *tmp = lista-> primeiro -> prox;
  Registro resp = tmp -> elemento;

  lista -> primeiro -> prox = tmp -> prox;

  if(tmp == lista -> ultimo)
  {
    lista -> ultimo = lista -> primeiro;
  }

  free(tmp);

  printf("(R) %s %s\n", resp.codigo, resp.carga);
}

void remover(Lista *lista, int pos) 
{
  Celula *ant = lista -> primeiro;

  for (int i = 0; i < pos; i++) 
  {
    if(ant -> prox == NULL)
    {
      return;
    }
    ant = ant -> prox;
  }

  Celula *tmp = ant -> prox;

  Registro resp = tmp -> elemento;

  if(tmp == NULL)
  {
    return;
  }

  ant -> prox = tmp -> prox;

  if(tmp == lista -> ultimo)
  {
    lista -> ultimo = ant;
  }

  free(tmp);
  
  printf("(R) %s %s\n", resp.codigo, resp.carga);
}

void mostrar(Lista *lista)
{
  int n = 0;
  for(Celula *i = lista -> primeiro -> prox; i != NULL; i = i -> prox)
  {
    printf("[%d] %s %s\n", n, i -> elemento.codigo, i -> elemento.carga);
    n++;
  }

  printf("\n");
}

int main(int argc, char *argv[])
{
  Lista lista;

  iniciar(&lista);

  int n = 0;

  scanf("%d", &n);
  getchar();
  
  for (int i = 0; i < n; i++) 
  {
    char linha[100];
    fgets(linha, 100, stdin);

    Registro registroAux = parseRegistro(linha);
    inserirFim(&lista, registroAux);
  }
  scanf("%d", &n);
  getchar();

  for (int i = 0; i < n; i++) 
  {
    char linha[100];
    char aux[100];
    char cmd[3];
    
    fgets(linha, 100, stdin);

    sscanf(linha, "%2[^ ] %s", cmd, aux);

    if(strcmp(cmd, "II") == 0) 
    {
      Registro registroAux = parseRegistro(aux);
      inserirInicio(&lista, registroAux);
    }
    else if(strcmp(cmd, "IF") == 0)
    {
      Registro registroAux = parseRegistro(aux);
      inserirFim(&lista, registroAux);
    }
    else if (strcmp(cmd, "R*") == 0) 
    {
      int pos = atoi(aux);
      remover(&lista, pos);
    }
  }

  mostrar(&lista);

}
