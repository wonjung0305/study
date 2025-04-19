package practice2;

import java.util.*;

public class TodoCRUD implements ICRUD {
  Scanner sc = new Scanner(System.in);
  ArrayList<ToolItem> list;

  public TodoCRUD() {
    list = new ArrayList<ToolItem>();
  }

  @Override
  public int addItem() {
    String title, detail;

    System.out.print("Add a Todo item\n" + "Enter the title: ");
    title = sc.nextLine().trim();

    if (isDuplicated(title)) {
      System.out.println("Title can't be duplicated.");
      return 0;
    }

    System.out.print("Enter the detail: ");
    detail = sc.nextLine().trim();

    ToolItem addItem = new ToolItem(title, detail);
    list.add(addItem);

    System.out.println("Item added");
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

  @Override
  public void listItem(){
    System.out.println("Total " + list.size() + " items");
    for(ToolItem item: list){
      System.out.println(item.toString());
    }
  }

  @Override
  public int delItem(){
    String title;
    System.out.print("Enter the title of the item to remove: ");
    title = sc.nextLine().trim();

    ToolItem deleteTool = null;
    for(ToolItem item : list){
      if(item.getTitle().equals(title)){
        deleteTool = item;
        break;
      }
    }

    if(deleteTool == null){
      System.out.println("Not Found.");
      return 0;
    }

    System.out.println(deleteTool.toString());
    list.remove(deleteTool);
    System.out.println("Item deleted.");

    return 1;
  }

  @Override
  public int updateItem(){
    String title;

    System.out.print("Enter the title of the item to edit: ");
    title = sc.nextLine().trim();

    ToolItem editTool = null;
    for(int i = 0; i < list.size(); i++){
      if(title.equals(list.get(i).getTitle())){
        editTool = list.get(i);
        break;
      }
    }

    if(editTool == null){
      System.out.println("Not found.");
      return 0;
    }

    System.out.println(editTool.toString());

    System.out.print("Enter the detail ");
    String detail = sc.nextLine().trim();
    editTool.setDetail(detail);

    System.out.println("Item updated.");

    return 1;
  }

  public void sortByName(){
    Collections.sort(list,new TodoitemNameComparator());
  }
  public void sortByDate(){
    Collections.sort(list,new TodoitemDateComparator());
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
