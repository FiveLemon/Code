package qin;

import java.util.Arrays;

/**
 * Question 12、 定义一个方法，传入两个数组，实现两个数组的连接，返回新的数组
 * */
public class ContactArray {
	public int[] contact(int[] dataA, int[] dataB){
		int length = dataA.length + dataB.length;
		int[] data = new int[length];
		for (int i = 0; i < dataA.length; i++){
			data[i] = dataA[i];
		}
		int index = 0;
		for (int i = dataA.length; i < length; i++){
			data[i] = dataB[index++];
		}
		return data;
	}
	public static void main(String[] args){
		ContactArray test = new ContactArray();
		int[] dataA = new int[]{3,4,2,3};
		int[] dataB = new int[]{23,42,32,33};
		System.out.println(Arrays.toString(test.contact(dataA, dataB)));
		
	}

}
