package practice7;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.*;

public class TodoCRUD implements ICRUD {
  ArrayList<Tool> list;
  Scanner sc = new Scanner(System.in);

  public TodoCRUD(){
    list = new ArrayList<Tool>();
  }

  @Override
  public int addItem(){

    String title;
    System.out.print("Add a Todo item\nEnter the title: ");
    title = sc.nextLine().trim();

    if(isDuplicated(title)){
      System.out.println("Title can't be duplicated");
      return 0;
    }

    System.out.print("Enter the detail: ");
    String detail = sc.nextLine().trim();

    Tool addTool = new Tool(title, detail);
    list.add(addTool);
    System.out.println("Item added.");

    return 1;
  }

  boolean isDuplicated(String title){
    for(Tool item: list){
      if(item.getTitle().equals(title)){
        return true;
      }
    }
    return false;
  }

  @Override
  public void listItem(){
    System.out.println("Total " + list.size() + " items");
    for(Tool item: list){
      System.out.println(item.toString());
    }
  }

  @Override
  public int delItem(){

    String title;
    System.out.println("Delete a Todo Item");
    System.out.print("Enter the title of the item to delete: ");
    title = sc.nextLine().trim();

    Tool delItem = null;
    for(int i = 0; i < list.size(); i++){
      if(title.equals(list.get(i).getTitle())){
        delItem = list.get(i);
        break;
      }
    }

    if(delItem == null){
      System.out.println("Not Found");
      return 0;
    }

    System.out.println(delItem.toString());
    list.remove(delItem);
    System.out.println("Item deleted");

    return 1;
  }

  @Override
  public int editItem(){
    String title;

    System.out.println("Edit a Todo Item");
    System.out.print("Enter the title of the item to edit: ");
    title = sc.nextLine().trim();

    Tool editTool = null;
    for(Tool item: list){
      if(item.getTitle().equals(title)){
        editTool = item;
        break;
      }
    }

    if(editTool == null){
      System.out.println("Not Found");
      return 0;
    }

    System.out.print("Enter the detail: ");
    String detail = sc.nextLine().trim();

    editTool.setDetail(detail);
    System.out.println("Item updated");

    return 1;
  }

  public void sortByName(){
    Collections.sort(list,new TodoToolNameComparator());
  }
  public void sortByDate(){
    Collections.sort(list,new TodoToolDateComparator());
  }
  public void reverseList(){
    Collections.reverse(list);
  }

  class TodoToolNameComparator implements Comparator<Tool>{
    @Override
    public int compare(Tool o1, Tool o2){
      return o1.getTitle().compareTo(o2.getTitle());
    }
  }

  class TodoToolDateComparator implements Comparator<Tool>{
    @Override
    public int compare(Tool o1, Tool o2){
      return o1.getNew_date().compareTo(o2.getNew_date());
    }
  }


  
}
