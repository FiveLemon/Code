package qin;

/**
 * Question 22、定义一个类，重写Object中的toString（）和 equals（）这两个方法.
 * */
public class OverrideToString {
	private String name;

	public OverrideToString() {
	}
	
	public OverrideToString(String name){
		this.name = name;
	}
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String toString(){
		return "This method is overrided " + name;
	}
	
	public boolean equals(Object obj){
		return this.name == ((OverrideToString)obj).getName();
	}
	
	public static void main(String[] args) {
		OverrideToString one = new OverrideToString("qin");
		OverrideToString two = new OverrideToString();
		two.setName("ruan");
		if (one.equals(two)){
			System.out.println("true");
			
		}else{
			System.out.println("false");
		}
		System.out.println(one);
		System.out.println(two);
	}
	

}
