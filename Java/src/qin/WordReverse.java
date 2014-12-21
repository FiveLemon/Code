package qin;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * *
 * Question 36、从键盘输入字符串，回车后按单词反转
 *	Where there is a way
 *	Way a is there where 
 *
 */
public class WordReverse {
	private String sentence;

	public WordReverse() {
	}

	public WordReverse(String sentence) {
		this.sentence = sentence;
	}

	public String getSentence() {
		return sentence;
	}

	public void setSentence(String sentence) {
		this.sentence = sentence;
	}
	
	public char[] reverseByOwn(String str){
		char[] a = str.toCharArray();
		reverse(a, 0, a.length);
		return a;
		
	}
	
	public void reverse(char[] a, int front, int end){
		char temp;
		for (int i = front, j = end - 1; i < j; i++, j--){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	public String reverseWord() {
		char[] a = reverseByOwn(sentence);
		int length = a.length;
		int front = 0; 
		for (int i = 0; i < length; i++){
			if (' ' == a[i]){
				reverse(a, front, i);
				front = i + 1;
			}
		}
		reverse(a, front, length);
		return new String(a);
	}

	public static void main(String[] args) {
		WordReverse test = new WordReverse();
		BufferedReader reader = null;
		reader = new BufferedReader(new InputStreamReader(System.in));
		try{
			String str;
			while (null != (str = reader.readLine())){
				//System.out.println(in.next());
				test.setSentence(str);
				//str = reader.readLine();
				System.out.println(test.reverseWord());
			}
		}catch(IOException e){
			e.printStackTrace();
			
		}finally{
			try {
				reader.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
