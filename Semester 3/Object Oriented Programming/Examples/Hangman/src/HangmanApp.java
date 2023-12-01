import java.util.InputMismatchException;
import java.util.Scanner;

public class HangmanApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int gameMode;

        System.out.println("Select Game Mode:");
        System.out.println("1. SinglePlayer");
        System.out.println("2. MultiPlayer");

        while (true) {
            try {
                gameMode = scanner.nextInt();
                if (gameMode == 1 || gameMode == 2) {
                    break;
                } else {
                    System.out.println("Invalid input. Please enter 1 or 2.");
                }
            } catch (InputMismatchException e) {
                scanner.nextLine(); // Consume the invalid input
                System.out.println("Invalid input. Please enter a valid integer.");
            }
        }

        HangmanGame hangmanGame;
        if (gameMode == 1) {
            hangmanGame = new HangmanGame();
            hangmanGame.playGame();
        } else {
            System.out.println("Enter the mysterious word:");
            String hiddenWord = scanner.nextLine();
            scanner.close();
            hangmanGame = new HangmanGame(hiddenWord);
            hangmanGame.playGame();
        }
    }
}
