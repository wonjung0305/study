public class AboutPrint{
  public static void main(String[] args){ // 프로그램의 시작점
    // public 어디서든 접근 가능
    // static 객체를 생성하지 않아도 실행 가능
    // void return 값 없음
    // String[] args 명령줄 인자를 배열로 받음(String 타입)

    String name = "김원중";
    int birth = 2003;
    double height = 168.8888;

    // Java는 System.out 이라는 출력 스트림을 이용해 콘솔에 출력
    // out은 PrintStream 타입의 객체
    System.out.println("This is a println"); // 줄 바꿈 (\n) 포함
    System.out.println("==========");
    System.out.print("This is just print"); // 줄 바꿈 없이 출력
    System.out.print("And use \\n\n");
    System.out.println("==========");
    System.out.printf("name: %s, birth: %d, height: %.1f\n", name, birth, height); // 형식 지정자로 출력
    System.out.println("==========");
    System.out.println("name: " + name + " " + "birth: " + birth); // " " 안에 문자열을 넣고 + 변수로 연결
    System.out.println("==========");
    System.out.println("println을 사용할 때 소수점을 출력하고 싶을 때 String.format() 사용");
    System.out.println("String.format은 결과를 문자열로 만들어 줌");
      // String result = String.format("점수: %.1f", score);
      // System.out.println(result);
  }
}