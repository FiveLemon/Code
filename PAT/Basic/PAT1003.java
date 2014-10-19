import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
public class PAT1003 {
	public static void main(String[] args) {
		int flagSum = 0;
		ArrayList<String> stringList=new ArrayList<String>();
			Scanner sc = new Scanner(System.in);
			flagSum = Integer.parseInt(sc.nextLine());
			for(int i = 0;i<flagSum;++i){
				stringList.add(sc.nextLine());
			}
		String pattern = "A*PA+TA*";
		String pattern1 = "PA+T";
		for(String x:stringList){
			if(x.matches(pattern)){
				if(x.matches(pattern1)){
					System.out.println("YES");
				}else{
					String temp[] = x.split("P|T");
					int aLength = temp[0].length();
					int bLength = temp[1].length();
					int cLength = temp[2].length();
					if((cLength-aLength)/aLength==(bLength-1)){
						System.out.println("YES");
					}else{
						System.out.println("NO");
					}
				}
			}else{
				System.out.println("NO");
			}
		}
	}
}
