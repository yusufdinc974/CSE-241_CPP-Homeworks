public class Image extends MediaObject implements NonPlayable, Visual {
    private String dimensionInfo;
    private String otherInfo;

    public Image(String name, String dimensionInfo, String otherInfo) {
        super(name);
        this.dimensionInfo = dimensionInfo;
        this.otherInfo = otherInfo;
    }

    @Override
    public void display() {
        System.out.println("Displaying image: " + name);
    }

    @Override
    public void info() {
        System.out.println("Image Info: " + name + ", " + dimensionInfo + ", " + otherInfo);
    }
}
