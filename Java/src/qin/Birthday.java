package qin;

/**
 * Question 17、 定义一个Birthday类是某个人的生日,有三个int属性: 年、月、日。并建立方法判断两个生日的人谁的年龄大。
 * public Birthday big(Birthday b1, Birthday b2){}
 * */
public class Birthday {
	private int year;
	private int month;
	private int day;

	public Birthday() {
	}

	public Birthday(int year, int month, int day) {
		super();
		this.year = year;
		this.month = month;
		this.day = day;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public int getMonth() {
		return month;
	}

	public void setMonth(int month) {
		this.month = month;
	}

	public int getDay() {
		return day;
	}

	public void setDay(int day) {
		this.day = day;
	}
	
	public Birthday big(Birthday b1, Birthday b2){
		if (b1.getYear() < b2.getYear() ){
			return b1;
		}else if (b1.getYear() > b2.getYear()){
			return b2;
		}else{
			if (b1.getMonth()< b2.getMonth()){
				return b1;
			}else if (b1.getMonth() > b2.getMonth()){
				return b2;
			}else{
				if (b1.getDay() < b1.getDay()){
					return b1;
				}else if (b1.getDay() > b2.getDay()){
					return b2;
				}else{
					return b1;
				}
			}
		}
		
	}
	
	public String toString(){
		return "year:" + year + " month:" + month + " day:" + day;
	}
	
	public static void main(String[] args){
		Birthday b1 = new Birthday(1970, 5, 9);
		Birthday b2 = new Birthday(1971, 8, 9);
		System.out.println(b1.big(b1, b2));
		
	}
	

}
