
public class GameObject {
	
	public static int x, y;
	private char symbol;
	
	// Getters
	public static int getX() {
		return x;
	}

	public static int getY() {
		return y;
	}

	public char getSymbol() {
		return symbol;
	}

	// Setters
	public void setX(int newLocation) {
		x = newLocation;
	}
	
	public void setY(int newLocation) {
		y = newLocation;
	}
	
	public void setSymbol(char newSymbol) {
		this.symbol = newSymbol;
	}
}

