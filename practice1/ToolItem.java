package practice1;

import java.text.SimpleDateFormat;
import java.util.Date;

public class ToolItem {
  
  private String title;
  private String detail;
  private Date reg_date;

  public ToolItem(String title, String detail) {
    this.title = title;
    this.detail = detail;
    this.reg_date = new Date(); // new Date() 는 현재 시간을 기록할 수 있다고 함
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

  public Date getReg_date() {
    return reg_date;
  }

  public void setReg_date(Date reg_date) {
    this.reg_date = reg_date;
  }

  @Override
  public String toString(){
    return "[" + "title" + "] " + detail + " - " + new SimpleDateFormat("yyyy/MM/dd.").format(reg_date);
  }


  
}
