package qin;

import java.util.Arrays;

/**
 * Question 18、 （1）定义一个方法，传入一个无序数组，对此数组中的元素进行冒泡排序
 *	public void sort(int arr){}
 *
 *    （2）实现有序数组连接，(假设都是从小到大排序的)，返回连接后的有序数组
 *	public int[] connect(int[] arr1, int[] arr2){}
 * */
public class Sort <T extends Number>{
	private T[] data;

	public Sort() {
	}
	
	public T[] getArray(){
		return data;
	}
	public void setArray(T[] data){
		this.data = data;
	}
	public void exchange(int indexOne, int indexTwo){
		T temp = data[indexOne];
		data[indexOne] = data[indexTwo];
		data[indexTwo] = temp;
	}
	public void bubbleSort(){
		int length = data.length;
		boolean flag = false;
		int counter = 0;
		for (int i = 1; i < length && !flag; i++){
			counter = 0;
			for (int j = 0; j < length - i; j++){
				if (data[j].doubleValue() > data[j + 1].doubleValue()){
					exchange(j, j + 1);
					//flag = true;
					counter++;
				}
			}
			if (0 == counter){
				flag = true;
			}
		}
	}
	
	public Object[] arrayContact(T[] dataOne, T[] dataTwo){
		int lengthOne = dataOne.length;
		int lengthTwo = dataTwo.length;
		int length = lengthOne + lengthTwo;
		Object[] data = new Object[length];
		int x = 0;
		int y = 0;
		int i = 0;
		for (; i < length && x < lengthOne && y < lengthTwo; i++){
			if (dataOne[x].doubleValue() < dataTwo[y].doubleValue()){
				data[i] = dataOne[x];
				x++;
			}else{
				data[i] = dataTwo[y];
				y++;
			}
		}
		if (x == lengthOne){
			for (; i < length; y++, i++){
				data[i] = dataTwo[y];
			}
		}else{
			for (; i < length; x++, i++){
				data[i] = dataOne[x];
			}
		}
		
		return data;
	}
	
	public static void main(String[] args){
		Sort<Integer> sort = new Sort<Integer>();
		Integer[] dataOne = new Integer[]{1,3,5,7,56};
		Integer[] dataTwo = new Integer[]{2,4,6,8,57};
//		System.out.println(Arrays.toString(data));
//		sort.setArray(data);
		//sort.bubbleSort();
		System.out.println(Arrays.toString(sort.arrayContact(dataOne, dataTwo)));
//		System.out.println(Arrays.toString(sort.getArray()));
		
	}

}
