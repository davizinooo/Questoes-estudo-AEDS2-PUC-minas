import java.util.Scanner;

class Registro
{
  private String nome;
  private int matricula;
  private int turma;

  Registro(int matricula, String nome, int turma)
  {
      this.matricula = matricula;
      this.nome = nome;
      this.turma = turma;
  }

  public static Registro parseRegistro(String s)
  {
    String[] campos = s.split(";");

    int matricula = Integer.parseInt(campos[0]);
    String nome = campos[1];
    int turma = Integer.parseInt(campos[2]);

    return new Registro(matricula, nome, turma);
  }

  public String getNome()
  {
    return nome;
  }
  
  public int getMatricula()
  {
    return matricula;
  }

  public int getTurma()
  {
    return turma;
  }
}

class questao2
{
  static void selectionSort(Registro[] estudantes, int n, int funcao)
  {
    for (int i = 0; i < n - 1; i++) 
    {
      int menor = i;
      for (int j = i + 1; j < n; j++) 
      {
        if(funcao == 0)
        {
          if(estudantes[menor].getTurma() > estudantes[j].getTurma())
          {
            menor = j;
          }
        }
        else if(funcao == 1)
        {
          if(estudantes[menor].getNome().compareTo(estudantes[j].getNome()) > 0)
          {
            menor = j;
          }
        }
        else if(funcao == -1) 
        {
          if(estudantes[menor].getMatricula() > estudantes[j].getMatricula())
          {
            menor = j;
          }
        }
      }
      Registro aux = estudantes[i];
      estudantes[i] = estudantes[menor];
      estudantes[menor] = aux;
    }
  }


  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    
    int n = Integer.parseInt(sc.nextLine());
    Registro[] estudantes = new Registro[n];
    for (int i = 0; i < n; i++) 
    {
      String pessoa = sc.nextLine();
      estudantes[i] = Registro.parseRegistro(pessoa);
    }
    
    selectionSort(estudantes, n, 0);
    selectionSort(estudantes, n, 1);
    selectionSort(estudantes, n, -1);

    for (int i = 0; i < n; i++) 
    {
      System.out.println(estudantes[i].getMatricula() + " | " + estudantes[i].getNome() + " | " + estudantes[i].getTurma());    
    }
  }
}

