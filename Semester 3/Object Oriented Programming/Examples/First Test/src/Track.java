public class Track {
    private String title;
    private Artist artist;

    public Track() {}

    public Track(String title) {
        this.title = title;
    }

    public Track(String title, Artist artist) {
        this.title = title;
        this.artist = artist;
    }

    public void setTitle(String Title) { this.title = title; }

    public void setArtist(Artist artist) { this.artist = artist; }

    public String getTitle() { return title; }

    public Artist getArtist() { return artist; }

    public String toString() {
        String description = "";
        description += title;
        if (artist != null) {
            description += " - " + artist.toString();
        }
        return description;
    }
}
