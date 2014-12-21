package qin;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Question 9、 定义一个方法，找出数组中的最大值,并打印
 * */
public class Maxium {
	private ArrayList<Integer> array;
	private int maxelement;

	public int getMaxelement() {
		return maxelement;
	}

	public void setMaxelement(int maxelement) {
		this.maxelement = maxelement;
	}

	public Maxium() {
	}

	public Maxium(ArrayList<Integer> array) {
		super();
		this.array = array;
	}
	
	public ArrayList<Integer> getArray() {
		return array;
	}

	public void setArray(ArrayList<Integer> array) {
		this.array = array;
	}
	public void max(){
		maxelement = array.get(0);
		for (int i = 1; i < array.size(); i++){
			maxelement = maxelement > array.get(i)? maxelement:array.get(i);
		}
		System.out.println(maxelement);
	}

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		Maxium test = new Maxium();
		ArrayList<Integer> array = new ArrayList<Integer>();
		while (in.hasNext()){
			array.add(new Integer(in.nextInt()));
		}
		test.setArray(array);
		test.max();
		in.close();
		
	}

}
