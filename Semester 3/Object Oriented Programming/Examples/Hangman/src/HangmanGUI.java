import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class HangmanGUI extends JFrame {
    private HangmanGame hangmanGame;
    private JLabel wordLabel, livesLabel;
    private JButton[] letterButtons;

    public HangmanGUI() {
        hangmanGame = new HangmanGame();
        initializeUI();
    }

    private void initializeUI() {
        setTitle("Hangman Game");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        wordLabel = new JLabel(getFormattedWord());
        wordLabel.setFont(new Font("Arial", Font.BOLD, 20));
        add(wordLabel, BorderLayout.CENTER);

        livesLabel = new JLabel("Lives left: " + hangmanGame.getLives());
        add(livesLabel, BorderLayout.SOUTH);

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

            if (hangmanGame.isGameOver()) {
                endGame();
            }

            clickedButton.setEnabled(false);
        }

        private void endGame() {
            for (JButton button : letterButtons) {
                button.setEnabled(false);
            }

            JOptionPane.showMessageDialog(
                    HangmanGUI.this,
                    hangmanGame.isGameWon() ? "Congratulations, you won!" :
                            "You lost... better luck next time :)",
                    "Game Over",
                    JOptionPane.INFORMATION_MESSAGE
            );
        }

        public static void main(String[] args) {
            SwingUtilities.invokeLater(() -> new HangmanGUI());
        }
    }
}
