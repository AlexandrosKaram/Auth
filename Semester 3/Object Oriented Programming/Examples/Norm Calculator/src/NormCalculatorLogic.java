import java.util.Arrays;

public class NormCalculatorLogic {
    public int rows, cols;
    public double[][] matrix;

    public NormCalculatorLogic() {
        initializeMatrix(2, 2);
    }

    public NormCalculatorLogic(int rows, int cols) {
        initializeMatrix(rows, cols);
    }

    public void initializeMatrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        matrix = new double[rows][cols];
    }


    // New method to set matrix values
    public void setMatrixValue(int row, int col, double value) {
        matrix[row][col] = value;
    }

    public double calculateOneNorm() {
        return calculateNorm(true);
    }

    public double calculateInfNorm() {
        return calculateNorm(false);
    }

    public double calculateNorm(boolean isOneNorm) {
        double max = 0;

        for (int i = 0; i < (isOneNorm ? cols : rows); i++) {
            double sum = 0;

            for (int j = 0; j < (isOneNorm ? rows : cols); j++) {
                sum += isOneNorm ? Math.abs(matrix[j][i]) : Math.abs(matrix[i][j]);
            }

            max = Math.max(max, sum);
        }

        return max;
    }
}
