package pratice;

import java.util.ArrayList;
import java.util.Scanner;

public class Tree {
	private TreeNode root;
	private ArrayList<TreeNode> list;
	
	public Tree(){
		this(null);		
	}
	public Tree(TreeNode root) {
		this.root = root;
		list = new ArrayList<TreeNode>();
	}
	public void initialTree(int[] data){
		//if ()
	}
	public TreeNode getRoot(){
		return root;
	}
	public void createBinaryTree(){
		//TreeNode a = new TreeNode();
		Scanner in = new Scanner(System.in);
		root = createTree(in, root);
		in.close();
		//return a;
		
	}
	
	private TreeNode createTree(Scanner in, TreeNode root){
		if (in.hasNext()){
			String a = in.next();
			//System.out.println(a);
			if (a.equals("#")){
				root = null;
				//System.out.println(a);
			}else{
				root = new TreeNode(Integer.valueOf(a));
				//list.add(root);
				if (null != root){
					root.setLeft(createTree(in, root.getLeft()));
					root.setRight(createTree(in, root.getRight()));
				}
			}
		}
		return root;
	}
	
	public void preOrder(TreeNode root){
		if (null == root){
			return;
		}
		System.out.print(root.getData() + " ");
		preOrder(root.getLeft());
		//System.out.println(root.getData());
		preOrder(root.getRight());
		//System.out.println(root.getData());
	}
	public void inOrder(TreeNode root){
		if (null == root){
			return;
		}
		//System.out.println(root.getData());
		inOrder(root.getLeft());
		System.out.print(root.getData()+ " ");
		inOrder(root.getRight());
		//System.out.println(root.getData());
	}
	public void postOrder(TreeNode root){
		if (null == root){
			return;
		}
		//System.out.println(root.getData());
		postOrder(root.getLeft());
		//System.out.println(root.getData());
		postOrder(root.getRight());
		System.out.print(root.getData()+ " ");
	}
	
	
	
	public static void main(String[] args) {
		
		TreeNode[]  node = new TreeNode[16]; 
		for (int i = 1; i < 16; i++){
			node[i] = new TreeNode(i);
		}
		
		Tree tree = new Tree(node[1]);
		node[1].setLeft(node[2]);
		node[1].setRight(node[3]);
		node[2].setLeft(node[4]);
		node[2].setRight(node[5]);
		node[3].setLeft(node[6]);
		node[3].setRight(node[7]);
		node[4].setLeft(node[8]);
		node[4].setRight(node[9]);
		node[5].setLeft(node[10]);
		node[5].setRight(node[11]);
		node[6].setLeft(node[12]);
		node[6].setRight(node[13]);
		node[7].setLeft(node[14]);
		node[7].setRight(node[15]);
		tree.preOrder(node[1]);
		tree.inOrder(node[1]);
		tree.postOrder(node[1]);
		Tree another = new Tree();
		another.createBinaryTree();
		//System.out.println(another.getRoot());
		another.preOrder(another.getRoot());
		//another.inOrder(another.getRoot());
		
		
	}
	

}
class TreeNode{
	private int data;
	private TreeNode left;
	private TreeNode right;
	public TreeNode() {
		left = null;
		right = null;
	}
	public TreeNode(int data) {
		this.data = data;
	}
	public int getData() {
		return data;
	}
	public void setData(int data) {
		this.data = data;
	}
	public TreeNode getLeft() {
		return left;
	}
	public void setLeft(TreeNode left) {
		this.left = left;
	}
	public TreeNode getRight() {
		return right;
	}
	public void setRight(TreeNode right) {
		this.right = right;
	}
	
	public String toString(){
		return data + "";
	}
	
	
}
