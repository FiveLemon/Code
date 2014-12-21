package qin;

/**
 * Question 4、 用循环打印99乘法口诀表
 * */
public class MultiplyTable {
	public static void main(String[] args){
		for(int i = 1; i <= 9; i++){
			for(int j = 1; j <= i; j++){
				System.out.format("%d * %d = %-3d", j, i, i * j);		
			}
			System.out.println();
		}
	}

}
