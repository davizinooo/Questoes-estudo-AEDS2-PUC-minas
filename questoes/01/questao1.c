#include <stdio.h>

typedef struct 
{
  char nome[100];
  char bairro[100];

} Crianca;

Crianca parseCrianca(char *s) 
{
  Crianca crianca;
  sscanf(s, "%100[^;];%100[^\n]", crianca.nome, crianca.bairro);

  return crianca;
}

int compararCidades(char *s1, char *s2) 
{
  int i = 0;
  while(s1[i] != '\0' && s2[i] != '\0')
  {
    if(s1[i] > s2[i])
    {
      return 1;
    }
    else if(s1[i] < s2[i]) 
    {
      return -1;
    }

    i++;
  }

  if(s1[i] > s2[i]) 
  {
    return 1;
  }
  else if(s1[i] < s2[i]) 
  {
    return -1;
  }

  return 0;
}

void selectionSort(Crianca *criancas, int n)
{
  for(int i = 1; i < n; i++) 
  {
    Crianca tmp = criancas[i];
    int j = i - 1;
    while(j >= 0 && compararCidades(criancas[j].bairro, tmp.bairro) > 0)
    {
      criancas[j + 1] = criancas[j];
      j--;
    }
    criancas[j + 1] = tmp;
  }
}

void imprimirCriancas(Crianca *criancas, int n) 
{
  for(int i = 0; i < n; i++) 
  {
    printf("%s | %s\n", criancas[i].bairro, criancas[i].nome);
  }
}

int main ()
{
  int n = 0;
  scanf("%d", &n);
  getchar();
  char linha[100];
  Crianca criancas[n];
  for (int i = 0; i < n; i++) 
  {
    fgets(linha, 100, stdin);
    criancas[i] = parseCrianca(linha);
  }
  selectionSort(criancas, n);

  imprimirCriancas(criancas, n);
}
