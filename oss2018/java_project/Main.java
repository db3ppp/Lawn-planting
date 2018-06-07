import java.util.Scanner;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		
		//initialize screen size (to be changed)
		int height = 18;
		int width = 14;
		
		// getting the screen size from the file
		try {
			FileInputStream fstream = new FileInputStream("data.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			java.util.ArrayList<String> list = new java.util.ArrayList<String>();

			while ((strLine = br.readLine()) != null) {
				list.add(strLine);
			}

			width = Integer.parseInt(list.get(0));
			height =  Integer.parseInt(list.get(1));

			in.close();
		}
		catch(Exception e) {      
			System.err.println("Error: " + e.getMessage());
		}

		// initialize screen
		GameScreen screen = new GameScreen(width, height);
				screen.InitScreen();

		 // initialize snake's random position
		int snakeX = (int) (Math.random() * (screen.getScreenWidth() - 1));
		int snakeY = (int) (Math.random() * (screen.getScreenHeight() - 1));
				  
		// initialize walls
		Wall wall = new Wall('#');
		wall.addWallsRow(screen, wall, 0); // First row
		wall.addWallsRow(screen, wall, screen.getScreenHeight() - 1); // Last row
		wall.addWallsColumn(screen, wall, 0); // First column
		wall.addWallsColumn(screen, wall, screen.getScreenWidth() - 1); // Last column

		// initialize snake
		Snake snake = new Snake('@', snakeX, snakeY);
		screen.setObjectOnLocation(snake, Snake.getX(), Snake.getY());

		// initilize food
		Food food = new Food('*');
		food.addRandomFood(screen, food);
		
		// Input from player
		Scanner scanner = new Scanner(System.in);
		char input;

		// play the game
		boolean isRunning = true;

		while (isRunning) {
			screen.PrintScreen();
			switch (input = scanner.nextLine().charAt(0)) {
			case 'a':
				snake.moveLeft(screen, snake);
				break;
			case 'd':
				snake.moveRight(screen, snake);
				break;
			case 'w':
				snake.moveUp(screen, snake);
				break;
			case 's':
				snake.moveDown(screen, snake);
				break;
			default: // in case of wrong input, nothing happens
				break;
			}
			Food.countIs(screen, food);
		}
	}

}
