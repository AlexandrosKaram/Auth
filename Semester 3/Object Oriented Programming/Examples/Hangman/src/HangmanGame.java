import java.util.ArrayList;
import java.util.Arrays;

public class HangmanGame {
    private String hiddenWord;
    private char[] foundLetters;
    private boolean[] letterGuessed;
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

        foundLetters = new char[hiddenWord.length()];
        Arrays.fill(foundLetters, '_');

        letterGuessed = new boolean[26];
        Arrays.fill(letterGuessed, false);
    }

    public char[] getFoundLetters() { return Arrays.copyOf(foundLetters, foundLetters.length); }

    public int getLives() { return lives; }

    public void makeGuess(char letter) {
        if (!letterGuessed[letter - 'a']) {
            letterGuessed[letter - 'a'] = true;
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
    }

    public boolean isGameOver() {
        return (lives <= 0 || !(Arrays.asList(foundLetters).contains('_')));
    }

    public boolean isGameWon() {
        return !(Arrays.asList(foundLetters).contains('_'));
    }
}
