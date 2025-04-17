import java.util.ArrayList;

public class TodoList {
    private ArrayList<String> todos = new ArrayList<>();

    // 항목 추가
    public void addTodo(String item) {
        todos.add(item);
    }

    // 항목 삭제
    public void deleteTodo(int index) {
        todos.remove(index);
    }

    // 모든 항목 출력
    public void printTodos() {
        for(int i = 0; i < todos.size(); i++){
            System.out.println(todos.get(i));
        }
    }

    public static void main(String[] args) {
        TodoList list = new TodoList();
        list.addTodo("스터디 자료 정리");
        list.addTodo("Java 시험 공부");
        list.addTodo("친구 생일 선물 구매");

        list.deleteTodo(1); // "Java 시험 공부" 삭제

        list.printTodos();  // 남은 항목 출력
    }
}