package pratice;

public class MyLinkList {
	private Node head;
	
	public MyLinkList() {
	}
	
	public Node getHead() {
		return head;
	}

	public void setHead(Node head) {
		this.head = head;
	}

	public void initialList(int[] a){
		Node current = head;
		for (int i = 0; i < a.length; i++){
			Node temp = new Node();
			temp.setData(a[i]);
			current.setNext(temp);
			current = temp;
		}
	}
	
	public void iterList(){
		Node current = head.getNext();
		while(null != current){
			System.out.println(current.getData());
			current = current.getNext();
		}
	}

	public static void main(String[] args) {
		Node head = new Node();
		MyLinkList list = new MyLinkList();
		list.setHead(head);
		int[] data = new int[]{5,6,7,3,4,1,3};
		list.initialList(data);
		list.iterList();
		
	}

}
class Node{
	private int data;
	private Node next;
	public Node() {
		next = null;
	}
	public int getData() {
		return data;
	}
	public void setData(int data) {
		this.data = data;
	}
	public Node getNext() {
		return next;
	}
	public void setNext(Node next) {
		this.next = next;
	}
	
	
}
