package practice2;

import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Main main = new Main();
    main.run();
  }

  public void displayHelp() {
    System.out.println("Usage of commands");
    System.out.println("1. Add a new item (add)");
    System.out.println("2.Delete an existing item (delete)");
    System.out.println("3. Update an item (edit)");
    System.out.println("4. List all items (ls)");
    System.out.println("5. sort the list by name (ls name)");
    System.out.println("6. sort the list by name descending (ls name desc)");
    System.out.println("7. sort the list by date (ls date desc)");
    System.out.println("8. sort the list by date descending (ls date desc)");
    System.out.println("9. show commands guidelines (?) ");
    System.out.println("10. quit program (exit)");
  }

  void run() {
    Scanner sc = new Scanner(System.in);
    TodoCRUD manager = new TodoCRUD();
    boolean quit = false;

    do {
      System.out.print("> ");
      String line = sc.nextLine();
      String choice = line.split(" ")[0]; // 공백 기준으로 자르고 제일 앞 다 ㄴ어 들고옴

      switch (choice) {
        case "add": // add 포함되면 실행
          manager.addItem();
          break;
        case "del": // del 포함하면 실행
          manager.delItem();
          break;
        case "edit": // edit 포함되면 실행
          manager.updateItem();
          break;
        case "ls": // ls를 넣고 name date desc에 따라 다르게 분류하고 전체 출력
          if (line.contains("name"))
            manager.sortByName();
          if (line.contains("date"))
            manager.sortByDate();
          if (line.contains("desc"))
            manager.reverseList();
          manager.listItem();
          break;
        case "?": // 명령어 뭐 있는지 리스트 출력
          displayHelp();
          break;
        case "exit": // 프로그램 나가기
          quit = true; // 나가기 위해 true로 바꿈
          break;
        default: // 잘못 입력한 경우
          System.out.println("? for help.");
          break;
      }
    } while (!quit); // flase일 때 동안 계속 반복됨
    sc.close();
  }
}
