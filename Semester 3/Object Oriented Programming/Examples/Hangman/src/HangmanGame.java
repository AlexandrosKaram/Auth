import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

public class HangmanGame {
    private String hiddenWord;
    private char[] foundLetters;
    private ArrayList<Character> lettersLeft;
    private int lives;


    // Default constructor
    public HangmanGame() {
        initializeGame(new WordGenerator().generateRandomWord());
    }

    // Parameterized constructor
    public HangmanGame(String hiddenWord) {
        initializeGame(hiddenWord);
    }

    private void initializeGame(String hiddenWord) {
        lives = 6;
        this.hiddenWord = hiddenWord;

        foundLetters = new char[hiddenWord.length()];
        for (int i=0 ; i<hiddenWord.length() ; i++) {
            foundLetters[i] = '_';
        }

        lettersLeft = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            lettersLeft.add((char) ('a' + i));
        }
    }

    public char[] getFoundLetters() {
        char[] foundLettersArray = new char[foundLetters.length];
        for (int i=0 ; i<foundLetters.length ; i++) {
            foundLettersArray[i] = foundLetters[i];
        }

        return foundLettersArray;
    }

    public int getLives() { return lives; }


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

    public void makeGuess(char letter) {
        boolean found = false;

        for (int i = 0; i < hiddenWord.length(); i++) {
            if (hiddenWord.charAt(i) == letter) {
                foundLetters[i] = letter;
                found = true;
            }
        }

        if (!found) {
            lives--;
        }
    }

    public boolean isGameOver() {
        return lives == 0 || (!Arrays.asList(foundLetters).contains('_'));
    }

    public boolean isGameWon() {
        return Arrays.asList(foundLetters).contains('_');
    }
}
