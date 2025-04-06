public class AboutVariable {
  // 변수(variable)는 데이터(값)를 저장할 수 있는 메모리 공간에 붙인 이름
  // 변수를 사용하기 전에 자료형을 지정해야 함
  // int(정수), double(실수), boolean(참/거짓), char(문자 한 글자)
  // 참조 자료형(Reference type)
    // String: 문자열을 저장하는 클래스

  public static void main(String[] args) {
    int age = 23;
    double height = 168.5;
    boolean isStudent = true;
    char grade = 'A';
    String name = "김원중";

    System.out.println("이름: " + name);
    System.out.println("나이: " + age);
    System.out.println("키: " + height + "cm");
    System.out.println("학생 여부: " + isStudent);
    System.out.println("학점: " + grade);

  } 
}
