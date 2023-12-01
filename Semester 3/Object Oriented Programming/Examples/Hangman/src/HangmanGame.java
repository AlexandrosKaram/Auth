import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

public class HangmanGame {
    private String hiddenWord;
    private Character[] foundLetters;
    private ArrayList<Character> lettersLeft;
    private int lives;


    // Default constructor
    public HangmanGame() {
        lives = 6;
        initializeGame(new WordGenerator().generateRandomWord());
    }

    // Parameterized constructor
    public HangmanGame(String hiddenWord) {
        lives = 6;
        initializeGame(hiddenWord);
    }

    private void initializeGame(String hiddenWord) {
        this.hiddenWord = hiddenWord;

        foundLetters = new Character[hiddenWord.length()];
        for (int i=0 ; i<hiddenWord.length() ; i++) {
            foundLetters[i] = '_';
        }

        lettersLeft = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            lettersLeft.add((char) ('a' + i));
        }
    }

    public void playGame() {
        while (lives > 0 && Arrays.asList(foundLetters).contains('_')) {
            System.out.println("Lives left: " + lives);

            // Print current state
            for (Character foundLetter : foundLetters) {
                System.out.print(foundLetter);
            }
            System.out.println();

            // Print available letters
            System.out.println("You can choose from the following letters");
            for (Character s : lettersLeft) {
                System.out.print(s + " ");
            }
            System.out.println("\n" + "Take a guess: ");

            // Guess a character
            Scanner scanner = new Scanner(System.in);
            Character chosenLetter;
            while (true) {
                try {
                    chosenLetter = scanner.next().charAt(0);
                    if (lettersLeft.contains(chosenLetter)) {
                        lettersLeft.remove(chosenLetter);
                        break;
                    } else {
                        System.out.println("You cannot choose this character... Try again:");
                    }
                } catch (InputMismatchException e) {
                    scanner.nextLine(); // Consume the invalid input
                    System.out.println("Invalid Input... Please choose a valid character:");
                }
            }

            int i = 0;
            boolean found = false;
            for (Character c : hiddenWord.toCharArray()) {
                if (c == chosenLetter) {
                    foundLetters[i] = chosenLetter;
                    found = true;
                }
                i++;
            }
            if (!found) {lives--;}
        }
        if (lives > 0) {
            System.out.println("Congratulations, you won!");
        } else {
            System.out.println("You lost... better luck next time:)");
        }
        System.out.println("The word was " + hiddenWord);
    }
}
