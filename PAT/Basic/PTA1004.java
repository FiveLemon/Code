package source.PTA;

import java.util.ArrayList;
import java.util.Scanner;

public class PTA1004 {
	private int number;
	class Student{
		private String name;
		private String ID;
		public String getName() {
			return name;
		}
		public void setName(String name) {
			this.name = name;
		}
		public String getID() {
			return ID;
		}
		public void setID(String iD) {
			ID = iD;
		}
		public int getScore() {
			return score;
		}
		public void setScore(int score) {
			this.score = score;
		}
		private int score;
		public Student(String name, String ID, int score)
		{
			this.name = name;
			this.ID = ID;
			this.score = score;
		}
		public String toString()
		{
			return name+" "+ID;
		}
		
	}
	private ArrayList<Student> student;
	public PTA1004(int num)
	{
		number = num;
		student = new ArrayList<Student>();
	}
	public int getNumber()
	{
		return number;
	}
	public String getStudent()
	{
		return student.toString();
	}
	public void getMaxMinStudent()
	{
		int score_max = Integer.MIN_VALUE;
		Student student_max = student.get(0);
		Student student_min = student.get(0);
		int score_min = Integer.MAX_VALUE;
		for(Student a: student)
		{
			if (a.getScore() > score_max)
			{
				score_max = a.getScore();
				student_max = a;
			}
			if(a.getScore() < score_min)
			{
				score_min = a.getScore();
				student_min = a;
			}
			
		}
		System.out.println(student_max);
		System.out.println(student_min);
			
	}

	public void getIn(String name, String ID, int score)
	{
		Student temp = new Student(name, ID, score);
		student.add(temp);
		
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int counter = 0;
		int number = sc.nextInt();
		PTA1004 test = new PTA1004(number);
		while(counter++ < number)
		{
			
			String name = sc.next();
			String ID = sc.next();
			int score = Integer.parseInt(sc.next());
		
			test.getIn(name, ID, score);
		
		}
		test.getMaxMinStudent();
	}
	

}
