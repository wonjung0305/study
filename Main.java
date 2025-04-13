

public class Main{
  public static void main(String[] args) {
    Main main = new Main();
    String name = "Kim, Wonjung";
    int age = 23;
    main.run(name);
    main.run(name, age);
  }

    void run(String name){ // overloading
      System.out.println("Hi, my name is " + name);
    
    } 
    void run(String name, int age ){
      System.out.println("Hi, my name is " + name);
      System.out.println("And I'm " + age + "years old");
    }
}
