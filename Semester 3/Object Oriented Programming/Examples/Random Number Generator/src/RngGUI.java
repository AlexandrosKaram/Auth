import javax.swing.*;
import java.awt.*;

public class RngGUI extends JFrame {
    private JCheckBox checkBox;
    private JTextField textField;
    private JButton button;
    private RngLogic rng;

    public RngGUI() {
        rng = new RngLogic();
        checkBox = new JCheckBox("Double");
        textField = new JTextField(15);  // Set columns for preferred width
        button = new JButton("Generate");

        initializeUI();
    }

    private void initializeUI() {
        setTitle("Random Number Generator");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setResizable(false);
        setLayout(new FlowLayout());
        setSize(new Dimension(300, 100));

        button.addActionListener(e -> {
            if (!checkBox.isSelected()) {
                textField.setText(String.valueOf(rng.randomInt()));
            } else {
                textField.setText(String.valueOf(rng.randomDouble()));
            }
        });

        add(button);
        add(checkBox);
        add(textField);

        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new RngGUI());
    }
}
