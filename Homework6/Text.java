public class Text extends MediaObject implements NonPlayable, NonVisual {
    private String otherInfo;

    public Text(String name, String otherInfo) {
        super(name);
        this.otherInfo = otherInfo;
    }

    @Override
    public void display() {
        System.out.println("Displaying text: " + name);
    }

    @Override
    public void info() {
        System.out.println("Text Info: " + name + ", " + otherInfo);
    }
}
