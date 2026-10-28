#include <stdio.h>

typedef struct 
{
  char nome[100];
  int producao;
} Duende;

Duende parseDuende(char *s)
{
  Duende duende;
  sscanf(s, "%99[^;];%d", duende.nome, &duende.producao);

  return duende;
}

int compararCaracterer(char *nome1, char *nome2)
{
  int i = 0;
  while(nome1[i] != '\0' && nome2[i] != '\0')
  {
    if(nome1[i] > nome2[i])
    {
      return 1;
    }
    else if(nome1[i] < nome2[i])
    {
      return -1;
    }
    i++;
  }
  
  if(nome1[i] > nome2[i])
  {
    return 1;
  }
  else if(nome1[i] < nome2[i])
  {
    return -1;
  }
  return 0;
}

void insertionSort(Duende *duende, int n) 
{
  for (int i = 1; i < n; i++) 
  {
    Duende chave = duende[i];
    int j = i - 1;

  while(j >= 0 && (chave.producao > duende[j].producao || (chave.producao == duende[j].producao && compararCaracterer(chave.nome, duende[j].nome) < 0)))
    {
      duende[j + 1] = duende[j];
      j--;
    }
    duende[j + 1] = chave;
  }
}

void imprimirArray(Duende *duende, int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%s | %d\n", duende[i].nome, duende[i].producao);
  }
}

int main (int argc, char *argv[])
{
  int n = 0;
  scanf("%d", &n);
  getchar();

  Duende duendes[n];  

  for (int i = 0; i < n; i++) 
  {
    char linha[100];
    fgets(linha, 100, stdin);
    duendes[i] = parseDuende(linha);  
  }
  
  insertionSort(duendes, n);

  imprimirArray(duendes, n);
}
