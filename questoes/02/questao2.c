#include <stdio.h>

typedef struct
{
  int matricula;
  char nome[100];
  int turma;
} Registro;

Registro parseRegistro(char *s)
{
  Registro pessoa;
  sscanf(s, "%d;%99[^;];%d", &pessoa.matricula, pessoa.nome, &pessoa.turma);

  return pessoa;
}

int compararString(char *s1, char *s2)
{
  int i  = 0;
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

void selectionSort(Registro *pessoas, int n, int funcao)
{

  for (int i = 0; i < n - 1; i++) 
  {
    int menor = i;
    for (int j = i + 1; j < n; j++) 
    {
      if(funcao == 1)
      {
      if(compararString(pessoas[menor].nome, pessoas[j].nome) > 0)
      {
        menor = j;
      }
      }
      if(funcao == 0) 
      {
        if(pessoas[menor].matricula > pessoas[j].matricula)
        {
          menor = j;
        }
      }
      if(funcao == -1)
      {
        if(pessoas[menor].turma > pessoas[j].turma)
        {
          menor = j;
        }
      }
    }
    Registro aux = pessoas[menor];
    pessoas[menor] = pessoas[i];
    pessoas[i] = aux;
  }
}

void imprimirArray(Registro *pessoas, int n)
{
  for (int i = 0; i < n; i++) 
  {
  printf("%d | %s | %d\n", pessoas[i].matricula, pessoas[i].nome, pessoas[i].turma);
  }
}

int main(int argc, char *argv[])
{
  int n = 0;
  scanf("%d", &n);
  getchar();

  Registro estudantes[n];

  for (int i = 0; i < n; i++) 
  {
    char linha[100];
    fgets(linha, 100, stdin);
    estudantes[i] = parseRegistro(linha);
  }

  selectionSort(estudantes, n, -1);
  selectionSort(estudantes, n, 1);
  selectionSort(estudantes, n, 0);

  imprimirArray(estudantes, n);
}
