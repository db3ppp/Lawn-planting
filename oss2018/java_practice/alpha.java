//baekjoon https://www.acmicpc.net/problem/10809
import java.util.Scanner;
class alpha {
public static void main (String [] args) {
  String input;
  int order;
  int [] alpha = new int[26];

  Scanner w = new Scanner(System.in);
  input = w.next();
char[] str = input.toCharArray();

  for(int i=0;i<26;i++)
  alpha[i]=-1;

  for(int i=0;i<str.length;i++){
    order = input.charAt(i) - 'a';
    if(alpha[order]==-1)
    alpha[order] = i;

  }
  for(int i=0;i<alpha.length;i++){
    System.out.print(alpha[i]+" ");
  }
  w.close();

}
}
