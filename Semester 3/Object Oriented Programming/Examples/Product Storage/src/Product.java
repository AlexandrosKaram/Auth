public class Product {
    private String code;
    private String description;
    private int quantity;

    // empty constructor
    public Product() {
        code = "";
        description = "";
        quantity = 0;
    }

    // constructor
    public Product(String code, String description, int quantity) {
        this.code = code;
        this.description = description;
        this.quantity = quantity;
    }

    // setters
    public void setCode(String code) { this.code = code; }
    public void setDescription(String description) { this.description = description; }
    public void setQuantity(int quantity) { this.quantity = quantity; }

    // getters
    public String getCode() { return code; }
    public String getDescription() { return description; }
    public int getQuantity() { return quantity; }

    // methods
    public String toString() {
        return description + " " + code + ": " + quantity;
    }
}
