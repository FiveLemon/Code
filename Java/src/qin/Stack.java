package qin;

import java.util.ArrayList;
import java.util.Iterator;

/**
 * Question 20、利用数组实现一个栈，特性 —— 先进后出
 * */
public class Stack<T> implements Iterable<T>{
	private ArrayList<T> array;	

	public Stack(ArrayList<T> array) {
		super();
		this.array = array;
	}

	public ArrayList<T> getArray() {
		return array;
	}

	public void setArray(ArrayList<T> array) {
		this.array = array;
	}
	public Stack() {
		array = new ArrayList<T>();
	}
	
	public T pop(){
		if (array.isEmpty()){
			return null;
		}else{
			return array.remove(array.size() - 1);
		}
		
	}
	public void push(T data){
		array.add(data);
	}
	
	public Iterator<T> iterator() {
		// TODO Auto-generated method stub
		return array.iterator();
	}
	
	public static void main (String[] args){
		Stack<Integer> a = new Stack<Integer>();
		for(int i = 0; i < 10; i++){
			a.push(i);
		}
		for (int i = 0; i < 10; i++){
			System.out.println(a.pop());
		}
		
	}

	

}
