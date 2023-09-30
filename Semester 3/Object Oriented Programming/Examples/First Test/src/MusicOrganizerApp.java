import java.util.Random;

public class MusicOrganizerApp {
    public static void main(String[] args) {
        Random random = new Random();
        MusicOrganizer playlist = new MusicOrganizer();

        Artist[] artists = {
                new Artist("Kanye West"),
                new Artist("Eminem"),
                new Artist("Kendrick Lamar"),
                new Artist("Drake"),
                new Artist("Ariana Grande"),
        };

        for (int i=0 ; i<26 ; i++) {
            String title = String.valueOf((char) ('A' + i));
            // create random track and add it to the playlist
            playlist.addTrack(new Track(
                    title,
                    artists[random.nextInt(5)]
            ));
        }

        playlist.printTracks();
    }
}
