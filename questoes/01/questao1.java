import java.util.Scanner;

class Criancas 
{
  private String nome;
  private String bairro;

  Criancas(String nome, String bairro)
  {
    this.nome = nome;
    this.bairro = bairro;
  }
  
  public static Criancas parseCriancas(String s)
  {
    String[] campos = s.split(";");

    String nome = campos[0];
    String bairro = campos[1];
    
    return new Criancas(nome, bairro);
  } 

  public String getBairro()
  {
    return bairro;
  }

  public String getNome()
  {
    return nome;
  }
}
public class questao1
{
  static void imprimirArray(Criancas[] criancas) 
  {
    for (int i = 0; i < criancas.length; i++) 
    {
     System.out.println(criancas[i].getBairro() + " | " + criancas[i].getNome()); 
    }
  }
  
  static void selectionSort(Criancas[] criancas)
  {
    for (int i = 0; i < criancas.length - 1; i++) 
    {
      int menor = i;
        for(int j = i + 1; j < criancas.length; j++)
        {
          int cmpBairro = criancas[menor].getBairro().compareTo(criancas[j].getBairro());
          if(cmpBairro > 0)
          {
            menor = j;

          }
          else if(cmpBairro == 0 && criancas[menor].getNome().compareTo(criancas[j].getNome()) > 0)
          {
            menor = j;
          }
        }
        Criancas aux = criancas[menor];
        criancas[menor] = criancas[i];
        criancas[i] = aux;
    }
  } 

  public static void main(String[] args) 
  {
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.nextLine());
    Criancas[] array = new Criancas[n];
    for(int i = 0; i < n; i++) 
    {
      String s = sc.nextLine();
      array[i] = Criancas.parseCriancas(s);
    }

    selectionSort(array);

    imprimirArray(array);
  }
}
