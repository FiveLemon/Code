package qin;

/**
 * Question 7、 学生类的定义
 * 属性：学号，年级，姓名，性别
 * 方法：显示学号，显示姓名，修改年级。
 * 创建2个学生的对象，并赋值和方法调用。
 * */
public class Student {
	private String number;
	private String grade;
	private String name;
	private String sex;
	public Student(String number, String grade, String name, String sex) {
		super();
		this.number = number;
		this.grade = grade;
		this.name = name;
		this.sex = sex;
	}
	public Student() {
	}
	public String getNumber() {
		return number;
	}
	public void setNumber(String number) {
		this.number = number;
	}
	public String getGrade() {
		return grade;
	}
	public void setGrade(String grade) {
		this.grade = grade;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getSex() {
		return sex;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	@Override
	public String toString() {
		return "Stuent [number=" + number + ", grade=" + grade + ", name="
				+ name + ", sex=" + sex + "]";
	}
	
	public static void main(String[] args){
		Student one = new Student("1", "first class", "zhangbeijin", "male");
		Student two = new Student("2", "second class", "fengjie", "female");
		System.out.println(one);
		System.out.println(two);
	}
	

}
