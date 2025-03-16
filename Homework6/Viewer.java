import java.util.ArrayList;
import java.util.List;

public class Viewer implements Observer {
    private List<NonPlayable> nonPlayables;
    private int currentIndex;

    public Viewer() {
        this.nonPlayables = new ArrayList<>();
        this.currentIndex = -1;
    }

    @Override
    public void update(List<MediaObject> mediaObjects) {
        nonPlayables.clear();
        for (MediaObject mediaObject : mediaObjects) {
            if (mediaObject instanceof NonPlayable) {
                nonPlayables.add((NonPlayable) mediaObject);
            }
        }
        if (!nonPlayables.isEmpty()) {
            currentIndex = 0;
        } else {
            currentIndex = -1;
        }
    }

    public void showList() {
        for (NonPlayable nonPlayable : nonPlayables) {
            nonPlayable.info();
        }
    }

    public NonPlayable currently_viewing() {
        if (currentIndex != -1 && !nonPlayables.isEmpty()) {
            return nonPlayables.get(currentIndex);
        }
        return !nonPlayables.isEmpty() ? nonPlayables.get(0) : new Text("dummy", "0KB");
    }

    public void next(String type) throws NoMoreItemsException {
        if (currentIndex == -1) throw new NoMoreItemsException("No more items to view.");
        for (int i = currentIndex + 1; i < nonPlayables.size(); i++) {
            if ((type.equals("Text") && nonPlayables.get(i) instanceof Text) ||
                (type.equals("Image") && nonPlayables.get(i) instanceof Image)) {
                currentIndex = i;
                return;
            }
        }
        throw new NoMoreItemsException("No more items of type: " + type);
    }

    public void previous(String type) throws NoMoreItemsException {
        if (currentIndex == -1) throw new NoMoreItemsException("No previous items to view.");
        for (int i = currentIndex - 1; i >= 0; i--) {
            if ((type.equals("Text") && nonPlayables.get(i) instanceof Text) ||
                (type.equals("Image") && nonPlayables.get(i) instanceof Image)) {
                currentIndex = i;
                return;
            }
        }
        throw new NoMoreItemsException("No previous items of type: " + type);
    }
}
