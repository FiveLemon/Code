package test;

public class Test {
	private Father father;
	
	

	public static void deal(Father a){
		
		a = new Father();
	}
	public static void main(String[] args){
		Father a = new Father();
		System.out.println(a);
		deal(a);
		System.out.println(a);
		
	}

}
