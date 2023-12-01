import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class WordGenerator {
    private static final String API_URL = "https://random-word-api.herokuapp.com/word?number=1";

    public WordGenerator() {}

    public String generateRandomWord() {
        try {
            URL url = new URL(API_URL);
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("GET");

            int responseCode = connection.getResponseCode();
            if (responseCode == HttpURLConnection.HTTP_OK) {
                BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                String line = reader.readLine();
                reader.close();

                // Edit and return the word from JSON response
                return line.replaceAll("\"", "").replace("[", "").replace("]","");
            } else {
                System.out.println("Error: Unable to fetch word from the API. Response code: " + responseCode);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
}
