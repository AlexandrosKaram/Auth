import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class NormCalculatorGUI extends JFrame {
    private NormCalculatorLogic calculatorLogic;
    private JTextField rowsField;
    private JTextField colsField;
    private DefaultTableModel matrixModel;
    private JTable matrixTable;

    public NormCalculatorGUI() {
        // Set up the JFrame
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Norm Calculator");
        setLayout(new BorderLayout());

        // Create an instance of NormCalculatorLogic
        calculatorLogic = new NormCalculatorLogic();

        // Panel for entering matrix dimensions
        JPanel dimensionPanel = new JPanel();
        rowsField = new JTextField(5);
        colsField = new JTextField(5);
        JButton createMatrixButton = new JButton("Create Matrix");
        createMatrixButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                createMatrix();
            }
        });
        dimensionPanel.add(new JLabel("Rows:"));
        dimensionPanel.add(rowsField);
        dimensionPanel.add(new JLabel("Cols:"));
        dimensionPanel.add(colsField);
        dimensionPanel.add(createMatrixButton);

        // Matrix Table
        matrixModel = new DefaultTableModel();
        matrixTable = new JTable(matrixModel);
        matrixTable.setCellSelectionEnabled(true);

        // ScrollPane for the matrix table
        JScrollPane scrollPane = new JScrollPane(matrixTable);

        // Add components to the JFrame
        add(dimensionPanel, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);

        // Set frame size
        setSize(400, 300);

        // Center the frame on the screen
        setLocationRelativeTo(null);
    }

    private void createMatrix() {
        try {
            int rows = Integer.parseInt(rowsField.getText());
            int cols = Integer.parseInt(colsField.getText());

            calculatorLogic.initializeMatrix(rows, cols);

            matrixModel.setColumnCount(cols);
            matrixModel.setRowCount(rows);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    matrixModel.setValueAt(calculatorLogic.matrix[i][j], i, j);
                }
            }
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Invalid input. Please enter valid integer values for rows and columns.");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            NormCalculatorGUI editableMatrixUI = new NormCalculatorGUI();
            editableMatrixUI.setVisible(true);
        });
    }
}
