import java.util.Scanner;

class Duende
{
  private String nome;
  private int producao;
  
  Duende(String nome, int producao)
  {
    this.nome = nome;
    this.producao = producao;
  }

  public static Duende parseDuende(String s)
  {
    String[] campos = s.split(";");

    String nome = campos[0];
    int producao = Integer.parseInt(campos[1]);

    return new Duende(nome, producao);
  }

  public String getNome()
  {
    return nome;
  }

  public int getProducao()
  {
    return producao;
  }
}

class questao3 
{
  static void insertionSort(Duende[] duendes, int n)
  {
    for (int i = 1; i < n; i++) 
    {
      Duende chave = duendes[i];
      int j = i - 1;
      while (j >= 0 && (chave.getProducao() > duendes[j].getProducao() || chave.getProducao() == duendes[j].getProducao() && (chave.getNome().compareTo(duendes[j].getNome()) < 0))) 
      {
        duendes[j + 1] = duendes[j];
        j--;
      }
      duendes[j + 1] = chave;
    }
  }

  public static void main(String[] args) 
  {
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.nextLine());
    
    Duende[] duendes = new Duende[n];

    for (int i = 0; i < n; i++) 
    {
     duendes[i] = duendes[i].parseDuende(sc.nextLine()); 
    }

    insertionSort(duendes, n);

    for (int i = 0; i < n; i++) 
    {
     System.out.println(duendes[i].getNome() + " | " + duendes[i].getProducao()); 
    }
  }
}
