public class Main {
    public static void main(String[] args) {
        Dataset ds = new Dataset();

        Player p1 = new Player();
        Player p2 = new Player();
        Viewer v1 = new Viewer();
        Viewer v2 = new Viewer();

        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);

        ds.add(new Image("img1", "609KB", "11.07.2022 13:15"));
        ds.add(new Image("img2", "697KB", "23.10.2021 21:56"));
        ds.add(new Image("img3", "314KB", "4.05.2022 10:53"));
        ds.add(new Image("img4", "950KB", "12.10.2019 13:38"));
        ds.add(new Image("img5", "109KB", "13.08.2022 11:51"));
        ds.add(new Audio("audio1", "00:04:21", "3.18MB"));
        ds.add(new Audio("audio2", "00:00:19", "486KB"));
        ds.add(new Audio("audio3", "00:03:55", "5.70MB"));
        ds.add(new Video("video1", "00:01:34", "192MB"));
        ds.add(new Video("video2", "00:00:10", "13.9MB"));
        ds.add(new Video("video3", "00:06:16", "17.6MB"));
        ds.add(new Text("txt1", "3.71KB"));
        ds.add(new Text("txt2", "2.54KB"));
        ds.add(new Text("txt3", "206BYTES"));

        try {
            // Player 1 operations
            p1.showList();
            System.out.print("\n");

            // Continue playing audio until no more items
            try {
                while (true) {
                    p1.next("Audio");
                    Playable po1 = p1.currently_playing();
                    po1.info();
                    System.out.print("\n");
                    ds.remove(po1);
                }
            } catch (NoMoreItemsException e) {
                System.out.println("Error: " + e.getMessage());
            }

            // Show updated list
            p1.showList();
            System.out.print("\n");

            // Player 2 operations
            p2.showList();
            System.out.print("\n");

            try {
                p2.next("Video");
                Playable po2 = p2.currently_playing();
                po2.info();
                System.out.print("\n");

                p2.next("Video");
                po2 = p2.currently_playing();
                po2.info();
                System.out.print("\n");

                p2.previous("Video");
                po2 = p2.currently_playing();
                po2.info();
                System.out.print("\n");
            } catch (NoMoreItemsException e) {
                System.out.println("Error: " + e.getMessage());
            }

            // Viewer 1 operations
            v1.showList();
            System.out.print("\n");

            try {
                v1.next("Image");
                v1.next("Image");
                v1.next("Image");
                v1.next("Image");
                NonPlayable np1 = v1.currently_viewing();
                np1.info();
                System.out.print("\n");

                v1.previous("Image");
                v1.previous("Image");
                np1 = v1.currently_viewing();
                np1.info();
                System.out.print("\n");
                ds.remove(np1);
            } catch (NoMoreItemsException e) {
                System.out.println("Error: " + e.getMessage());
            }

            // Viewer 2 operations
            v2.showList();
            System.out.print("\n");

            try {
                v2.next("Text");
                NonPlayable np2 = v2.currently_viewing();
                np2.info();
                System.out.print("\n");
                ds.remove(np2);

                v2.next("Text");
                np2 = v2.currently_viewing();
                np2.info();
                System.out.print("\n");
                ds.remove(np2);

                v2.previous("Text");
                np2 = v2.currently_viewing();
                np2.info();
                System.out.print("\n");

                ds.remove(np2);

                v2.next("Text");
                np2 = v2.currently_viewing();
                ds.remove(np2);

                v2.next("Text");
                np2 = v2.currently_viewing();
                ds.remove(np2);

                v2.next("Image");
                np2 = v2.currently_viewing();
                ds.remove(np2);

                v2.next("Image");
                np2 = v2.currently_viewing();
                ds.remove(np2);

                v2.next("Image");
                np2 = v2.currently_viewing();
                ds.remove(np2);

                v2.next("Image");
                np2 = v2.currently_viewing();
                ds.remove(np2);

                v2.showList();
            } catch (NoMoreItemsException e) {
                System.out.println("Error: " + e.getMessage());
            }
        } catch (Exception e) {
            // Handle any other exceptions here
            e.printStackTrace();
        }
    }
}
