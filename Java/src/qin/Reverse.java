package qin;

import java.util.Scanner;

/**
 * Question 35、String类：从键盘输入字符串，回车后反转打印.如：输入 abcd, 输出dcba
 * */
public class Reverse {
	private String str;
	
	public Reverse(){
		this(null);
	}
	public String getStr() {
		return str;
	}
	public void setStr(String str) {
		this.str = str;
	}
	public Reverse(String str){
		this.str = str;
	}
	public String reverse(){
		StringBuilder string = new StringBuilder(str);
		return string.reverse().toString();
	}
	public String reverseByOwn(){
		char[] a = str.toCharArray();
		char temp;
		int length = a.length;
		for (int i = 0, j = length - 1; i < j; i++, j--){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		return new String(a);
		
	}
	

	public static void main(String[] args) {
		Reverse test = new Reverse();
		Scanner in = new Scanner(System.in);
		while (in.hasNext()){
			test.setStr(in.next());
			System.out.println(test.reverseByOwn());
		}
		in.close();

	}

}
