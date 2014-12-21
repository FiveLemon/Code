package qin;
import java.util.Scanner;

/**
 * Question 2、 判断成绩等级，给出一个double类型的分数（如：85.7），分别用if语句
 * 和switch语句实现：90~100打印优秀，80~89打印良好，60~79打印及格，60以下不及格。
 * */
public class Grade
{
	private byte score;

	public Grade(byte score){
		this.score = score;
	}
	public Grade(){
	}

	public byte getScore(){
		return score;
	}
	public void setScore(byte score){
		this.score = score;
	}
	public void getResultByIf(){
		if (score < 60){
			System.out.println("failed");
		}	
		else if (score < 70){
			System.out.println("pass");
		}
		else if (score < 90){
			System.out.println("good");
		}
		else{
			System.out.println("best");
		}
	}
	public void getResultBySwitch(){
		
		if (score < 0 || score > 100)
		{
			System.out.println("Wrong");
		}
		else{
			byte temp = (byte)(score / 10);
			switch(temp){
				case 10:
				case 9:
					System.out.println("Best");
					break;
				case 8:
				case 7:
					System.out.println("Good");
					break;
				case 6:
					System.out.println("Pass");
					break;
				default:
						System.out.println("Failed");

			}
		}
	}
	public static void main(String[] args) 
	{
		Grade student = new Grade();
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			student.setScore(in.nextByte());
			student.getResultBySwitch();
		}
		in.close();
	}
}
