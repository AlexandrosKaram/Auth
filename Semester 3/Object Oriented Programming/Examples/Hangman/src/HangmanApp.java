import javax.swing.*;

public class HangmanApp {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new HangmanGUI());
    }
}