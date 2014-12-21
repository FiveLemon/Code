package qin;

/**
 * Question 34.求图形的面积，
 * */
public class TestShape {

	public static void main(String[] args) {
		Circle circle = new Circle(new Point(0.0, 0.0), 2.5);
		Rectangle rec = new Rectangle(2.5, 4.5);
		System.out.println(circle.calculatePerimerter());
		System.out.println(rec.calculatePerimerter());

	}

}
