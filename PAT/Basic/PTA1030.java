package source.PTA;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class PTA1030 extends ArrayList<Integer> implements Comparator<Integer>{
	private int N;
	private int p;
	//private  ArrayList<Integer> data;
	public PTA1030(int N, int p)
	{
		this.N = N;
		this.p =  p;
	}
	public void addData(int temp)
	{
		this.add(temp);
		
	}
	public int getData(int index)
	{
		if (index < N)
		{
			return this.get(index);
		}
		return -1;
	}
	
	@Override
	public int compare(Integer o1, Integer o2) {
		// TODO Auto-generated method stub
		return o1 - o2;
	}
	public int result()
	{
		this.sort(this);
		int number = 0;
		for (int i = 0; i < N; i++)
		{
			if (this.get(i) * 1.0 / this.get(0) <= p)
			{
				number++;
			}
		}
		return number;
	}

	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String temp[] = sc.nextLine().trim().split(" ");
		int N = Integer.valueOf(temp[0]);
		int p = Integer.valueOf(temp[1]);
		PTA1030 test = new PTA1030(N, p);
		int i = 0;
		while(i++ < N)
		{
			test.addData(sc.nextInt());
		}
		System.out.println(test.result());
		
		
	}
	
}
