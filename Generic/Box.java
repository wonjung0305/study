package Generic;
public class Box<T> {

  private T value;

  public Box(T value){ // T는 type 파라미터를 말함
    this.value = value;
  }

  public void printMessage(){
    System.out.println("This box has the value, " + value + ".");
  }

}