//숫자파일에서 중복된 숫자 갯수 세기
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
public class Q2_CountRepetition_main {
	public static void main(String[]args) {
		String fileName = "Q2_numbers.txt";
		Q2_CountRepetition cr = new Q2_CountRepetition(fileName);
		cr.Print();
	} 

}
// 1) using HashMap
public class Q2_CountRepetitionn {
	HashMap<Integer,Integer> map;

	public Q2_CountRepetitionn(String filename) {
		map = new HashMap<Integer,Integer>();
		readdata(filename);
	}
	
	public void readdata(String fileName) {
		Scanner inputStream = null;
		try {
			inputStream = new Scanner(new File(fileName));
		}
		catch(FileNotFoundException e) {
			System.out.println("Error opening the file "+fileName);
			System.exit(0);
		}
		
		while(inputStream.hasNextInt()){
			String line = inputStream.nextLine();
			int key = Integer.parseInt(line);
			int count = 0;
			if(map.containsKey(key)==true) {
				count = map.get(key);
				count++;
			}
			map.put(key, count);
		}
		
		inputStream.close();
	}
	
	public void printMap() {
		System.out.println("Map contains: ");
		for(Integer key : map.keySet())
			System.out.println(key+ " : " +map.get(key));
	}
	
	public void Print() {
		printMap();
		
		int count = 0;
		for(Integer key : map.keySet())
			count += map.get(key);
		
		System.out.println("Num of Repetitions: " +count);
	}
	
}

//2) using ArrayList & HashSet
public class Q2_CountRepetition {
		ArrayList<Integer> array = new ArrayList<Integer>();

	public Q2_CountRepetition(String fileName) {
		readdata(fileName);
	}
	
	public void Print()
	{
		int arraySize = array.size();
		int result = arraySize - getNumIntegers();
		System.out.println("Num of Repetitions: "+result);
	}
	
	
	public void readdata(String fileName) {
		Scanner inputStream = null;
		try {
			inputStream = new Scanner(new File(fileName));
		}
		catch(FileNotFoundException e) {
			System.out.println("Error opening the file "+fileName);
			System.exit(0);
		}
		
		while(inputStream.hasNextInt()){
			int num = inputStream.nextInt();
			array.add(num); //array에 숫자들 담기 
		}
		
		inputStream.close();
	}
	
		public int getNumIntegers() {
			HashSet<Integer> intset = new HashSet<Integer>(array);
			
			return intset.size();
		}
		
}

