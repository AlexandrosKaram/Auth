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
        for (int i=0 ; i<hiddenWord.length() ; i++){
            foundLetters[i] = '_';
        }

        letterGuessed = new boolean[26];
        for (int i=0 ; i<26 ; i++) {
            letterGuessed[i] = false;
        }
    }

    public char[] getFoundLetters() { return Arrays.copyOf(foundLetters, foundLetters.length); }

    public int getLives() { return lives; }

    public String getHiddenWord() { return hiddenWord; }

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
        boolean found = true;
        for (char c : foundLetters) {
            if (c == '_') {
                found = false;
                break;
            }
        }
        return lives == 0 || found;
    }

    public boolean isGameWon() {
        boolean found = true;
        for (char c : foundLetters) {
            if (c == '_') {
                found = false;
                break;
            }
        }
        return found;
    }
}
