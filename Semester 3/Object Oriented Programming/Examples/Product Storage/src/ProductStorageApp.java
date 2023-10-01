public class ProductStorageApp {
    public static void main(String[] args) {
        Storage storage = new Storage();

        Product product1 = new Product("1", "beer", 100);
        Product product2 = new Product("2", "diapers", 200);

        storage.addProduct(product1);
        storage.addProduct(product2);

        storage.printProducts();

        storage.sellProduct("1", 6);
        storage.sellProduct("2", 2);

        storage.printProducts();

        System.out.println("Stock for product 3:" + storage.stockForProductByCode("3"));
    }
}
