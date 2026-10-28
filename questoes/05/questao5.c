#include <stdio.h>

typedef struct
{
  int id; 
  char modelo[100];
  int cilindrada;

} Veiculos;

Veiculos parseVeiculo(char *s)
{
  Veiculos veiculo;
  sscanf(s, "%d;%99[^;];%d", &veiculo.id, veiculo.modelo, &veiculo.cilindrada);

  return veiculo;
}

void countingSort(Veiculos *array, int n)
{
  int maior = array[0].cilindrada;
  for (int i = 1; i < n; i++) 
  {
    if(array[i].cilindrada > maior)
    {
      maior = array[i].cilindrada;
    }
  }
  
  int count[maior + 1];
  for(int i = 0; i <= maior; i++)
  {
    count[i] = 0;
  }
  
  for (int i = 0; i < n; i++) 
  {
    count[array[i].cilindrada]++;
  }

  for (int i = 1; i <= maior; i++) 
  {
    count[i] += count[i - 1];
  }

  Veiculos aux[n];

  for (int i = n - 1; i >= 0; i--) 
  {
    aux[count[array[i].cilindrada]- 1] = array[i];
    count[array[i].cilindrada]--;
  }

  for (int i = 0; i < n; i++) 
  {
    array[i] = aux[i];
  }
}

void imprimirArray(Veiculos *array, int n)
{
  for (int i = 0; i < n; i++)  
  {
    printf("%d | %d | %s\n", array[i].cilindrada, array[i].id, array[i].modelo);
  }
}

int main(int argc, char *argv[])
{
  int n = 0;
  scanf("%d", &n);
  getchar();
  Veiculos array[n];

  for (int i = 0; i < n; i ++) 
  {
    char linha[100];
    fgets(linha, 100, stdin);
    array[i] = parseVeiculo(linha);
  }
  
  countingSort(array, n);

  imprimirArray(array, n);
}


