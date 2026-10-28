typedef struct 
{
  int id;
  char modelo[100];
  double cilindrada;
}Veiculos;


Veiculos parseVeiculo(char *s)
{
  Veiculos v;
  sscanf(s, "%d;%99[^;];%lf", &v.id, v.modelo, &v.cilindrada);
  return v;
}

void imprimirArray(Veiculos *array, int n)
{
  for (int i = 0; i < n; i++) 
  {
    printf("%lf | %d | %s\n", array[i].cilindrada, array[i].id, array[i].modelo);
  }
}

void bucketSort(char *s, int n)
{
  double baldes[10];
  for (int i = 0; i < 10; i ++) 
  {
    baldes[i] = 0;
  }

  for (int i = 0; i < n; i++) 
  {
    baldes[array[i].cilindrada]:
  }
}

int main(int argc, char *argv[])
{
  int n = 0;
  scanf("%d", &n);
  getchar();

  Veiculos array[n];

  for (int i = 0; i < n; i++) 
  {
    char linha[100];
    fgets(linha, 100, stdin);
    array[i] = parseVeiculo(linha);
  }
}
