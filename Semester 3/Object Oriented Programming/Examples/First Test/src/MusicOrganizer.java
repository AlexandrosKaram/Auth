import java.util.ArrayList;

public class MusicOrganizer {
    private ArrayList <Track> tracklist;

    public MusicOrganizer() {
        tracklist = new ArrayList<>();
    }

    public void addTrack(Track track) {
        tracklist.add(track);
    }

    public void removeTrack(int index) {
        tracklist.remove(index-1);
    }

    public void removeTrack(Track track) {
        tracklist.remove(track);
    }

    public void printTracks() {
        int i = 1;
        for (Track x : tracklist) {
            System.out.println(i + ". " + x.toString());
            i++;
        }
    }
}
