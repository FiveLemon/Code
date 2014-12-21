package test;

public class Child extends Father{
	public int a = 8;
	{	
		System.out.println("child normal");
	}
	
	static{
		System.out.println("child static");
	}
	
	public Child() {
		System.out.println("child consttract");
		// TODO Auto-generated constructor stub
	}
	
	public void print(){
		System.out.println("child");
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Child c = new Child();
		//Child c1 = new Child();
		System.out.println(c.a);

	}

}
