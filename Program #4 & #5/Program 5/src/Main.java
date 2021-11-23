//Juhwan Lee
//CS202
//Program 5
//This is an implementation of user interface.
//Playlists get created with initial data from the data files.
//And all the playlists get stored in the AVL tree called Canvas.
//Depending on the user type, the user can perform many different functions on the data structure.

import java.util.*;

public class Main {
    protected static Scanner input = null;
    public static void main(String [] args) {
        Canvas canvas = new Canvas();
        canvas.upload_from_file();
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
                    System.out.println("1. Add new subject");
                    System.out.println("2. Display all subjects");
                    System.out.println("3. Move to the subject");
                    System.out.println("4. Remove all subjects");
                    System.out.println("5. Quit");
                    i = input.nextInt();
                    input.nextLine();
                    if (i == 1) {
                        canvas.upload_from_user();
                    }
                    if (i == 2) {
                        canvas.display_all();
                    }
                    if (i == 3) {
                        canvas.move_to_subject_professor();
                    }
                    if (i == 4) {
                        canvas.remove_all();
                    }
                } while (i != 5);
                i = 1;
            }
            if (i == 2) {
                do {
                    System.out.println("What do you want to perform?");
                    System.out.println("1. Display all subjects");
                    System.out.println("2. Move to the subject");
                    System.out.println("3. Quit");
                    i = input.nextInt();
                    input.nextLine();
                    if (i == 1) {
                        canvas.display_all();
                    }
                    if (i == 2) {
                        canvas.move_to_subject_students();
                    }
                } while (i != 3);
                i = 2;
            }
        } while (i != 3);
    }
}
