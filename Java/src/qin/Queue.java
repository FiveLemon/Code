package qin;

import java.util.ArrayList;

/**
 * Question 21、利用数组实现一个队列，特性 —— 先进先出
 * */
public class Queue <T>{
	private ArrayList<T> array;

	public Queue(ArrayList<T> array) {
		this.array = array;
	}

	public Queue() {
		array = new ArrayList<T>();
	}
	
	public void put(T data){
		array.add(data);
	}
	
	public T get(){
		if (array.isEmpty()){
			return null;
		}
		return array.remove(0);
	}
	

	public static void main(String[] args) {
		Queue<Integer> queue = new Queue<Integer>();
		for (int i = 0; i < 10; i++){
			queue.put(i + 1);
		}
		for (int i = 0; i < 10; i++){
			System.out.println(queue.get());
		}
	}

}
