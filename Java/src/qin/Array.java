package qin;

import java.util.Arrays;

/**
 * Question 8、 数组：创建一个整数的数组，长度为6，
 * 要求数组中的每一项是前一项的2倍，第一项值为2.
 * */
public class Array {

	public static void main(String[] args) {
		int[] data = new int[6];
		data[0] = 2;
		for (int i = 1; i < data.length; i++){
			data[i] = 2 * data[i - 1];
		}
		System.out.println(Arrays.toString(data));

	}

}
