import java.util.Scanner;

class Contato
{
  private int telefone;
  private String nome;

  public Contato(int telefone, String nome)
  {
    this.telefone = telefone;
    this.nome = nome;
  }
  
  public static Contato parseContato(String s) 
  {
    String[] campos = s.split(";");

    String nome = campos[0];
    int telefone = Integer.parseInt(campos[1]);

    return new Contato(telefone, nome);
  }

  public int getTelefone()
  {
    return telefone;
  }

  public String getNome()
  {
    return nome;
  }
}

class Lista
{
  private Contato[] array;
  private int n;

  public Lista(int tamanho) 
  {
    array = new Contato[tamanho];
    n = 0;
  }

  public void inserirInicio(Contato x)
  {
    n++;
    for (int i = 1; i < n; i++) 
    {
     array[i] = array[i - 1];
    }
    array[0] = x;
  }

  public void inserirFim(Contato x)
  {
    array[n] = x;
    n++;
  }

  public void removerInicio()
  {
    Contato rm = array[0];
    for(int i = 0; i < n; i++) 
    {
      array[i] = array[i + 1];
    }
    n--;
    System.out.println("(R) " + rm.getNome() + " " + rm.getTelefone());
  }

  public void removerFim()
  {
    Contato rm = array[n - 1];
    n--;
    System.out.println("(R) " + rm.getNome() + " " + rm.getTelefone());
  }

  public void removerPos(int pos)
  {
    Contato rm = array[pos];
    for (int i = pos; i < n; i++) 
    {
     array[i] = array[i + 1]; 
    }
    n--;

    System.out.println("(R) " + rm.getNome() + " " + rm.getTelefone());
  }

  public void inserirPos(int pos, Contato x)
  {
    n++;
    for (int i = n; i > pos; i--) 
    {
      array[i] = array[i - 1];
    }
    array[pos] = x;
  }

  public void imprimirLista()
  {
    for (int i = 0; i < n; i++) 
    {
      System.out.println("[" + i +"] " + array[i].getNome() + " " + array[i].getTelefone());  
    }
  }
}

class questao12 
{
  public static void main(String[] args) 
  {
   Scanner sc = new Scanner(System.in);
   int n = Integer.parseInt(sc.nextLine());
   Lista lista = new Lista(100);

   for (int i = 0; i < n; i++) 
   {
    lista.inserirFim(Contato.parseContato(sc.nextLine()));
   }
  
   int qntC = Integer.parseInt(sc.nextLine());
   for (int i = 0; i < qntC; i++) 
   {
    String[] cmd = sc.nextLine().split(" ");
    if(cmd[0].compareTo("I*") == 0)
    {
      lista.inserirPos(Integer.parseInt(cmd[1]),Contato.parseContato(cmd[2]));
    }
    else if(cmd[0].compareTo("RF") == 0)
    {
      lista.removerFim();
    }
    else if(cmd[0].compareTo("RI") == 0)
    {
      lista.removerInicio();
    }
   }

   lista.imprimirLista();
  }
}
