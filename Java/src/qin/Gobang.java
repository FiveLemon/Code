package qin;

import java.util.Scanner;

/**
 * Question 19、利用二维数组实现五子棋下棋功能
 * */
public class Gobang {
	private Color[][] data;
	private int row = 10;
	private int column = 10;

	public Gobang() {
		/*
		 * The default checkerboard is 10 * 10 boxes;
		 * */
		this(10, 10);
		initial();
	}
	/*
	 * Initial the Game
	 * */
	public void initial(){
		for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				data[i][j] = Color.NULL;
			}
		}
	}
	
	/*
	 * The piece move
	 * */
	public void setChess(int row, int column,Color color){
		data[row][column] = color;
	}
	
	public Gobang(int row, int column){
		/*
		 * set the Chess squre to row * line
		 * */
		this.row = row;
		this.column = column;
		data = new Color[row][];
		for (int i = 0; i < row; i++){
			data[i] = new Color[column];
		}
		initial();
	}
	/*
	 * print out the current checkerboard
	 * */
	public void printCheckerBoard(){
		/*
		 * print out the chessboard layout
		 * */
		for (Color[] i: data){
			for (Color j : i){
				System.out.print(j.toString() + " ");
			}
			System.out.println();	
		}
	}
	/*
	 * verify the input data to insure the piece is in the range
	 * and not put this piece in the history place
	 * 验证棋子在合适的位置上
	 * */
	public boolean check(int x, int y){
		if (x < 0 || x >= row || y < 0 || y >= column){
			System.out.println("The input is error");
			System.out.println("The input should from(0, 0) to (" + (x - 1) + "," + (y - 1) + ")");
			return false;
		}
		if (Color.NULL != data[x][y]){
			System.out.println("This place already has one piece!");
			return false;
		}
		return true;
	}
	
	/*
	 * judge if successed, The parameter x and y
	 * is the range which need to be scanning.
	 * The Scanning range can zoom in a range which is a circle(a square)
	 * center in current move, radius is 5.
	 * 扫描棋盘看是不是有棋子获胜，可以优化扫描方案，将扫描的范围局限于一个以落子处为中心
	 * 5为半径的棋盘。
	 */
	public boolean isSuccess(Point x, Point y, Color color){
		boolean flag = false;
		int counter = 0;
		label:
		for (int i = (int) x.getX(); i <= (int)y.getX(); i++){
			for (int j = (int)x.getY(); j <= (int)y.getY(); j++){
				/*
				 * scanning the [x,y] range in 4 directions.
				 * */
				
				// check the line
				counter = 0;
				if (j + 4 <= (int)y.getY()){
					for (int index = j; index <= j + 4; index++){
						if (color == data[i][index]){
							counter++;
						}
					}
				}
				if (5 == counter){
					flag = true;
					break label;
				}
				// check the column
				counter = 0;
				if (i + 4 <= (int)y.getX()){
					for (int index = i; index <= i + 4; index++){
						if (color == data[index][j]){
							counter++;
						}
					}
				}
				if (5 == counter){
					flag = true;
					break label;
				
				}
				//check the dig line
				counter = 0;
				if ((i + 4 <= (int)y.getX()) && (j + 4 <= (int)y.getY())){
					for (int indexX = i, indexY = j; indexX <= i + 4 ;indexX++, indexY++){
						if (color == data[indexX][indexY]){
							counter++;
						}
					}
				}
				if (5 == counter){
					flag = true;
					break label;
				}
				//check the reverse dig line
				counter = 0;
				if ((i + 4 <= (int)y.getX()) && (j - 4 >= (int)x.getY())){
					for (int indexX = i, indexY = j; indexX <= i + 4;indexX++, indexY--){
						if (color == data[indexX][indexY]){
							counter++;
						}
					}
				}
				if (5 == counter){
					flag = true;
					break label;
				}
			}
		}
		
		return flag;
		 
	}
	
	/*
	 * The actual game start here, where black first, white second,
	 * we can optimize the game which  do not call
	 * the method isSuccess in the first segment. such as 8 moves.
	 * and we can narrow the scanning the range to a square just talk above.
	 * */
	public void playChess(){
		Scanner in = new Scanner(System.in);
		Point x = new Point(0, 0);
		Point y = new Point(row - 1, column - 1);
		label:
		while (true){
			//The input should like 1,2
			while (in.hasNext()){
				
				String[] str = in.next().split(",");
				int indexX = Integer.valueOf(str[0]);
				int indexY = Integer.valueOf(str[1]);
				if (!check(indexX, indexY)){
					System.out.println("please input again");
					continue;
				}else{
					setChess(indexX, indexY, Color.BLACK);
					printCheckerBoard();
					if (isSuccess(x, y, Color.BLACK)){
						System.out.println("The Black is win");
						break label;
					}
					break;
				}
			}
			while (in.hasNext()){
				String[] str = in.next().split(",");
				int indexX = Integer.valueOf(str[0]);
				int indexY = Integer.valueOf(str[1]);
				if (!check(indexX, indexY)){
					System.out.println("please input again");
					continue;
				}else{
					setChess(indexX, indexY, Color.WHITE);
					printCheckerBoard();
					if (isSuccess(x, y, Color.WHITE)){
						System.out.println("The White is win");
						
						break label;
					}
					break;
				}
			}	
		}
		in.close();
	}

	public static void main(String[] args) {
		Gobang chess = new Gobang();
		chess.playChess();
	}

}
