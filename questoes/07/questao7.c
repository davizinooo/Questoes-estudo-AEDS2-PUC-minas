#include <stdio.h>

typedef struct 
{
  int id; 
  char modelo[100];
  int ano;
} Carros;

Carros parseCarro(char *s)
{
  Carros carro;
  sscanf(s, "%d;%99[^;];%d", &carro.id, carro.modelo, &carro.ano);
  return carro;
}

void radixSort(Carros *array, int n)
{
  for (int dc = 1; dc <= 1000; dc *= 10) 
  {
    int count[10];
    for (int i = 0; i < 10; i++) 
    {
      count[i] = 0;
    }
    
    for (int i = 0; i < n; i++) 
    {
      count[((array[i].ano / dc) % 10)]++;
    }
    
    for (int i = 1; i < 10; i++) 
    {
      count[i] += count[i - 1];
    }
  
    Carros aux[n];

    for (int j = n - 1; j >= 0; j--)
    {
      aux[count[(array[j].ano / dc) % 10] - 1] = array[j];
      count[(array[j].ano / dc) % 10]--;
    }

    for (int j = 0; j < n; j++) 
    {
      array[j] = aux[j];
    }
    
  }
}

void imprimirArray(Carros *array, int n) 
{
  for (int i = 0 ; i < n; i++) 
  {
    printf("%d | %d | %s\n", array[i].ano, array[i].id, array[i].modelo);
  }
}

int main (int argc, char *argv[])
{
  int n = 0;
  scanf("%d", &n);
  getchar();

  Carros carros[n];

  for (int i = 0; i < n; i ++) 
  {
    char linha[100];
    fgets(linha, 100, stdin);
    carros[i] = parseCarro(linha);
  }

  radixSort(carros, n);
  imprimirArray(carros, n);
}
