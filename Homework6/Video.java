public class Video extends MediaObject implements Playable, Visual {
    private String duration;
    private String otherInfo;

    public Video(String name, String duration, String otherInfo) {
        super(name);
        this.duration = duration;
        this.otherInfo = otherInfo;
    }

    @Override
    public void play() {
        System.out.println("Playing video: " + name);
    }

    @Override
    public void info() {
        System.out.println("Video Info: " + name + ", " + duration + ", " + otherInfo);
    }
}
