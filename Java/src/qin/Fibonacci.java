package qin;

/**
 * Question 32、求斐波那契额数列第n项的值， 数列规则如下：
 * 1, 1, 2, 3, 5, 8, 13, 21 ……
 * */
public class Fibonacci {
	
	public int getFibonacci(int number){
		if (number < 1){
			System.out.println("Something is wrong");
			return 0;
		}
		if (number < 3){
			return 1;
		}else{
			return getFibonacci(number - 2) + getFibonacci(number - 1);
		}
	}

	public static void main(String[] args) {
		Fibonacci fibonacci = new Fibonacci();
		System.out.println(fibonacci.getFibonacci(4));
	}

}
