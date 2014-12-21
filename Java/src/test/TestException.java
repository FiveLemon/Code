package test;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.io.FileWriter;


public class TestException{

    public void readFile(String filename){
        FileReader file = null;
        try{
            file = new FileReader(filename);
            int data;
            while ((data = file.read()) != -1){
                System.out.print((char)(data));
            }
        }catch(FileNotFoundException e){
            System.out.println("The file not found");
            e.printStackTrace();
        }catch(IOException e){
            e.printStackTrace();
        }finally{
            if (null != file){
                try{
                    file.close();
                }catch(IOException e){
                    e.printStackTrace();
                }
            }
        }
    }

    public void writeFile(String filename, String content){
        FileWriter writer = null;
        try{
            writer = new FileWriter(filename);
            writer.write(content);
            System.out.println(content);
        }catch(IOException e){
            e.printStackTrace();
        }finally{
            if (null != writer){
                try{
                    writer.close();
                }catch(IOException e){
                    e.printStackTrace();
                }
            }
        }
    }

    public void getCurrentTime(){
        String day = "2014-12-24";
        SimpleDateFormat formatOld = new SimpleDateFormat("yyyy-MM-dd");
        Date date = null;
		try {
			date = formatOld.parse(day);
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        System.out.println(date);
        formatOld.applyPattern("yyyyƒÍMM‘¬dd»’");
        System.out.println(formatOld.format(date));
        
        /*
        Date date = new Date(Integer.valueOf(day.substring(0,4)) - 1900, Integer.valueOf(day.substring(5,7)) - 1, Integer.valueOf(day.substring(8,10)));//DateFormat.parse(day);
        System.out.println(date.toString());
        SimpleDateFormat formatNew = new SimpleDateFormat("yyyy'year'MM'month'dd'day'");
        System.out.println(formatNew.format(date));
        */

        /*
        Date date= new Date();
        System.out.println(date.toString());
        GregorianCalendar calendar = new GregorianCalendar();
        DateFormat format = new SimpleDateFormat("yyyy.MM.dd G 'at' HH:mm:ss z");
        format.setCalendar(calendar);
        System.out.println(format.format(date));
        */
    }
    
	public static void main(String[] args){
	    String filename = "./src/test/Child.java";
	    String file_out = "Child.txt";
	    System.out.println();
	    TestException test = new TestException();
	    test.readFile(filename);
	    test.writeFile(file_out, "I am Chinese, I Love My Coumtry");
	    System.out.println();
	    test.getCurrentTime();
		
	}
}
