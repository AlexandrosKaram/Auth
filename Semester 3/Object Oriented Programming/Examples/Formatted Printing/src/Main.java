public class Main {
    public static void main(String[] args) {
        System.out.printf("Η συμβολοσειρά είναι '%-5s'%n", "α");
        System.out.printf("Η συμβολοσειρά είναι '%.5s'%n","αλφαβήτα");
        System.out.printf("Μικρά %1$s και κεφαλαία %1$S%n","γράμματα");
        System.out.printf("Το πρώτο γράμμα του ονόματος μου είναι %C%n",'γ');
        System.out.printf("Αυτό που απάντησες είναι... %b%n", true);

        byte aByte = 4; System.out.printf("%-4d%n", aByte);
        short aShort = 13; System.out.printf("%2x%n", aShort);
        long aLong = 64; System.out.printf("%2o%n", aLong);
        double f1 = 1.23456789; System.out.printf("%.3f%n", f1);
        double f3 = 0.0000123456789; System.out.printf("%.2e%n", f3);
        int i1 = 43, i2=-27; System.out.printf("% d%n", i1);
        System.out.printf("%,f%n", 1000000000.1234);
        System.out.printf("%05d%n", i1);

    }
}