package qin;

import java.util.Scanner;

/**
 * Question 3、 用for循环循环打印1~100所有能被3整除的数。
 * */
public class DivideByThree {
	private int n;
	
	public DivideByThree() {
	}

	public DivideByThree(int n) {
		this.n = n;
	}

	public int getN() {
		return n;
	}

	public void setN(int n) {
		this.n = n;
	}
	
	public void getDivideByThree(){
		for (int i = 1; i <= n; i++){
			if (0 == i % 3){
				System.out.println(i);
			}
		}
		
	}

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		DivideByThree test = new DivideByThree();
		
		while(in.hasNext()){
			test.setN(in.nextInt());
			test.getDivideByThree();
		}
		in.close();
		
	}

}
