package qin;

/**
 * Question 13、 定义一个方法，传入一个整数n，求0~n的所有素数（质数：只能被1和它
 * 本身整除的数）和.备注：求4的开平方  Math.sqrt(4)
 * */
import java.util.Scanner;

public class Prime {
	private int number;

	public Prime() {
	}
	
	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.number = number;
	}

	public Prime(int number) {
		super();
		this.number = number;
	}
	
	public void getOutThePrime(){
		for (int i = 0; i <= number; i++){
			if (isPrime(i)){
				System.out.println(i);
			}
		}
		
	}
	
	public boolean isPrime(int num){
		if (num < 2){
			return false;
		}
		boolean flag = true;
		int data = (int) Math.sqrt(num);
		for (int i = 2; i <= data; i++){
			if (0 == num % i){
				flag = false;
				break;
			}
		}
		return flag;
		
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Prime test = new Prime();
		while (in.hasNext()){
			test.setNumber(in.nextInt());
			test.getOutThePrime();
		}
		in.close();

	}

	
}
