import java.util.ArrayList;

public class Storage {
    private ArrayList <Product> stock;

    // empty constructor
    public Storage() {
        stock = new ArrayList<>();
    }

    // constructor
    public Storage(int n) {
        stock = new ArrayList<>(n);
    }

    // methods
    public void printProducts() {
        for (Product x : stock) {
            System.out.println(x.toString());
        }
    }

    public void addProduct(Product product) {
        // check if product already exists
        for (Product x : stock) {
            if (product.getCode().equals(x.getCode())) {
                x.setQuantity(x.getQuantity() + product.getQuantity());
                return;
            }
        }
        // add product if not existing
        stock.add(product);
    }

    public void sellProduct(String code, int quantity) {
        for (Product x : stock) {
            if (code.equals(x.getCode())) {
                if (quantity <= x.getQuantity()) {
                    x.setQuantity(x.getQuantity() - quantity);
                } else {
                    System.out.println("Not enough stock for product: " + code);
                }
                return;
            }
        }
        System.out.println("Could not find such product.");
    }

    public int stockForProductByCode(String code) {
        for (Product x : stock) {
            if (x.getCode().equals(code)) {
                return x.getQuantity();
            }
        }
        return 0;
    }
}
