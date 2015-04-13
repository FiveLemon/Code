package homework;

/**
 * Question 44: This  is just for demo
 * */
public class Client {
    private static Word word = null;
    private static Excel excel = null;
	public static Office creatOffice(int productType){
		if (1 == productType){
            if (null == word){
                word = new Word();
            }
            return word;
        }else if (2 == productType){
            if (null == excel){
                excel = new Excel();
            }
            return excel;
        }else{
            System.out.println("The input is error, please check it!");
            return null;
        }
	}
	public static void main(String[] args){
		Office o1 = Client.creatOffice(Office.WORD);
		Office o2 = Client.creatOffice(Office.EXCEL);
		o1.start();
		o2.start();
		
	}
}
