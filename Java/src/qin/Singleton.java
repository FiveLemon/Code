package qin;
/**
 * 25、单子模式Singleton
 * */
public class Singleton {
	private static Singleton single;
	private Singleton(){
	}
	public static Singleton getInstance(){
		if (null == single){
			single = new Singleton();
		}
		return single;
	}
	public void print(){
		System.out.println("you get it");
	}
	public static void main(String[] args) {
		Singleton single = Singleton.getInstance();
		single.print();
	}

}
