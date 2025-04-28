package practice8;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Tool {
  private String title;
  private String detail;
  private Date date;

  public Tool(String title, String detail) {
    this.title = title;
    this.detail = detail;
    date = new Date();
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

  public Date getDate() {
    return date;
  }

  public void setDate(Date date) {
    this.date = date;
  }

  @Override
  public String toString() {
    return "[" + title + "] " + detail + " - " + new SimpleDateFormat("yyyy/MM/dd").format(date);
  }

}
