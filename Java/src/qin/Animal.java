package qin;

/**
 * Question 33
 * */
public abstract class Animal {
	private int legs;

	protected Animal(int legs) {
		this.legs = legs;
	}
	
	public void walk(){
		System.out.println("The animal is walking");
	}

	public abstract void eat();
}
