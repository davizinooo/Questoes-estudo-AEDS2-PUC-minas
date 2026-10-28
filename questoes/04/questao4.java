import java.util.Scanner;

class Carros
{
  private String marca;
  private String modelo;
  private int ano;
  private int id;

  Carros(String marca, String modelo, int ano, int id)
  {
    this.marca = marca;
    this.modelo = modelo;
    this.ano = ano;
    this.id = id;
  }

  public static Carros parseCarros(String s) 
  {
    String[] campos = s.split(";");
    int id = Integer.parseInt(campos[0]);
    String modelo = campos[2];
    String marca = campos[1];
    int ano = Integer.parseInt(campos[3]);

    return new Carros(marca, modelo, ano, id);
  }

  public String getMarca()
  {
    return marca;
  }
  public String getModelo()
  {
    return modelo;
  }
  public int getAno()
  {
    return ano;
  }
  public int getId()
  {
    return id;
  }
}

class questao4
{
  static void insertionSort(Carros[] carros, int n)
  {
    for (int i = 1; i < n; i++) 
    {
      Carros chave = carros[i];
      int j = i - 1;
      while(j >= 0 && (carros[j].getMarca().compareTo(chave.getMarca()) > 0 ||
                      (carros[j].getMarca().compareTo(chave.getMarca()) == 0 &&
                       carros[j].getModelo().compareTo(chave.getModelo()) > 0) ||
                      (carros[j].getModelo().compareTo(chave.getModelo()) == 0 &&
                       carros[j].getMarca().compareTo(chave.getMarca()) == 0 &&
                       carros[j].getId() < chave.getId())))
      {
        carros[j + 1] = carros[j];
        j--;
      }
      carros[j + 1] = chave;
    }
  }

  static void imprimirArray(Carros[] carros, int n)
  {
    for (int i = 0; i < n; i++) 
    {
      System.out.println(carros[i].getId() + " ## " + carros[i].getMarca() + " ## " + carros[i].getModelo() + " ## " + carros[i].getAno());
    }
  }

  public static void main(String[] args) 
  {
    Scanner sc = new Scanner(System.in);
    int n = 0;
    n = Integer.parseInt(sc.nextLine());

    Carros[] carros = new Carros[n];
    
    for (int i = 0; i < n; i++) 
    {
      carros[i] = Carros.parseCarros(sc.nextLine());
    }

    insertionSort(carros, n);

    imprimirArray(carros, n);
  }
}
