import java.util.Scanner;

class Registro 
{
  private int nivel;
  private String codigo;
  private String descricao;

  Registro(int nivel, String codigo, String descricao)
  {
    this.nivel = nivel;
    this.codigo = codigo;
    this.descricao = descricao;
  }

  public static Registro parseRegistro(String s)
  {
    String[] campos = s.split(";");

    int nivel = Integer.parseInt(campos[2]);
    String codigo = campos[1];
    String descricao = campos[0];

    return new Registro(nivel, codigo, descricao);
  }

  public int getNivel()
  {
    return nivel;
  }
  public String getCodigo()
  {
    return codigo;
  }
  public String getDescricao()
  {
    return descricao;
  }
}

class questao6
{
  static void countingSort(Registro[] array, int n)
  {
    int maior = array[0].getNivel();
    //maior
    for (int i = 1; i < n; i++) 
    {
      if(array[i].getNivel() > maior)
      {
        maior = array[i].getNivel();
      }
    }
    //inicializar contador
    int[] count = new int[maior + 1];
    for (int i = 0; i <= maior; i++) 
    {
      count[i] = 0;
    }
    
    //countar
    for (int i = 0; i < n; i++) 
    {
      count[array[i].getNivel()]++;
    }

    //conta acumulada 
    for (int i = 1; i <= maior; i++) 
    {
      count[i] += count[i - 1];  
    }

    Registro[] aux = new Registro[n];
    
    //escrever array
    for (int i = n - 1; i >= 0; i--) 
    {
      aux[count[array[i].getNivel()] - 1] = array[i];
      count[array[i].getNivel()]--;
    }

    for (int i = 0; i < n; i++) 
    {
     array[i] = aux[i]; 
    }
  }

  static void imprimirArray(Registro[] array, int n)
  {
    for (int i = 0; i < n; i++) 
    {
     System.out.println(array[i].getNivel() + " | " + array[i].getCodigo() + " | " + array[i].getDescricao()); 
    }
  }

  public static void main(String[] args) 
  {
    Scanner sc = new Scanner(System.in);
    int n = 0;
    n = Integer.parseInt(sc.nextLine());

    Registro[] registros = new Registro[n];

    for (int i = 0; i < n; i++) 
    {
      registros[i] = Registro.parseRegistro(sc.nextLine());  
    }

    countingSort(registros, n);
    imprimirArray(registros, n);
  }
}
