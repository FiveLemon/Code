package PAT;

import java.util.ArrayList;
import java.util.Scanner;

public class PAT1031 {
	private int[] weight = new int[]{7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	private char[] M = new char[]{'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	
	public boolean verification(String id){
		int sum = 0;
		for (int i =0; i < id.length() - 1; i++){
			if (!Character.isDigit(id.charAt(i))){
				return false;
			} else {
				sum += (weight[i] * Character.digit(id.charAt(i), 10));
			}
		}
		if (M[sum % 11] == id.charAt(id.length() - 1)){
			return true;
		} else {
			return false;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PAT1031 test = new PAT1031();
		int temp = in.nextInt();
		int counter = 0;
		ArrayList<String> data = new ArrayList<String>();
		for (int i = 0; i < temp; i++){
			data.add(in.next());
		}
		for (String a:data){
			if (test.verification(a)){
				counter++;
			} else {
				System.out.println(a);
			}
		}
		
		if (counter == temp){
			System.out.println("All passed");
		}
		in.close();
	}

}
