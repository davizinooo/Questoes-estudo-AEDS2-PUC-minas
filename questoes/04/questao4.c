#include <stdio.h>

typedef struct
{
  int id;
  char marca[100];
  char modelo[100];
  int ano;
} Carros;

Carros parseCarros(char *s)
{
  Carros carro;

  sscanf(s, "%d;%99[^;];%99[^;];%d", &carro.id, carro.marca, carro.modelo, &carro.ano);

  return carro;
}

int compararCaracterer(char *s1, char *s2)
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

void insertionSort(Carros *carros, int n, int cmd) 
{
  for (int i = 1; i < n; i++) 
  {
    Carros chave = carros[i];
    int j = i - 1;

    while(j >= 0 && (compararCaracterer(chave.marca, carros[j].marca) < 0 ||
                    (compararCaracterer(chave.marca, carros[j].marca) == 0 &&
                     compararCaracterer(chave.modelo, carros[j].modelo) < 0) ||
                    (compararCaracterer(chave.marca, carros[j].marca) == 0 &&
                     compararCaracterer(chave.modelo, carros[j].modelo) == 0 &&
                     chave.id < carros[j].id)))
    {
      carros[j + 1] = carros[j];
      j--;      
    } 
  carros[j + 1] = chave;
  }
}

void imprimirArray(Carros *carros, int n)
{
  for (int i = 0; i < n; i ++) 
  {
    printf("%d ## %s ## %s ## %d\n", carros[i].id, carros[i].marca, carros[i].modelo, carros[i].ano);
  }
}

int main(int argc, char *argv[])
{ 
  int n = 0; 
  scanf("%d", &n);
  getchar();
  Carros carros[n];

  for (int i = 0; i < n; i++) 
  {
    char linha[100];
    fgets(linha, 100, stdin);
    carros[i] = parseCarros(linha);
  }

  insertionSort(carros, n, 0);
  imprimirArray(carros, n);
}
