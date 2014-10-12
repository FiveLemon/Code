package source.PTA;

import java.util.ArrayList;
import java.util.Scanner;



public class PTA1002 {
	private String input;
	private int index;
	private ArrayList<String> list;
	private PTA1002()
	{
		list = new ArrayList<String>();
		list.add("ling");
		list.add("yi");
		list.add("er");
		list.add("san");
		list.add("si");
		list.add("wu");
		list.add("liu");
		list.add("qi");
		list.add("ba");
		list.add("jiu");
		index = 0;
		
	}
	public void setString(String input)
	{
		this.input = input;
	}
	public String out()
	{
		index = 0;
		int sum = 0;
		String str = "";
		StringBuilder temp = new StringBuilder();
		while(index++ < input.length())
		{
			sum += Integer.parseInt(input.substring(index - 1, index));
		}
		str = String.valueOf(sum);
		index = 0;
		while(index++ < str.length())
		{
			temp.append(list.get(Integer.parseInt(str.substring(index - 1, index))));
			temp.append(" ");
		}
		return temp.toString().trim();
	}
	public static void main(String args[])
	{
		
		Scanner sc = new Scanner(System.in);
		PTA1002 test = new PTA1002();
		test.setString(sc.next());
		System.out.println(test.out());
	}
}
