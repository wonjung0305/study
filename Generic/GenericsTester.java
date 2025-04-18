package Generic;
import java.util.ArrayList;

public class GenericsTester {

    public static void main(String[] args) {
        GenericsTester myTester = new GenericsTester();
        myTester.run();
    }

    public void run() {
        ArrayList<Box<Integer>> boxesForInteger = new ArrayList<Box<Integer>>();

        Box<Integer> box1 = new Box<Integer>(12);
        Box<Integer> box2 = new Box<Integer>(14);
        Box<Integer> box3 = new Box<Integer>(17);

        boxesForInteger.add(box1);
        boxesForInteger.add(box2);
        boxesForInteger.add(box3);

        for (Box<Integer> box : boxesForInteger) {
            box.printMessage();
        }

        ArrayList<Box<String>> boxesForString = new ArrayList<Box<String>>();

        Box<String> boxForStr1 = new Box<String>("JC");
        Box<String> boxForStr2 = new Box<String>("JH");
        Box<String> boxForStr3 = new Box<String>("BR");

        boxesForString.add(boxForStr1);
        boxesForString.add(boxForStr2);
        boxesForString.add(boxForStr3);

        for (Box<String> box : boxesForString) {
            box.printMessage();
        }
        
        /*
        * ArrayList<Box> boxesForEveryTypes = new ArrayList<Box>();
                boxesForEveryTypes.add(box1);
                boxesForEveryTypes.add(boxForStr2);
                for (Box<String> box : boxesForEveryTypes) {
                    box.printMessage();
                }
        */
        
    }

}