public class AboutConditional {
  public static void main(String[] args){
    // 조건문
    // 특정 조건이 참일 때만 실행되는 코드

    int score = 85;

    if(score >= 90) System.out.println('A');
    else if(score >= 80) System.out.println('B');
    else if(score >= 70) System.out.println('C');
    else System.out.println('F');

    // 사용되는 연산자 
      // == 같다 , != 다르다
      // >, <, >=, <=  크기비교
      // &&, ||, ! 논리 연산자도 사용 가능
    // 중괄호는 한 줄 실행일 때는 생략 가능
  }
}
