public class HangmanGame {
    private String hiddenWord;
    private int lives;

    public HangmanGame() {
        lives = 6;
        WordGenerator wordGenerator = new WordGenerator();
        hiddenWord = wordGenerator.generateRandomWord();
        System.out.println(hiddenWord);
    }

    public HangmanGame(String hiddenWord) {
        lives = 6;
        this.hiddenWord = hiddenWord;
    }
}
