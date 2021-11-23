//Juhwan Lee
//CS202
//Program 4
//This is an implementation of user interface.
//Playlist gets created with initial data from the data file.
//Depending on the user type, the user can perform many different functions on the data structure.

import java.util.*;

public class Main {
    protected static Scanner input = null;
    public static void main(String [] args){
        Playlist playlist = new Playlist();
        playlist.openFile();
        playlist.readFile();
        playlist.closeFile();
        int i = 0;
        input = new Scanner(System.in);
        do {
            System.out.println("What type of user are you?");
            System.out.println("1. Professor (Administrator)");
            System.out.println("2. Student");
            System.out.println("3. Quit");
            i = input.nextInt();
            input.nextLine();
            if (i == 1) {
                do {
                    System.out.println("What do you want to perform?");
                    System.out.println("1. Upload media (general or specific class)");
                    System.out.println("2. Edit media (general or specific class)");
                    System.out.println("3. Remove media (general or specific class)");
                    System.out.println("4. Remove all medias");
                    System.out.println("5. Display specific playlist (general or specific class)");
                    System.out.println("6. Display the whole playlist");
                    System.out.println("7. Go to media (add quiz, remove quiz, and much more)");
                    System.out.println("8. Quit");
                    i = input.nextInt();
                    input.nextLine();
                    if (i == 1)
                        playlist.upload_from_user();
                    if (i == 2)
                        playlist.edit();
                    if (i == 3)
                        playlist.remove();
                    if (i == 4)
                        playlist.remove_all();
                    if (i == 5)
                        playlist.display();
                    if (i == 6)
                        playlist.display_all();
                    if (i == 7)
                        playlist.professor_go_to_media();
                    if (i < 1 || i > 8)
                        System.out.println("Wrong input!");
                } while (i != 8);
                i = 1;
            }
            if (i == 2) {
                do {
                    System.out.println("What do you want to perform?");
                    System.out.println("1. Display specific playlist (general or specific class)");
                    System.out.println("2. Display the whole playlist");
                    System.out.println("3. Go to media (take quiz, add comments and much more)");
                    System.out.println("4. Quit");
                    i = input.nextInt();
                    input.nextLine();
                    if (i == 1)
                        playlist.display();
                    if (i == 2)
                        playlist.display_all();
                    if (i == 3)
                        playlist.students_go_to_media();
                    if (i < 1 || i > 4)
                        System.out.println("Wrong input!");
                } while (i != 4);
                i = 2;
            }
            if (i < 1 || i > 3)
                System.out.println("Wrong input!");
        } while (i != 3);
    }
}
