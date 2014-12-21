package qin;

/**
 * Question 34.求图形的面积，
 * */
public class Rectangle extends Shape{
	private double width;
	private double length;
	public Rectangle(double wide, double length) {
		this.width = wide;
		this.length = length;
	}
	public Rectangle() {
	}
	public double getWide() {
		return width;
	}
	public void setWide(int wide) {
		this.width = wide;
	}
	public double getLength() {
		return length;
	}
	public void setLength(int length) {
		this.length = length;
	}
	public double areaByWideAndLength(){
		return width * length;
	}
	public double areaByRect(Rectangle rec){
		return rec.getLength()* rec.getWide();
	}
	public static void main(String[] args){
		Rectangle test = new Rectangle();
		Rectangle test1 = new Rectangle(6,7);
		test.setLength(9);
		test.setWide(4);
		System.out.println(test.areaByWideAndLength());
		System.out.println(test.areaByRect(test1));
	}

	public double calculatePerimerter() {
	
		return 2 * (width + length);
	}
	

}
