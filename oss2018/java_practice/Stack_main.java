//https://www.acmicpc.net/problem/10828
import java.util.Scanner;
public class Stack_main {
	public static void main(String[]args) {
		int num;
		
		Stack_main main = new Stack_main();
		Stack stack = main.new Stack();
		
		Scanner kb = new Scanner(System.in);
		num = kb.nextInt();
		
		String []input = new String [num+1];
		
		for(int i=0; i<=num ; i++) {
			input[i] = kb.nextLine();
		}
		
		for(int i=0 ; i<=num ; i++) {
			if(input[i].contains("push")) {
				input[i] = input[i].substring(5);
				int n = Integer.parseInt(input[i]);
				stack.push(n);
			}
			else if(input[i].contains("pop"))
				stack.pop();
			else if(input[i].contains("size"))
				stack.size();
			else if(input[i].contains("empty"))
				stack.empty();
			else if(input[i].contains("top"))
				stack.top();
		}
		kb.close();
	}
	
	private class Stack extends Listnode{
		private Listnode top;
		
		public Stack() {top=null;}
		
		public void push(int n) {
			top = new Listnode(n,top);
		}
		
		public void pop() {
			if(top==null) System.out.println(-1);
			else {
				System.out.println(top.data);
				top = top.link;//이거이거 
			}
		}
		
		public void size() {
			int count=0;
			Listnode cur=top;
			
			while(cur!=null) {
				count++;
				cur = cur.link;
			}
			System.out.println(count);
		}
		
		public void empty() {
			if(top==null) System.out.println(1);
			else System.out.println(0);
		}
		
		public void top() {
			System.out.println(top.data);
		}
		
	}
	
	private class Listnode{
		private int data;
		private Listnode link;
		
		public Listnode() {
			data = -1;
			link = null;
		}
		public Listnode(int newdata, Listnode linkvalue) {
			data = newdata;
			link = linkvalue;
		}
	}
	

}

