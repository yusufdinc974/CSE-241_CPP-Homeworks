import java.util.ArrayList;
import java.util.List;

public class Dataset {
    private List<Observer> observers = new ArrayList<>();
    private List<MediaObject> mediaObjects = new ArrayList<>();

    public void register(Observer observer) {
        observers.add(observer);
    }

    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    public void add(MediaObject mediaObject) {
        mediaObjects.add(mediaObject);
        notifyObservers();
    }

    public void remove(MediaObject mediaObject) {
        mediaObjects.remove(mediaObject);
        notifyObservers();
    }

    public void remove(Playable playable) {
        mediaObjects.remove((MediaObject)playable);
        notifyObservers();
    }
    
    public void remove(NonPlayable nonPlayable) {
        mediaObjects.remove((MediaObject)nonPlayable);
        notifyObservers();
    }
    

    private void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(mediaObjects);
        }
    }
}
