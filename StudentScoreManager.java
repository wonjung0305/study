import java.util.HashMap;

public class StudentScoreManager {
    private HashMap<String, Integer> scores = new HashMap<>();

    // Create - 학생 추가
    public void addScore(String name, int score) {
        scores.put(name, score);
    }

    // Read - 점수 조회
    public Integer getScore(String name) {
        return scores.get(name);
    }

    // Update - 점수 수정
    public void updateScore(String name, int newScore) {
        if (scores.containsKey(name)) {
            scores.put(name, newScore);
        } else {
            System.out.println(name + " 학생이 존재하지 않습니다.");
        }
    }

    // Delete - 학생 삭제
    public void removeScore(String name) {
        if (scores.containsKey(name)) {
            scores.remove(name);
        } else {
            System.out.println(name + " 학생이 존재하지 않습니다.");
        }
    }

    // 모든 학생 출력
    public void printAllScores() {
        for (String name : scores.keySet()) { // keySet() 모든 키드말 모아놓음
            System.out.println(name + ": " + scores.get(name));
        }

        /*
            for (Map.Entry<String, Integer> entry : map.entrySet()) {
                System.out.println(entry.getKey() + ": " + entry.getValue());
            }
         */
    }

    // 테스트용 main
    public static void main(String[] args) {
        StudentScoreManager manager = new StudentScoreManager();
        manager.addScore("Alice", 90);
        manager.addScore("Bob", 85);

        System.out.println("Bob's score: " + manager.getScore("Bob"));

        manager.updateScore("Bob", 95);
        manager.removeScore("Alice");

        manager.printAllScores();
    }
}
