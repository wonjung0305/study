package practice3;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Tool {
  private String title;
  private String detail;
  private Date new_date;

  public Tool(String title, String detail){
    this.title = title;
    this.detail = detail;
    new_date = new Date();
  }

  public String getTitle() {
    return title;
  }
  public void setTitle(String title) {
    this.title = title;
  }
  public String getDetail() {
    return detail;
  }
  public void setDetail(String detail) {
    this.detail = detail;
  }
  public Date getNew_date() {
    return new_date;
  }
  public void setNew_date(Date new_date) {
    this.new_date = new_date;
  }

  @Override
  public String toString(){
    return "[" +  title +"] " + detail + " - " + new SimpleDateFormat("yyyy/MM/dd").format(new_date); 
  }

  
}
