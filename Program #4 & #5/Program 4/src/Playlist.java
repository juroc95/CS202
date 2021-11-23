//Juhwan Lee
//CS202
//Program 4
//This is an implementation of an array of linear linked lists.
//There are four linear linked lists, each representing a different class.
//The first list is General, the second is CS162, the third is CS163, and the fourth is CS202.
//And each node has media data.

import java.io.File;
import java.util.Scanner;

public class Playlist {
    protected Node[] head;
    protected int size = 4;
    protected static Scanner input = null;
    protected Scanner x;
    //open file
    public void openFile(){
        try{
            x = new Scanner(new File("data.txt"));
        }
        catch(Exception e){
            System.out.println("Could not find file");
        }
    }
    //read file and insert in the data structure
    public void readFile(){
        String type = "";
        String name = "";
        String description = "";
        String attachments = "";
        int i = 0;
        while(x.hasNext()){
            if(i < 4){
                if(i == 0)
                    type = x.nextLine();
                if(i == 1)
                    name = x.nextLine();
                if(i == 2)
                    description = x.nextLine();
                if(i == 3)
                    attachments = x.nextLine();
                if(i == 3 && type.equals("General")){
                    General temp = new General(name, description, attachments);
                    //add temp to array of linear linked lists
                    upload_from_file(temp);
                }
                if(i == 3 && type.equals("CS162")){
                    CS162 temp = new CS162(name, description, attachments);
                    //add temp to array of linear linked lists
                    upload_from_file(temp);
                }
                if(i == 3 && type.equals("CS163")){
                    CS163 temp = new CS163(name, description, attachments);
                    //add temp to array of linear linked lists
                    upload_from_file(temp);
                }
                if(i == 3 && type.equals("CS202")){
                    CS202 temp = new CS202(name, description, attachments);
                    //add temp to array of linear linked lists
                    upload_from_file(temp);
                }
            }
            ++i;
            if(i == 4)
                i = 0;
        }
    }
    //close file
    public void closeFile(){
        x.close();
    }
    //default constructor
    public Playlist(){
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
        System.out.println("1. General");
        System.out.println("2. CS162");
        System.out.println("3. CS163");
        System.out.println("4. CS202");
        i = input.nextInt();
        input.nextLine();
        if(i == 1){
            General temp = new General();
            temp.set_media();
            this.head[0] = upload(head[0], temp);
            System.out.println("Media uploaded");
        }
        if(i == 2){
            CS162 temp = new CS162();
            temp.set_media();
            this.head[1] = upload(head[1], temp);
            System.out.println("Media uploaded");
        }
        if(i == 3){
            CS163 temp = new CS163();
            temp.set_media();
            this.head[2] = upload(head[2], temp);
            System.out.println("Media uploaded");
        }
        if(i == 4){
            CS202 temp = new CS202();
            temp.set_media();
            this.head[3] = upload(head[3], temp);
            System.out.println("Media uploaded");
        }
        if(i < 1 || i > 4)
            System.out.println("Wrong input!");
    }
    //recursive function for insertion
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
    //wrapper function for removal
    public void remove(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        input = new Scanner(System.in);
        int i = 0;
        String name = "";
        System.out.println("What type of media do you want to delete?");
        System.out.println("1. General");
        System.out.println("2. CS162");
        System.out.println("3. CS163");
        System.out.println("4. CS202");
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
    //recursive function for removal
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
    //remove all function
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
    //wrapper function for display
    public int display(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return 0;
        }
        int i = 0;
        input = new Scanner(System.in);
        System.out.println("Which playlist do you want to display?");
        System.out.println("1. General");
        System.out.println("2. CS162");
        System.out.println("3. CS163");
        System.out.println("4. CS202");
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
    //recursive function for display
    private int display(Node head){
        if(head == null)
            return 0;
        head.get_data().display();
        return display(head.get_next());
    }
    //wrapper function for display all
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
    //wrapper function for edit
    public void edit(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        int i = 0;
        String name = "";
        input = new Scanner(System.in);
        System.out.println("What type of media do you want to edit?");
        System.out.println("1. General");
        System.out.println("2. CS162");
        System.out.println("3. CS163");
        System.out.println("4. CS202");
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
    //recursive function for edit
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
    //wrapper function for students go to media
    public void students_go_to_media(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        int i = 0;
        String name = "";
        input = new Scanner(System.in);
        System.out.println("Where do you want to go?");
        System.out.println("1. General");
        System.out.println("2. CS162");
        System.out.println("3. CS163");
        System.out.println("4. CS202");
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
    //recursive function for students go to media
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
    //wrapper function for professor go to media
    public void professor_go_to_media(){
        if(head == null){
            System.out.println("The playlist has not been created");
            return;
        }
        int i = 0;
        String name = "";
        input = new Scanner(System.in);
        System.out.println("Where do you want to go?");
        System.out.println("1. General");
        System.out.println("2. CS162");
        System.out.println("3. CS163");
        System.out.println("4. CS202");
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
    //recursive function for professor go to media
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
}
