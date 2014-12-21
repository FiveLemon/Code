package qin;

/**
 * Question 6、 信息的封装：职工。
 * */
public class Employer{
	private String name;
	private int age;
	private float salary;
	public Employer(){

	}

	public Employer(String name, int age, float salary){
		this.name = name;
		this.age = age;
		this.salary = salary;
	}

	public String getName(){
		return name;
	}

	public int getAge(){
		return age;
	}

	public float getSalary(){
		return salary;
	}

	public void setName(String name){
		this.name = name;
	}

	public String toString(){
		return "name:" + name +"\n" + "age:" + age + "\n" + "salary:" + salary;
	}

	public static void main(String[] args){
		Employer employerA = new Employer("A", 30, 8000f);
		Employer employerB = new Employer("B", 35, 9000f); 
		System.out.println(employerA + "\n" + employerB);
	}

}