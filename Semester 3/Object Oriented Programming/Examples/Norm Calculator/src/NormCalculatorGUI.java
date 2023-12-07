import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;

public class NormCalculatorGUI extends JFrame {
    private NormCalculator normCalculator;
    private JTextField rowsField, colsField, resultField;
    private JPanel topSection, midSection, bottomSection;
    private JButton createMatrixButton, calculateNormButton;
    private JTable matrixTable;

    public NormCalculatorGUI() {
        // Initialize UI
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Norm Calculator");
        setSize(new Dimension(400, 300));
        setLayout(new BorderLayout());
        setLocationRelativeTo(null);

        // Set up top-section components
        topSection = new JPanel();
        rowsField = new JTextField(5);
        colsField = new JTextField(5);
        createMatrixButton = new JButton("Create Matrix");

        // Set up mid-section components
        midSection = new JPanel();
        // Create table
        DefaultTableModel model = new DefaultTableModel();
        matrixTable = new JTable(model);

        // Set up bottom-section components
        bottomSection = new JPanel();
        calculateNormButton = new JButton("Calculate");
        resultField = new JTextField(5);

        // Add components to top-section
        topSection.add(new JLabel("Rows: "));
        topSection.add(rowsField);
        topSection.add(new JLabel("Cols: "));
        topSection.add(colsField);
        topSection.add(createMatrixButton);

        // Add components to mid-section
        midSection.add(matrixTable);

        // Add components to bottom-section
        bottomSection.add(calculateNormButton);
        bottomSection.add(resultField);

        // Event listener for createMatrixButton
        createMatrixButton.addActionListener(e -> {
            // Parse text from textField
            int rows = Integer.parseInt(rowsField.getText());
            int cols = Integer.parseInt(colsField.getText());

            // back-end
            normCalculator = new NormCalculator(rows, cols);

            // front-end
            DefaultTableModel tableModel = new DefaultTableModel(rows, cols);
            matrixTable.setModel(tableModel);
            initializeTable();

            // testing
            normCalculator.printMatrix();
        });

        // Event listener for calculateNormButton
        calculateNormButton.addActionListener(e -> {
            parseContentToApi();

            resultField.setText(String.valueOf(normCalculator.calculateOneNorm()));
        });

        // Add sections to frame
        add(topSection, BorderLayout.NORTH);
        add(midSection, BorderLayout.CENTER);
        add(bottomSection, BorderLayout.SOUTH);
    }


    private void initializeTable() {
        for (int i = 0; i < matrixTable.getRowCount(); i++) {
            for (int j = 0; j < matrixTable.getColumnCount(); j++) {
                matrixTable.setValueAt(0, i, j);
            }
        }
    }

    private void parseContentToApi() {
        for (int i = 0; i < matrixTable.getRowCount(); i++) {
            for (int j = 0; j < matrixTable.getColumnCount(); j++) {
                double value = Double.parseDouble(matrixTable.getValueAt(i, j).toString());
                normCalculator.setValueAt(value, i, j);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater( () -> {
            new NormCalculatorGUI();
        });
    }
}