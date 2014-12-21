package qin;

/**
 * Question 33
 * */
public class Fish extends Animal implements Pet{
	private String name;
	public Fish() {
		super(0);
	}


	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
		
	}
	
	public void walk(){
		System.out.println("The fish is swimming");
	}

	public void play() {
		System.out.println("The fish is playing");
	}

	public void eat() {
		System.out.println("The fish is eating");
	}

}
