import java.util.Scanner;
import java.lang.*;
public class repet {
	public static void main(String[] args) {
		int num;
		Scanner kb = new Scanner(System.in);
		num = kb.nextInt();
		
		String []str = new String[num];
		int [] repet = new int [num];
		
		for(int i=0;i<num;i++) {
			repet[i] = kb.nextInt();
			str[i] = kb.next();
			}
		
		for(int i=0;i<num;i++) {//str 어레이 바꿔주기 위한 반복문 
			int len = str[i].length();
			
			for(int k=0; k<len;k++) {//str의 길이만큼 반복해서 출력 
			for(int j=0;j<repet[i];j++)//R번씩 반복해서 출력 
				System.out.print(str[i].charAt(k));
			}
			
			System.out.println();
		}
		kb.close();
	}
}

