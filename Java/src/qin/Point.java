package qin;

/**
 * Question 14、定义一个点Point的类，它拥有两个属性，x坐标和y坐标，
 * 并对其使用封装。并创建两个对象，然后给坐标赋值
 * 
 * Question 15、定义一个方法，传入4个整数代表的坐标点：int x1,int y1,int x2, int y2.
 * 实现这两个点之间的距离。
 * */
public class Point {
	private double x;
	private double y;

	public double getX() {
		return x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return y;
	}

	public void setY(double y) {
		this.y = y;
	}

	public Point() {
	}

	public Point(double x, double y) {
		super();
		this.x = x;
		this.y = y;
	}
	
	public double distance(int x1, int y1, int x2, int y2){
		return distance(new Point(x1, y1), new Point(x2, y2));
		//		return Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
	}
	public double distance(Point point){
		return Math.sqrt(Math.pow(x - point.getX(), 2) + Math.pow(y - point.getY(), 2));
	}
	
	public double distance(double x, double y){
		return distance(new Point(x, y));
	}
	
	public double distance(Point a, Point b){
		return Math.sqrt(Math.pow(a.getX() - b.getX(), 2) + Math.pow(a.getY() - b.getY(), 2));
	}

	public String toString() {
		return "Point [x=" + x + ", y=" + y + "]";
	}
	
	public static void main(String[] args){
		Point a = new Point(2.6, 6.7);
		Point b = new Point();
		b.setX(2.5);
		b.setY(6.7);
		System.out.println(a.distance(1,2,3,4));
	}

}
