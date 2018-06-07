import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;
import java.io.*;

public class GameScreen {
   private int width, height;
   private char[][] screenMatrix;

   public GameScreen(int width, int height) {
      this.width = width;
      this.height = height;
      this.screenMatrix = new char[this.height][this.width];
      
      
   }

   // Fill array with dots
   public void InitScreen() {
      for (int i = 0; i < this.height; i++) {
         for (int j = 0; j < this.width; j++) {
            this.screenMatrix[i][j] = '.';
         }
      }
      
      //Choose level
      System.out.println("Choose the level.");
      System.out.println("1.Easy");
      System.out.println("2.Nomal");
      System.out.println("3.Hard");
      Scanner kb = new Scanner(System.in);
      
      int level=kb.nextInt();
      
      myTimer(level);
   }

   // Print the screen to console
   public void PrintScreen() {
      for (int i = 0; i < this.height; i++) {
         for (int j = 0; j < this.width; j++) {
            System.out.print(this.screenMatrix[i][j]);
         }
         System.out.println();
      }
   }

   // Screen clear location
   public void ClearScreenLocation(int x, int y) {
      this.screenMatrix[y][x] = '.';
   }

   // Getters
   public int getScreenWidth() {
      return this.width;
   }

   public int getScreenHeight() {
      return this.height;
   }

   public char getObjectOnLocation(int x, int y) {
      return this.screenMatrix[y][x];
   }

   // Setters
   public void setObjectOnLocation(GameObject object, int x, int y) {
      this.screenMatrix[y][x] = object.getSymbol();
   }
   
   private void scoreOut() {
      // print result to console
       System.out.println("Game over!");
       System.out.println("Your score is " + Food.getCount());
       
       // print result to file
       String fileName = "result.txt";

       try {
           FileWriter fw =
               new FileWriter(fileName);

           BufferedWriter bw =
               new BufferedWriter(fw);

           // Note that write() does not automatically
           // append a newline character.
           bw.write("Game over!");
           bw.newLine();
           bw.write("Your score is ");
           bw.write(Integer.toString(Food.getCount()));

           // Always close files.
           bw.close();
       }
       catch(IOException ex) {
           System.out.println(
               "Error writing to file '"
               + fileName + "'");
       }
   }

   // Timer
   public void myTimer(int level) {
      Timer m_timer = new Timer();
      TimerTask m_task = new TimerTask() {
         public void run() {
           scoreOut();
            System.exit(0);
         }
      };
      
      if (level == 1) {
         m_timer.schedule(m_task, 90000);
      } else if (level == 2) {
         m_timer.schedule(m_task, 60000);
      } else {
         m_timer.schedule(m_task, 30000);
      }
      
   }

}
