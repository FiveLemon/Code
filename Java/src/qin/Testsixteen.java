package qin;

import java.util.Arrays;

/**
 * Question 16、（1）定义一个点的类Point，并建立方法计算两点之间的距离；
 *	public double distance(Point p1, Point p2){}
 *
 *  （2）定义圆的类Circle，并建立方法判断两个圆是否相交。
 *	public boolean intersect(Circle c1, Circle c2){}
 *
 *  （3）创建一个存放点的引用类型的数组Point[]，总长度为5，所有点都在x轴和y轴的平分线上。
 *
 *  （4）定义一个方法，传入一个点的数组Point[],实现交换数组中任意两个不同点的坐标，并打印交换之后的数组元素的坐标值。
 *   可以使用随机数。（Math.random()/Random.nextInt()）
 * */
public class Testsixteen {

	public Testsixteen() {
	}
	
	public void changePoint(Point[] a, int indexOne, int indexTwo){
		double temp = a[indexOne].getX();
		a[indexOne].setX(a[indexTwo].getX());
		a[indexTwo].setX(temp);
		temp = a[indexOne].getY();
		a[indexOne].setY(a[indexTwo].getY());
		a[indexTwo].setY(temp);
		
		
		
	}
	
	
	
	public static void main(String[] args){
		Point[] point = new Point[5];
		for (int i = 0; i < 5; i++){
			point[i] = new Point((i + 1) * 1.0, (i + 1) * 1.0);
		}
		System.out.println(Arrays.toString(point));
		
	}

}
