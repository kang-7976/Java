import java.lang.Override;

class Father {
  protected String name;

  public void MiniFather() {
    System.out.println("hello " + name);
  }
}

class son extends Father {
  public void Test() {
    this.name = "Jack";
  }
}

public class Main {
  public static void main(String[] args) {
    son s = new son();
    s.Test();
    s.MiniFather();
  }
}

