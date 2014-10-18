/**
 * Created in 2014年9月15日
 * Created by:qcq
 */
package source.PTA;

import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class PTA1001 {
	private int n;
	public int counter;
	
	
	public PTA1001(int n)
	{
		this.n = n;
		counter = 0;
	}
	
	public int getN() {
		return n;
	}
	
	public void setN(int n) {
		this.n = n;
	}
	
	public int cutNumber()
	{
		
		while( n > 1)
		{
			if (0 == n % 2)
			{
				n/=2;
				counter++;
			}
			else
			{
				n = (3 * n + 1) / 2;
				counter++;
			}
		}
		return counter;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in); 
		int b = sc.nextInt();
		PTA1001 test = new PTA1001(b);
		System.out.println(test.cutNumber());
	}
}
