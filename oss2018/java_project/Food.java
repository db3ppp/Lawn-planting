public class Food extends GameObject {
   static int count=0;
   static int xx;
   static int yy;
   
   public Food(char symbol) {
      setSymbol(symbol);
   }
   
   public static int getCount() {
	   return count;
   }

   // Add food to random location inside the matrix limits
   public static void addRandomFood(GameScreen screen, Food food) 
   {
      xx = (int)(Math.random()*(screen.getScreenWidth() - 2))+1;
      yy = (int)(Math.random()*(screen.getScreenHeight() - 2))+1;
      
      screen.setObjectOnLocation(food,xx,yy);
   }
   public static void countIs(GameScreen screen, Food food)
   {
      if((Snake.getX()==xx)&&(Snake.getY()==yy))
      {
         count++;
         System.out.println("current score is "+count);
         addRandomFood(screen, food);
      }   
   }
}
