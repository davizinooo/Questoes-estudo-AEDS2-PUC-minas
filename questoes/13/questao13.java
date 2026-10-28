import java.util.Scanner;

class Registro
{
  private String codigo;
  private String carga;

  Registro(String codigo, String carga)
  {
    this.codigo = codigo;
    this.carga = carga;
  }

  static Registro parseRegistro(String s)
  {
    String[] campos = s.split(";");

    String codigo = campos[0];
    String carga = campos[1];

    return new Registro(codigo, carga);
  }

  String getCodigo()
  {
    return codigo;
  }

  String getCarga()
  {
    return carga;  
  }
}

class Celula 
{
  Registro elemento;
  Celula prox;

  Celula(Registro elemento)
  {
    this.elemento = elemento;
    this.prox = null;
  }
}

class Lista 
{
  Celula primeiro;
  Celula ultimo;

  Lista()
  {
    primeiro = new Celula(null);
    ultimo = primeiro;
  }

  void inserirInicio(Registro x)
  {
    Celula nova = new Celula(x);

    nova.prox = primeiro.prox;
    primeiro.prox = nova;
  }

  void inserirFim(Registro x)
  {
    Celula nova = new Celula(x);

    ultimo.prox = nova;
    ultimo = nova;
  }

  void inserirPos(Registro x, int pos)
  {
    Celula ant = primeiro;
    Celula nova = new Celula(x);

    for(int i = 0; i < pos; i++)
    {
      if(ant.prox == null)
      {
        return;
      }
      ant = ant.prox;
    }

    nova.prox = ant.prox;
    ant.prox = nova;
    
    if(ant == ultimo)
    {
      ultimo = nova;
    }
  }

  Registro removerInicio()
  {
    //vazia
    if(primeiro == ultimo)
    {
      return null;
    }
    
    Registro resp = primeiro.prox.elemento;

    
    //um elemento
    if(primeiro.prox == ultimo)
    {
      ultimo = primeiro;
    }


    //remover da lista
    primeiro.prox = primeiro.prox.prox;


    return resp;
  }

  Registro removerFim()
  {
    //vazia
    if(primeiro == ultimo)
    {
      return null;
    }

    Celula i;
    Registro resp = ultimo.elemento;

    for(i = primeiro; i.prox.prox != null; i = i.prox);
   
    i.prox = null;
    ultimo = i;

    return resp;
  }

  Registro removerPos(int pos)
  {
    //vazio
    if(primeiro == ultimo)
    {
      return null;
    }

    Celula ant = primeiro;
    
    for(int i = 0; i < pos; i++)
    {
      //pos invalida
      if(ant.prox == null)
      {
        return null;
      }
      ant = ant.prox;
    }
    //sem elemento na posicao
    if(ant.prox == null)
    {
      return null;
    }
    
    Registro resp = ant.prox.elemento;
    
    //se estamos removendo o ultimo
    if(ant.prox == ultimo)
    {
      ultimo = ant;
    }

    ant.prox = ant.prox.prox;

    return resp;
  }

  void imprimirLista()
  {
    Celula aux;
    int i = 0;
    for (aux = primeiro.prox; aux != null; aux = aux.prox) 
    {
      System.out.println("[" + i + "]" + aux.elemento.getCodigo() + " " + aux.elemento.getCarga());
      i++;
    }
  }
}

class questao13 
{
  public static void main(String[] args) 
  {
    Lista lista = new Lista();

    Scanner sc = new Scanner(System.in);

    int n = Integer.parseInt(sc.nextLine());

    for (int i = 0; i < n; i++) 
    {
      String s = sc.nextLine();
      Registro aux = Registro.parseRegistro(s);
      lista.inserirFim(aux);
    }

    n = Integer.parseInt(sc.nextLine());

    for (int i = 0; i < n; i++) 
    {
      String[] campos = sc.nextLine().split(" ");
      String cmd = campos[0];
    
      if(cmd.equals("II"))
      {
        Registro aux = Registro.parseRegistro(campos[1]);
        lista.inserirInicio(aux);
      }
      else if(cmd.equals("IF"))
      {
        Registro aux = Registro.parseRegistro(campos[1]);
        lista.inserirFim(aux);
      }
      else if(cmd.equals("R*"))
      {
        int pos = Integer.parseInt(campos[1]);
        Registro r = lista.removerPos(pos);

        System.out.println("(R)" + r.getCodigo() + " " + r.getCarga());
      }
    }

    lista.imprimirLista();
  }
}
