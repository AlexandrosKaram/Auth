import java.util.ArrayList;

public class HangmanGame {
    private String hiddenWord;
    private ArrayList<String> foundLetters;
    private int lives;
    private String[] lettersLeft = {
            "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
            "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
    };

    // Default constructor
    public HangmanGame() {
        this.lives = 6;
        initializeGame(new WordGenerator().generateRandomWord());
    }

    // Parameterized constructor
    public HangmanGame(String hiddenWord) {
        this.lives = 6;
        initializeGame(hiddenWord);
    }

    private void initializeGame(String hiddenWord) {
        this.hiddenWord = hiddenWord;

        foundLetters = new ArrayList<>();
        for (char c : hiddenWord.toCharArray()) {
            foundLetters.add("_");
        }
    }
}
