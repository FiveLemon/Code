package qin;
/**
 * Question 10、 定义一个方法，实现，输入一个整数参数n,返回n的阶乘的值。（递归和
 * 循环）
 * */
import java.math.BigDecimal;
import java.util.Scanner;

public class Factorial {
	private int number;
	private BigDecimal result;

	public Factorial() {
		result = new BigDecimal(1);	
	}

	public Factorial(int number, BigDecimal result) {
		super();
		this.number = number;
		this.result = result;
	}

	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.result = new BigDecimal(1);
		this.number = number;
	}

	public BigDecimal getResult() {
		return result;
	}

	public void setResult(BigDecimal result) {
		this.result = result;
	}
	
	public void getFactorialByCircle(){
		if (1 == number || 0 == number){
			return;
		}
		for (int i = 1; i <= number; i++){
			result = result.multiply(new BigDecimal(i));
		}
	}
	public void getFactorialByRecursive(){
		result = FactorialByRecursive(number);
	}
	public BigDecimal FactorialByRecursive(int number)
	{
		BigDecimal temp = new BigDecimal(number);
		if (0 == number || 1 == number){
			return new BigDecimal(1);
		}else{
			temp = temp.multiply(FactorialByRecursive(number - 1));
		}
		return temp;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Factorial test = new Factorial();
		while(in.hasNext()){
			test.setNumber(in.nextInt());
			test.getFactorialByRecursive();
			System.out.println(test.getResult().toString());
		}	
		in.close();
	}
}
