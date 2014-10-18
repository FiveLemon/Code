package source.PTA;

import java.util.Scanner;

public class PTA1006 {
	private int data;
	private String bit[] = {"","S","B","Q","W","A","V","Z","Y"};
	private boolean flag;
	private StringBuilder temp;
	private int index;
	
	public PTA1006(int data)
	{
		this.data = data;
		this.flag = true;
		index = 0;
		
	}
	public void getOutput(int data)
	{
		int a = data % 10;
		if (0 == data)
		{
			return;
		}
		data /= 10;
		if(flag)
		{
			flag = false;
			index++;
			temp = new StringBuilder() ;
			for(int i = a; i > 0; i--)
			{
				temp.append(i);
			}
			getOutput(data);
			
		}
		else
		{
			for(int i = 0; i < a; i++)
			{
				temp.append(bit[index]);
			}
			index++;
			getOutput(data);
			}
			
	}
	public String getString()
	{
		return temp.reverse().toString();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int data = sc.nextInt();
		PTA1006 test = new PTA1006(data);
		test.getOutput(data);
		System.out.println(test.getString());
	}

}
