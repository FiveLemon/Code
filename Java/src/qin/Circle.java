package qin;

/**
 * Question 16、（1）定义一个点的类Point，并建立方法计算两点之间的距离；
 *	public double distance(Point p1, Point p2){}
 *
 *  （2）定义圆的类Circle，并建立方法判断两个圆是否相交。
 *	public boolean intersect(Circle c1, Circle c2){}
 *
 *  （3）创建一个存放点的引用类型的数组Point[]，总长度为5，所有点都在x轴和y轴的平分线上。
 * */
/**
 * Question 34.求图形的面积，
 * */
public class Circle extends Shape{
	private Point center;
	private double radius;

	public Circle() {
	}

	public Circle(Point center, double radius) {
		this.center = center;
		this.radius = radius;
	}

	public Point getCenter() {
		return center;
	}

	public void setCenter(Point center) {
		this.center = center;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public boolean intersect(Circle c1, Circle c2){
		return c1.getCenter().distance(c2.getCenter()) <= c1.getRadius() + c2.getRadius();
	}

	public double calculatePerimerter() {
		return 2 * Math.PI * radius;
	}

}
