//Juhwan Lee
//CS202
//Program 4
//This is an implementation of media class.
//It is abstract base class because we do not create media reference.
//And there are four pure virtual functions.

import java.util.*;

public abstract class Media {
    protected String name;
    protected String comments;
    protected String attachments;
    protected String description;
    protected int views;
    protected static Scanner input = null;
    //default constructor
    public Media(){
        this.name = null;
        this.comments = null;
        this.attachments = null;
        this.description = null;
        this.views = 0;
    }
    //constructor with arguments
    public Media(String name, String description, String attachments){
        this.name = name;
        this.description = description;
        this.attachments = attachments;
        this.comments = null;
        this.views = 0;
    }
    //copy constructor
    public Media(Media ref){
        this.name = ref.name;
        this.comments = ref.comments;
        this.attachments = ref.attachments;
        this.description = ref.description;
        this.views = ref.views;
    }
    //pure virtual function for media type
    public abstract int media_type();
    //pure virtual function for take quiz
    public abstract int take_quiz();
    //pure virtual function for set quiz
    public abstract int set_quiz();
    //pure virtual function for remove quiz
    public abstract int remove_quiz();
    //set media function
    public int set_media(){
        input = new Scanner(System.in);
        System.out.print("Please enter video title: ");
        this.name = input.nextLine();
        System.out.print("Please enter description: ");
        this.description = input.nextLine();
        System.out.print("Please enter attachments: ");
        this.attachments = input.nextLine();
        return 1;
    }
    //edit media function
    public int edit_media(){
        input = new Scanner(System.in);
        int i = 0;
        do {
            System.out.println("What do you want to edit?");
            System.out.println("1. Video Title");
            System.out.println("2. Description");
            System.out.println("3. Attachments");
            System.out.println("4. Quit");
            i = input.nextInt();
            input.nextLine();
            if (i == 1) {
                System.out.print("Please enter new video title: ");
                this.name = input.nextLine();
            }
            if (i == 2) {
                System.out.print("Please enter new description: ");
                this.description = input.nextLine();
            }
            if (i == 3) {
                System.out.print("Please enter new attachments: ");
                this.attachments = input.nextLine();
            }
            if (i < 1 || i > 4)
                System.out.println("Wrong input!");
        } while(i != 4);
        return 1;
    }
    //display function
    public int display(){
        System.out.println("Video Title: " + name);
        System.out.println("Description: " + description);
        System.out.println("Attachments: " + attachments);
        System.out.println("Views: " + views);
        if(this.comments == null)
            System.out.println("Comments: No comments");
        else
            System.out.println("Comments: " + comments);
        return 1;
    }
    //set comments function
    public int set_comments(){
        input = new Scanner(System.in);
        System.out.print("Enter your comments: ");
        this.comments = input.nextLine();
        return 1;
    }
    //remove comments function
    public int remove_comments(){
        if(comments == null){
            System.out.println("There is no comments to delete");
            return 0;
        }
        this.comments = null;
        System.out.println("The comment is deleted");
        return 1;
    }
    //count views
    public int count_views(){
        this.views += 1;
        return 1;
    }
    //compare name function
    public int compare_name(String name){
        if(this.name.equals(name))
            return 1;
        else
            return 0;
    }
}
