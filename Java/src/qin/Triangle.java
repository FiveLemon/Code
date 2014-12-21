package qin;

/**
 * Question 5、 在控制台打印如下图形
 * */
import java.util.Scanner;

public class Triangle {
	private String shape;
	private int line;
	
	public Triangle() {
	}
	public Triangle(String shape, int line) {
		this.shape = shape;
		this.line = line;
	}
	public String getShape() {
		return shape;
	}
	public void setShape(String shape) {
		this.shape = shape;
	}
	public int getLine() {
		return line;
	}
	public void setLine(int line) {
		this.line = line;
	}
	public void printShape(){
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < (line - i - 1); j++){
				System.out.print(" ");
			}
			for (int j = 0; j < 2 * i + 1; j++){
				System.out.print(shape);
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		Triangle test = new Triangle();
		test.setShape(in.next());
		test.setLine(in.nextInt());
		test.printShape();
		in.close();
	}

}
