package qin;

public class CircleQueue{

    private int front;
    private int rear;
    private int size;
    private Integer[] data;

    public CircleQueue(){
        this(10);
    }

    public CircleQueue(int size){
        front = 0;
        rear = 0;
        this.size = size;
        data = new Integer[this.size];
    }

    public boolean isEmpty(){
        return front == rear;
    }

    public boolean isFull(){
        return front == (rear + 1) % size;
    }

    public boolean push(Integer da){
        if (isFull()){
            System.out.println("The Queue is Full!!!");
            return false;
        }
        rear++;
        if (rear == size){
            rear = rear % size;
        }
        data[rear] = da;
        return true;
    }

    public Integer pop(){
        if (isEmpty()){
            System.out.println("The Queue is Empty!!");
            return null;
        }
        front++;
        if (front == size){
            front = front % size;
        }
        return data[front];
    }

    public String toString(){
        return "front:" + front + "rear:" + rear + "size:" + size;
    }

    public static void main(String[] args){
        CircleQueue queue = new CircleQueue();
        for (int i = 0; i < 9; i++){
            queue.push(i + 1);
            
        }
        for (int i = 0; i < 3; i++){
            System.out.println(queue.pop());
          
        }
        System.out.println(queue); 
        for (int i = 0; i < 3; i++){
            queue.push(i + 1);
            
        }
        System.out.println(queue); 
        for (int i = 0; i < 9; i++){
            System.out.println(queue.pop());
            
        }
        
    }
}
