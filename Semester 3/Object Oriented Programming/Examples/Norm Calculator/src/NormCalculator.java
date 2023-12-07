public class NormCalculator {
    private int rows, cols;
    private double[][] matrix;

    public NormCalculator() {
        initializeMatrix(2, 2);
    }

    public NormCalculator(int rows, int cols) {
        initializeMatrix(rows, cols);
    }

    public void initializeMatrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        matrix = new double[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }


    // New method to set matrix values
    public void setValueAt(double value, int row, int col) {
        matrix[row][col] = value;
    }

    public double calculateOneNorm() {
        return calculateNorm(true);
    }

    public double calculateInfNorm() {
        return calculateNorm(false);
    }

    private double calculateNorm(boolean isOneNorm) {
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

    public int getRows() { return rows; }

    public int getCols() { return cols; }

    public void setRows() { this.rows = rows; }

    public void setCols() { this.cols = cols; }

    public double getValueAt(int rows, int cols) {
        return matrix[rows][cols];
    }

    public void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public double[][] getData() {
        double[][] tempMatrix = new double[rows][cols];

        // deep copying main matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                tempMatrix[i][j] = matrix[i][j];
            }
        }

        return tempMatrix;
    }
}
