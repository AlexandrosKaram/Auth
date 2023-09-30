public class Artist {
    private String name, genre;
    private int age;

    public Artist() {}

    public Artist (String name) {
        this.name = name;
    }

    public Artist (String name, String genre, int age) {
        this.name = name;
        this.genre = genre;
        this.age = age;
    }

    public String getName() { return name; }

    public String getGenre() { return genre; }

    public int getAge() { return age; }

    public void setName(String name) { this.name = name; }

    public void setGenre(String genre) { this.genre = genre; }

    public void setAge(int age) { this.age = age; }

    public String toString() {
        String description = "";
        if (name != null) {
            description += name;
        }
        return description;
    }
}
