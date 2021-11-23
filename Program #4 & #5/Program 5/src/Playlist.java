//Juhwan Lee
//CS202
//Program 5
//This is an implementation of an array of linear linked lists.
//There are four linear linked lists, each representing a different class.
//The first list is General, the second is Class 1, the third is Class 2, and the fourth is Class 3.
//And each node has media data.

import java.io.*;
import java.util.*;

public class Playlist {
    protected String name;
    protected Node[] head;
    protected int size = 4;
    protected static Scanner input = null;
    protected Scanner x;
    //open file
    public void openFile(int i){
        try{
            if(i == 1)
                x = new Scanner(new File("computer science.txt"));
            if(i == 2)
                x = new Scanner(new File("chemistry.txt"));
            if(i == 3)
                x = new Scanner(new File("mathematics.txt"));
            if(i == 4)
                x = new Scanner(new File("university studies.txt"));
        }
        catch(Exception e){
            System.out.println("Could not find file");
        }
    }
    //The data is read and entered into the array of linear linked lists.
    public void readFile(){
        String type = "";
        String class_name = "";
        String name = "";
        String description = "";
        String attachments = "";
        int i = 0;
        while (x.hasNext()) {
            if (i < 5) {
                if (i == 0)
                    type = x.nextLine();
                if (i == 1)
                    class_name = x.nextLine();
                if (i == 2)
                    name = x.nextLine();
                if (i == 3)
                    description = x.nextLine();
                if (i == 4)
                    attachments = x.nextLine();
                if (i == 4 && type.equals("general")) {
                    General temp = new General(class_name, name, description, attachments);
                    //add temp to array of linear linked lists
                    upload_from_file(temp);
                }
                if (i == 4 && type.equals("class1")) {
                    Class1 temp = new Class1 (class_name, name, description, attachments);
                    //add temp to array of linear linked lists
                    upload_from_file(temp);
                }
                if (i == 4 && type.equals("class2")) {
                    Class2 temp = new Class2(class_name, name, description, attachments);
                    //add temp to array of linear linked lists
                    upload_from_file(temp);
                }
                if (i == 4 && type.equals("class3")) {
                    Class3 temp = new Class3(class_name, name, description, attachments);
                    //add temp to array of linear linked lists
                    upload_from_file(temp);
                }
            }
            ++i;
            if (i == 5)
                i = 0;
        }
    }
    //close file
    public void closeFile(){
        x.close();
    }
    //default constructor
    public Playlist(int j){
        if(j == 0){
            input = new Scanner(System.in);
            System.out.print("Please enter the name of the subject: ");
            this.name = input.nextLine();
        }
        if(j == 1)
            this.name = "Computer Science";
        if(j == 2)
            this.name = "Chemistry";
        if(j == 3)
            this.name = "Mathematics";
        if(j == 4)
            this.name = "University Studies";
        this.head = new Node[size];
        for(int i = 0; i < size; ++i){
            this.head[i] = null;
        }
    }
    //insert from the file
    public void upload_from_file(Media data){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        if(data.media_type() == 0)
            this.head[0] = upload(head[0], data);
        if(data.media_type() == 1)
            this.head[1] = upload(head[1], data);
        if(data.media_type() == 2)
            this.head[2] = upload(head[2], data);
        if(data.media_type() == 3)
            this.head[3] = upload(head[3], data);
    }
    //insert from the user
    public void upload_from_user(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        input = new Scanner(System.in);
        int i = 0;
        System.out.println("What type of media do you want to upload?");
        if(head[0] == null)
            System.out.println("1. Empty");
        else {
            System.out.print("1. ");
            head[0].get_data().display_class_name();
        }
        if(head[1] == null)
            System.out.println("2. Empty");
        else {
            System.out.print("2. ");
            head[1].get_data().display_class_name();
        }
        if(head[2] == null)
            System.out.println("3. Empty");
        else {
            System.out.print("3. ");
            head[2].get_data().display_class_name();
        }
        if(head[3] == null)
            System.out.println("4. Empty");
        else {
            System.out.print("4. ");
            head[3].get_data().display_class_name();
        }
        i = input.nextInt();
        input.nextLine();
        if(i == 1){
            General temp = new General();
            temp.set_media();
            this.head[0] = upload(head[0], temp);
            System.out.println("Media uploaded");
        }
        if(i == 2){
            Class1 temp = new Class1();
            temp.set_media();
            this.head[1] = upload(head[1], temp);
            System.out.println("Media uploaded");
        }
        if(i == 3){
            Class2 temp = new Class2();
            temp.set_media();
            this.head[2] = upload(head[2], temp);
            System.out.println("Media uploaded");
        }
        if(i == 4){
            Class3 temp = new Class3();
            temp.set_media();
            this.head[3] = upload(head[3], temp);
            System.out.println("Media uploaded");
        }
        if(i < 1 || i > 4)
            System.out.println("Wrong input!");
    }
    //recursive method for insertion
    private Node upload(Node head, Media data){
        if(head == null){
            head = new Node();
            head.set_data(data);
            head.set_next(null);
            return head;
        }
        head.set_next(upload(head.get_next(), data));
        return head;
    }
    //wrapper method for removal
    public void remove(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        input = new Scanner(System.in);
        int i = 0;
        String name = "";
        System.out.println("What type of media do you want to delete?");
        if(head[0] == null)
            System.out.println("1. Empty");
        else {
            System.out.print("1. ");
            head[0].get_data().display_class_name();
        }
        if(head[1] == null)
            System.out.println("2. Empty");
        else {
            System.out.print("2. ");
            head[1].get_data().display_class_name();
        }
        if(head[2] == null)
            System.out.println("3. Empty");
        else {
            System.out.print("3. ");
            head[2].get_data().display_class_name();
        }
        if(head[3] == null)
            System.out.println("4. Empty");
        else {
            System.out.print("4. ");
            head[3].get_data().display_class_name();
        }
        i = input.nextInt();
        input.nextLine();
        if(i < 1 || i > 4) {
            System.out.println("Wrong input!");
            return;
        }
        if(i == 1)
            display(head[0]);
        if(i == 2)
            display(head[1]);
        if(i == 3)
            display(head[2]);
        if(i == 4)
            display(head[3]);
        System.out.print("Enter the video title you want to delete: ");
        name = input.nextLine();
        if(i == 1)
            this.head[0] = remove(head[0], name);
        if(i == 2)
            this.head[1] = remove(head[1], name);
        if(i == 3)
            this.head[2] = remove(head[2], name);
        if(i == 4)
            this.head[3] = remove(head[3], name);
    }
    //recursive method for removal
    private Node remove(Node head, String name) {
        if(head == null){
            System.out.println("There was no match!");
            return null;
        }
        if(head.get_data().compare_name(name) == 1){
            head = head.get_next();
            System.out.println("Media deleted");
            return head;
        }
        head.set_next(remove(head.get_next(), name));
        return head;
    }
    //remove all method
    public void remove_all(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        for(int i = 0; i < size; ++i){
            this.head[i] = null;
        }
        System.out.println("All medias are deleted");
    }
    //wrapper method for display
    public int display(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return 0;
        }
        int i = 0;
        input = new Scanner(System.in);
        System.out.println("Which playlist do you want to display?");
        if(head[0] == null)
            System.out.println("1. Empty");
        else {
            System.out.print("1. ");
            head[0].get_data().display_class_name();
        }
        if(head[1] == null)
            System.out.println("2. Empty");
        else {
            System.out.print("2. ");
            head[1].get_data().display_class_name();
        }
        if(head[2] == null)
            System.out.println("3. Empty");
        else {
            System.out.print("3. ");
            head[2].get_data().display_class_name();
        }
        if(head[3] == null)
            System.out.println("4. Empty");
        else {
            System.out.print("4. ");
            head[3].get_data().display_class_name();
        }
        i = input.nextInt();
        input.nextLine();
        if(i == 1)
            return display(head[0]);
        if(i == 2)
            return display(head[1]);
        if(i == 3)
            return display(head[2]);
        if(i == 4)
            return display(head[3]);
        else {
            System.out.println("Wrong input!");
            return 0;
        }
    }
    //recursive method for display
    private int display(Node head){
        if(head == null)
            return 0;
        head.get_data().display();
        return display(head.get_next());
    }
    //wrapper method for display all
    public int display_all(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return 0;
        }
        for(int i = 0; i < size; ++i){
            display(head[i]);
        }
        return 1;
    }
    //wrapper method for edit
    public void edit(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        int i = 0;
        String name = "";
        input = new Scanner(System.in);
        System.out.println("What type of media do you want to edit?");
        if(head[0] == null)
            System.out.println("1. Empty");
        else {
            System.out.print("1. ");
            head[0].get_data().display_class_name();
        }
        if(head[1] == null)
            System.out.println("2. Empty");
        else {
            System.out.print("2. ");
            head[1].get_data().display_class_name();
        }
        if(head[2] == null)
            System.out.println("3. Empty");
        else {
            System.out.print("3. ");
            head[2].get_data().display_class_name();
        }
        if(head[3] == null)
            System.out.println("4. Empty");
        else {
            System.out.print("4. ");
            head[3].get_data().display_class_name();
        }
        i = input.nextInt();
        input.nextLine();
        if (i < 1 || i > 4) {
            System.out.println("Wrong input!");
            return;
        }
        if(i == 1)
            display(head[0]);
        if(i == 2)
            display(head[1]);
        if(i == 3)
            display(head[2]);
        if(i == 4)
            display(head[3]);
        System.out.print("Enter the video title you want to edit: ");
        name = input.nextLine();
        if(i == 1)
            this.head[0] = edit(head[0], name);
        if(i == 2)
            this.head[1] = edit(head[1], name);
        if(i == 3)
            this.head[2] = edit(head[2], name);
        if(i == 4)
            this.head[3] = edit(head[3], name);
    }
    //recursive method for edit
    private Node edit(Node head, String name){
        if(head == null){
            System.out.println("There was no match!");
            return null;
        }
        if(head.get_data().compare_name(name) == 1){
            head.get_data().edit_media();
            return head;
        }
        head.set_next(edit(head.get_next(), name));
        return head;
    }
    //This method allows a student to navigate to a specific playlist, navigate to a specific media,
    //and perform various functions.
    public void students_go_to_media(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        int i = 0;
        String name = "";
        input = new Scanner(System.in);
        System.out.println("Where do you want to go?");
        if(head[0] == null)
            System.out.println("1. Empty");
        else {
            System.out.print("1. ");
            head[0].get_data().display_class_name();
        }
        if(head[1] == null)
            System.out.println("2. Empty");
        else {
            System.out.print("2. ");
            head[1].get_data().display_class_name();
        }
        if(head[2] == null)
            System.out.println("3. Empty");
        else {
            System.out.print("3. ");
            head[2].get_data().display_class_name();
        }
        if(head[3] == null)
            System.out.println("4. Empty");
        else {
            System.out.print("4. ");
            head[3].get_data().display_class_name();
        }
        i = input.nextInt();
        input.nextLine();
        if(i == 1){
            display(head[0]);
            System.out.print("Enter the video title you want to go: ");
            name = input.nextLine();
            this.head[0] = students_go_to_media(head[0], name);
        }
        if(i == 2){
            display(head[1]);
            System.out.print("Enter the video title you want to go: ");
            name = input.nextLine();
            this.head[1] = students_go_to_media(head[1], name);
        }
        if(i == 3){
            display(head[2]);
            System.out.print("Enter the video title you want to go: ");
            name = input.nextLine();
            this.head[2] = students_go_to_media(head[2], name);
        }
        if(i == 4){
            display(head[3]);
            System.out.print("Enter the video title you want to go: ");
            name = input.nextLine();
            this.head[3] = students_go_to_media(head[3], name);
        }
        if (i < 1 || i > 4)
            System.out.println("Wrong input!");
    }
    //recursive method for students go to media
    private Node students_go_to_media(Node head, String name){
        if(head == null){
            System.out.println("There was no match!");
            return null;
        }
        if(head.get_data().compare_name(name) == 1){
            head.get_data().count_views();
            head.get_data().display();
            int i = 0;
            input = new Scanner(System.in);
            do {
                System.out.println("What do you want to perform?");
                System.out.println("1. Add comments");
                System.out.println("2. Remove comments");
                System.out.println("3. Take quiz");
                System.out.println("4. Quit");
                i = input.nextInt();
                input.nextLine();
                if (i == 1)
                    head.get_data().set_comments();
                if (i == 2)
                    head.get_data().remove_comments();
                if (i == 3)
                    head.get_data().take_quiz();
                if (i < 1 || i > 4)
                    System.out.println("Wrong input!");
            } while (i != 4);
            return head;
        }
        head.set_next(students_go_to_media(head.get_next(), name));
        return head;
    }
    //This method allows professor (administrator) to navigate to a specific playlist, navigate to a specific media,
    //and perform various functions.
    public void professor_go_to_media(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        int i = 0;
        String name = "";
        input = new Scanner(System.in);
        System.out.println("Where do you want to go?");
        if(head[0] == null)
            System.out.println("1. Empty");
        else {
            System.out.print("1. ");
            head[0].get_data().display_class_name();
        }
        if(head[1] == null)
            System.out.println("2. Empty");
        else {
            System.out.print("2. ");
            head[1].get_data().display_class_name();
        }
        if(head[2] == null)
            System.out.println("3. Empty");
        else {
            System.out.print("3. ");
            head[2].get_data().display_class_name();
        }
        if(head[3] == null)
            System.out.println("4. Empty");
        else {
            System.out.print("4. ");
            head[3].get_data().display_class_name();
        }
        i = input.nextInt();
        input.nextLine();
        if(i == 1){
            display(head[0]);
            System.out.print("Enter the video title you want to go: ");
            name = input.nextLine();
            this.head[0] = professor_go_to_media(head[0], name);
        }
        if(i == 2){
            display(head[1]);
            System.out.print("Enter the video title you want to go: ");
            name = input.nextLine();
            this.head[1] = professor_go_to_media(head[1], name);
        }
        if(i == 3){
            display(head[2]);
            System.out.print("Enter the video title you want to go: ");
            name = input.nextLine();
            this.head[2] = professor_go_to_media(head[2], name);
        }
        if(i == 4){
            display(head[3]);
            System.out.print("Enter the video title you want to go: ");
            name = input.nextLine();
            this.head[3] = professor_go_to_media(head[3], name);
        }
        if(i < 1 || i > 4)
            System.out.println("Wrong input!");
    }
    //recursive method for professor go to media
    private Node professor_go_to_media(Node head, String name){
        if(head == null){
            System.out.println("There was no match!");
            return null;
        }
        if(head.get_data().compare_name(name) == 1){
            head.get_data().count_views();
            head.get_data().display();
            int i = 0;
            input = new Scanner(System.in);
            do {
                System.out.println("What do you want to perform?");
                System.out.println("1. Edit media");
                System.out.println("2. Remove media");
                System.out.println("3. Add comments");
                System.out.println("4. Remove comments");
                System.out.println("5. Add quiz question");
                System.out.println("6. Remove quiz question");
                System.out.println("7. Quit");
                i = input.nextInt();
                input.nextLine();
                if (i == 1)
                    head.get_data().edit_media();
                if (i == 2) {
                    head = head.get_next();
                    i = 7;
                }
                if (i == 3)
                    head.get_data().set_comments();
                if (i == 4)
                    head.get_data().remove_comments();
                if (i == 5)
                    head.get_data().set_quiz();
                if (i == 6)
                    head.get_data().remove_quiz();
                if (i < 1 || i > 7)
                    System.out.println("Wrong input!");
            } while (i != 7);
            return head;
        }
        head.set_next(professor_go_to_media(head.get_next(), name));
        return head;
    }
    //This method compares subject names to determine which data is small and large. Used in AVL tree.
    public int compare_string(String name){
        return this.name.compareTo(name);
    }
    //This method compares subject names to determine which data is small and large. Used in AVL tree.
    public int compare(Playlist playlist){
        return this.name.compareTo(playlist.name);
    }
    //This method displays the subject name.
    public void display_playlist_name(){
        System.out.println(name);
    }
    //Playlist user interface for professor (administrator)
    public Playlist main_menu_professor(){
        int i = 0;
        input = new Scanner(System.in);
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
                upload_from_user();
            if (i == 2)
                edit();
            if (i == 3)
                remove();
            if (i == 4)
                remove_all();
            if (i == 5)
                display();
            if (i == 6)
                display_all();
            if (i == 7)
                professor_go_to_media();
            if (i < 1 || i > 8)
                System.out.println("Wrong input!");
        } while (i != 8);
        return this;
    }
    //Playlist user interface for students
    public Playlist main_menu_students(){
        int i = 0;
        input = new Scanner(System.in);
        do {
            System.out.println("What do you want to perform?");
            System.out.println("1. Display specific playlist (general or specific class)");
            System.out.println("2. Display the whole playlist");
            System.out.println("3. Go to media (take quiz, add comments and much more)");
            System.out.println("4. Quit");
            i = input.nextInt();
            input.nextLine();
            if (i == 1)
                display();
            if (i == 2)
                display_all();
            if (i == 3)
                students_go_to_media();
            if (i < 1 || i > 4)
                System.out.println("Wrong input!");
        } while (i != 4);
        return this;
    }
}
