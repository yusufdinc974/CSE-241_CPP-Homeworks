public class Audio extends MediaObject implements Playable, NonVisual {
    private String duration;
    private String otherInfo;

    public Audio(String name, String duration, String otherInfo) {
        super(name);
        this.duration = duration;
        this.otherInfo = otherInfo;
    }

    @Override
    public void play() {
        System.out.println("Playing audio: " + name);
    }

    @Override
    public void info() {
        System.out.println("Audio Info: " + name + ", " + duration + ", " + otherInfo);
    }
}
