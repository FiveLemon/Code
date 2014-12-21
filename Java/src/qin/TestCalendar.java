package qin;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
/**
 * Question 24、Calendar类
 *	通过Calendar类查看自己出生的那一天是星期几?
 * */
public class TestCalendar {
	private SimpleDateFormat pattern;
	private Calendar calendar;
	
	public TestCalendar(){
		pattern = new SimpleDateFormat("yyyy-MM-dd");
		calendar = Calendar.getInstance();
	}
	
	public int setBirthday(String birthday){
		Date date = null;
		try {
			date = pattern.parse(birthday);
			System.out.println(date);
		} catch (ParseException e) {
			e.printStackTrace();
		}
		System.out.println(date.getYear());
		calendar.set(date.getYear(), date.getMonth() + 1, date.getDay());
		System.out.println(calendar);
//		System.out.println(calendar.get(Calendar.DAY_OF_MONTH));
		System.out.println(calendar.get(Calendar.DAY_OF_WEEK));
//		System.out.println(calendar.get(Calendar.DAY_OF_WEEK_IN_MONTH));
//		System.out.println(calendar.get(Calendar.DAY_OF_YEAR));
		return calendar.get(Calendar.DAY_OF_MONTH);
	}

	public static void main(String[] args) {
		TestCalendar test = new TestCalendar();
		System.out.println(test.setBirthday("2014-12-20"));
	}

}
