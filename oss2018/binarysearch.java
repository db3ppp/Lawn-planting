import java.util.Scanner;
public class BinarySearch {

	public static void main(String[] args) {
		int []data = {5,7,9,13,32,33,42,54,56,88};
		System.out.println("What index of number do you want to know?");
		
		Scanner kb = new Scanner(System.in);
		int num = kb.nextInt();
		
		int index = binarysearch(data, num, 0, data.length-1);
		
		if(index==-1)
			System.out.println("There is no number in data");
		else
		System.out.println("The index of "+num+ " is " +index);
		
		kb.close();
	}
	
	public static int binarysearch(int []data, int key, int left, int right) {
		
		while(left <= right) {
			 int middle = (left+right)/2;
			
			if(data[middle] == key) return middle;
			else if(data[middle] < key)
				left = middle+1;
			else
				right = middle-1;
		}
		return -1;
		
	}
	//recursion ver
	public static int binarysearchrecursion(int []data, int key, int left, int right) {
		if(left <=right) {
			int middle = (left+right)/2;
			
			if(data[middle] == key) return middle;
			else if(data[middle] < key)
				return binarysearchrecursion(data, key, middle+1, right);
			else
				return binarysearchrecursion(data, key, left, middle-1);
		}
		else return -1;
	}

}
