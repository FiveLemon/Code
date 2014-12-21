package test;

public class Father {
	public int a = 9;
	
	{
		
		System.out.println("Father noraml ");
	}
	static{
		System.out.println("Father static");
	}
	public void print(){
		System.out.println("father");
	}

	public Father() {
		// TODO Auto-generated constructor stub
		System.out.println("Father constractor");
	}
	public static void main(String[] args){
		Father fa = new Father();
		Father fa1 = new Father();
	}

}
