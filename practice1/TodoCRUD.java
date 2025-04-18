package practice1;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.*;

public class TodoCRUD implements ICRUD {
  private ArrayList<ToolItem> list;
  private Scanner sc;

  public TodoCRUD() {
    this.list = new ArrayList<ToolItem>();
    sc = new Scanner(System.in);
  }

  @Override
  public int addItem() {
    String title, desc;

    System.out.print("Add a Todo item\n" + "Enter the title: ");
    title = sc.nextLine().trim();

    if (isDuplicated(title)) {
      System.out.println("Title can't be duplicated.");
      return 0;
    }

    System.out.print("Enter the detail: ");
    desc = sc.nextLine().trim();

    ToolItem addItem = new ToolItem(title, desc);
    list.add(addItem);
    System.out.println("Item added");

    return 1; // 1은 데이터를 넣었다, 0은 안넣어졌다
  }

  @Override
  public void listItem() {
    System.out.println("Total " + list.size() + " items");
    for (int i = 0; i < list.size(); i++) {
      System.out.println(list.get(i).toString());
    }

    /*
     * System.out.println("Total " + this.list.size() + " items"); // 몇 개 있는지
     * for(ToolItem item : this.list){ // 전체 출력
     * System.out.println(item.toString());
     * }
     */
  }

  @Override
  public int delItem() {
    String title;
    System.out.println("Delete a Todo Item");
    System.out.print("Enter the title of the item to remove: ");
    title = sc.nextLine().trim();

    ToolItem delItem = null;
    for (ToolItem item : list) {
      if (item.getTitle().equals(title)) {
        delItem = item;
        break;
      }
    }

    if (delItem == null) {
      System.out.println("Not Found");
      return 0;
    }

    System.out.println(delItem.toString());
    list.remove(delItem);
    System.out.println("Item deleted.");

    return 1; // 정상 삭제
  }

  @Override
  public int updateItem() {
    String title;
    System.out.println("Edit a Todo Item");
    System.out.print("Enter the title of the item to edit: ");
    title = sc.nextLine().trim();

    ToolItem editItem = null;
    for(ToolItem item : list){
      if(item.getTitle().equals(title)){
        editItem = item;
        break;
      }
    }

    if(editItem == null){
      System.out.println("Not found.");
      return 0;
    }

    System.out.println(editItem.toString());

    System.out.print("Enter the detail ");
    String detail = sc.nextLine().trim();
    editItem.setDetail(detail);
    System.out.println("Item updated.");

    return 1;
  }

  boolean isDuplicated(String title) {
    for (ToolItem item : list) {
      if (title.equals(item.getTitle())) {
        return true;
      }
    }
    return false;
  }

  public void sortByName(){
    Collections.sort(list, new TodoitemNameComparator());
  }
  public void sortByDate(){
    Collections.sort(list, new TodoitemDateComparator());
  }
  public void reverseList(){
    Collections.reverse(list);
  }

  class TodoitemNameComparator implements Comparator<ToolItem>{
    @Override
    public int compare(ToolItem o1, ToolItem o2){
      return o1.getTitle().compareTo(o2.getTitle());
    }
  }

  class TodoitemDateComparator implements Comparator<ToolItem>{
    @Override
    public int compare(ToolItem o1, ToolItem o2){
      return o1.getReg_date().compareTo(o2.getReg_date());
    }
  }

}
