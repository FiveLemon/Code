package qin;

import java.util.Scanner;

/**
 * Question 23、int与String之间的转换
 * */
public class ConvertStringInt {

	public ConvertStringInt() {
	}
	
	public String int2String(int data){
		return new Integer(data).toString();
	}
	
	public int string2Int(String str){
		return Integer.valueOf(str);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		ConvertStringInt con = new ConvertStringInt();
		System.out.println(con.int2String(100));
		System.out.println(con.string2Int("1000"));
		in.close();

	}

}
