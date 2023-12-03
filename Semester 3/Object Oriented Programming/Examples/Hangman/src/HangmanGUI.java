import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class HangmanGUI extends JFrame {
    private HangmanGame hangmanGame;
    private JLabel wordLabel, livesLabel;
    private JButton[] letterButtons;

    public HangmanGUI(boolean singlePlayer) {
        hangmanGame = singlePlayer ? new HangmanGame() : new HangmanGame("");  // Create game with an empty word for MultiPlayer
        initializeUI();
    }

    public HangmanGUI(boolean singlePlayer, String word) {
        hangmanGame = singlePlayer ? new HangmanGame() : new HangmanGame(word);
        initializeUI();
    }

    private void initializeUI() {
        setTitle("Hangman Game");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        setResizable(false);

        wordLabel = new JLabel(getFormattedWord());
        wordLabel.setFont(new Font("Arial", Font.BOLD, 20));
        add(wordLabel, BorderLayout.CENTER);

        livesLabel = new JLabel("Lives left: " + hangmanGame.getLives());
        add(livesLabel, BorderLayout.NORTH);

        JPanel buttonPanel = new JPanel(new GridLayout(2, 13));
        letterButtons = new JButton[26];
        for (int i = 0; i < 26; i++) {
            char letter = (char) ('a' + i);
            letterButtons[i] = new JButton(String.valueOf(letter));
            letterButtons[i].addActionListener(new LetterButtonListener());
            buttonPanel.add(letterButtons[i]);
        }

        add(buttonPanel, BorderLayout.SOUTH);

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private String getFormattedWord() {
        StringBuilder formattedWord = new StringBuilder();

        for (char letter : hangmanGame.getFoundLetters()) {
            formattedWord.append(letter).append(" ");
        }

        return formattedWord.toString().trim();
    }

    private class LetterButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JButton clickedButton = (JButton) e.getSource();
            char chosenLetter = clickedButton.getText().charAt(0);

            hangmanGame.makeGuess(chosenLetter);

            wordLabel.setText((getFormattedWord()));
            livesLabel.setText("Lives left: " + hangmanGame.getLives());

            SwingUtilities.invokeLater(() -> {
                if (hangmanGame.isGameOver()) {
                    endGame();
                }
            });

            clickedButton.setEnabled(false);
        }

        private void endGame() {
            for (JButton button : letterButtons) {
                button.setEnabled(false);
            }

            int option = JOptionPane.showOptionDialog(
                    HangmanGUI.this,
                    hangmanGame.isGameWon() ? "Congratulations, you won!"+"\nThe hidden word was "+ hangmanGame.getHiddenWord()  :
                            "You lost... better luck next time :)"+"\nThe hidden word was "+ hangmanGame.getHiddenWord(),
                    "Game Over",
                    JOptionPane.YES_NO_OPTION,
                    JOptionPane.INFORMATION_MESSAGE,
                    null,
                    new Object[]{"Play Again", "Exit"},
                    "Play Again"
            );

            if (option == JOptionPane.YES_OPTION) {
                resetGame();
            } else {
                System.exit(0);
            }
        }

        private void resetGame() {
            // Reset the game state
            hangmanGame = new HangmanGame();
            wordLabel.setText(getFormattedWord());
            livesLabel.setText("Lives left: " + hangmanGame.getLives());

            // Enable letter buttons
            for (JButton button : letterButtons) {
                button.setEnabled(true);
            }
        }
    }
}
