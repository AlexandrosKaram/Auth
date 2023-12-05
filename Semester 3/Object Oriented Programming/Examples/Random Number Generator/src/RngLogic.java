import java.util.Random;

public class RngLogic {
    Random random;

    public RngLogic() {
        random = new Random();
    }

    public double randomDouble() {
        return random.nextDouble();
    }

    public int randomInt() {
        return random.nextInt();
    }
}
