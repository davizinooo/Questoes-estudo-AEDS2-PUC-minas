#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
  int id;
  char nome[100];
} Brinquedo;

typedef struct 
{
  Brinquedo array[100];
  int n;
} Lista;

Brinquedo parseBrinquedo(char *s)
{
  Brinquedo brinquedo;
  sscanf(s, "%d;%99[^\n]", &brinquedo.id, brinquedo.nome);
  return brinquedo;
}

void iniciarLista(Lista *lista)
{
  lista -> n = 0;
}

void inserirFim(Lista *lista, Brinquedo x)
{
  lista -> array[lista -> n] = x;
  lista -> n++;
}

void inserirInicio(Lista *lista, Brinquedo x) 
{
  for (int i = lista -> n; i > 0; i--) 
  {
    lista -> array[i] = lista -> array[i - 1];
  }

  lista -> array[0] = x;
  lista -> n++;
}

void inserirPos(Lista *lista, Brinquedo x, int pos)
{
  lista -> n++;

  for (int i = lista -> n; i > pos; i--) 
  {
    lista -> array[i] = lista -> array[i - 1];
  }

  lista -> array[pos] = x;
}

void removerPos(Lista *lista, int pos) 
{
  Brinquedo brinquedo = lista -> array[pos];
  for (int i = pos; i < lista -> n - 1; i++) 
  {
    lista -> array[i] = lista -> array[i + 1];
  }
  lista -> n--;
  printf("(R) %d %s\n", brinquedo.id, brinquedo.nome);
}

void imprimirLista(Lista *lista)
{
  for (int i = 0 ; i < lista -> n; i++) 
  {
    printf("[%d] %d %s\n", i, lista -> array[i].id, lista -> array[i].nome);
  }
}

int main(int argc, char *argv[])
{ 
  int n = 0;
  scanf("%d", &n);
  getchar();
  Lista lista;
  iniciarLista(&lista);

  for (int i = 0; i < n; i++) 
  {
    char linha[100];
    fgets(linha, 100, stdin);
    inserirFim(&lista, parseBrinquedo(linha));
  }

  int qntC = 0;
  scanf("%d", &qntC);
  getchar();

  for (int i = 0; i < qntC; i++) 
  {
    char linha[100];
    char strBrin[100];
    char comando[3];

    fgets(linha,100,stdin);
    sscanf(linha, "%2[^ ] %99[^\n]", comando, strBrin);
    
    if(strcmp(comando, "II") == 0) 
    {
      inserirInicio(&lista, parseBrinquedo(strBrin));
    }
      else if (strcmp(comando, "IF") == 0) 
      {
        inserirFim(&lista, parseBrinquedo(strBrin));
      }
        else if (strcmp(comando, "R*") == 0) 
        {
          removerPos(&lista, atoi(strBrin));
        }        
  }
  imprimirLista(&lista);
}
