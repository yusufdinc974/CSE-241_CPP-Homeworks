import java.util.ArrayList;
import java.util.List;

public class Player implements Observer {
    private List<Playable> playables;
    private int currentIndex;

    public Player() {
        this.playables = new ArrayList<>();
        this.currentIndex = -1;
    }

    @Override
    public void update(List<MediaObject> mediaObjects) {
        playables.clear();
        for (MediaObject mediaObject : mediaObjects) {
            if (mediaObject instanceof Playable) {
                playables.add((Playable) mediaObject);
            }
        }
        if (!playables.isEmpty()) {
            currentIndex = 0;
        } else {
            currentIndex = -1;
        }
    }

    public void showList() {
        for (Playable playable : playables) {
            playable.info();
        }
    }

    public Playable currently_playing() {
        if (currentIndex != -1 && !playables.isEmpty()) {
            return playables.get(currentIndex);
        }
        return !playables.isEmpty() ? playables.get(0) : new Audio("dummy", "00:00", "0KB");
    }

    public void next(String type) throws NoMoreItemsException {
        if (currentIndex == -1) throw new NoMoreItemsException("No more items to play.");
        for (int i = currentIndex + 1; i < playables.size(); i++) {
            if ((type.equals("Audio") && playables.get(i) instanceof Audio) ||
                (type.equals("Video") && playables.get(i) instanceof Video)) {
                currentIndex = i;
                return;
            }
        }
        throw new NoMoreItemsException("No more items of type: " + type);
    }

    public void previous(String type) throws NoMoreItemsException {
        if (currentIndex == -1) throw new NoMoreItemsException("No previous items to play.");
        for (int i = currentIndex - 1; i >= 0; i--) {
            if ((type.equals("Audio") && playables.get(i) instanceof Audio) ||
                (type.equals("Video") && playables.get(i) instanceof Video)) {
                currentIndex = i;
                return;
            }
        }
        throw new NoMoreItemsException("No previous items of type: " + type);
    }
}
