import javax.swing.*;

public class HangmanApp {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> chooseGameMode());
    }

    private static void chooseGameMode() {
        String[] options = {"SinglePlayer", "MultiPlayer"};
        int choice = JOptionPane.showOptionDialog(
                null,
                "Choose Game Mode:",
                "Hangman Game",
                JOptionPane.DEFAULT_OPTION,
                JOptionPane.QUESTION_MESSAGE,
                null,
                options,
                options[0]
        );

        if (choice == 0) {
            new HangmanGUI(true);  // SinglePlayer mode
        } else if (choice == 1) {
            String hiddenWord;
            while (true) {
                hiddenWord = JOptionPane.showInputDialog("Enter a word for MultiPlayer:");
                if (hiddenWord == null) {
                    // User canceled input, return to game mode selection
                    chooseGameMode();
                    return;
                }

                hiddenWord = hiddenWord.toLowerCase();
                if (isValidWord(hiddenWord)) {
                    break;
                } else {
                    JOptionPane.showMessageDialog(null, "Invalid word. Please enter a valid word.");
                }
            }

            // Proceed to MultiPlayer with the valid hiddenWord
            new HangmanGUI(false, hiddenWord);
        } else {
            // Handle unexpected choice
        }
    }

    private static boolean isValidWord(String word) {
        for (char c : word.toCharArray()) {
            if (!(c >= 'a' && c <= 'z')) {
                return false;
            }
        }
        return true;
    }
}