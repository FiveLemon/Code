package qin;

/**
 * Question 11、（1）定义一个方法，传入一个整数参数，判断奇是否为奇数？
 *		是返回true，不是，返回false。
 *
 * （2）定义一个方法，传入一个整数参数n，
 *      	计算0~n的所有奇数的和。并打印和。
 *
 * （3）定义一个方法，传入一个整数的数组参数，
 *		求数组中最大值和最小值的差，并返回差值。
 * */
import java.util.Scanner;

public class Odd {
	public boolean isOdd(int number){
		if (0 != number % 2){
			return true;
		}else{
			return false;
		}
		
	}
	public int sumOfOdd(int number){
		int sum = 0;
		for (int i = 0; i <= number; i++){
			if (isOdd(i)){
				sum += i;
			}
		}
		return sum;
	}
	public int differenceOfTwoNumber(int[] data){
		int max = data[0];
		int min = data[0];
		for (int i = 1; i < data.length; i++){
			max = Math.max(max, data[i]);
			min = Math.min(min, data[i]);
		}
		return max - min;
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		Odd test = new Odd();
		int temp;
		while (in.hasNext()){
			temp = in.nextInt();
			if (test.isOdd(temp)){
				System.out.println("true");
			}else{
				System.out.println("false");
			}
			System.out.println(test.sumOfOdd(temp));
		}
		int[] data = new int[]{1,2,34,4,5};
		System.out.println(test.differenceOfTwoNumber(data));
		in.close();
	}

}
