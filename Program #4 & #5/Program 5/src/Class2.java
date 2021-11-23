//Juhwan Lee
//CS202
//Program 5
//This is an implementation of Class 2 class.
//Class 2 class is derived from media class.
//This media type represents one class type in the array of linear linked lists.

import java.util.*;

public class Class2 extends Media {
    protected String type;
    protected String quiz;
    protected String answer;
    protected String student_answer;
    protected static Scanner input = null;
    //default constructor
    public Class2(){
        this.type = null;
        this.quiz = null;
        this.answer = null;
        this.student_answer = null;
    }
    //constructor with arguments
    public Class2(String class_name, String name, String description, String attachments){
        super(name, description, attachments);
        this.type = class_name;
        this.quiz = null;
        this.answer = null;
        this.student_answer = null;
    }
    //copy constructor
    public Class2(Class2 ref){
        super(ref);
        this.type = ref.type;
        this.quiz = ref.quiz;
        this.answer = ref.answer;
        this.student_answer = ref.student_answer;
    }
    //media type method
    public int media_type(){
        return 2;
    }
    //set media method
    public int set_media(){
        input = new Scanner(System.in);
        System.out.print("Please enter class name: ");
        this.type = input.nextLine();
        super.set_media();
        return 1;
    }
    //set quiz method
    public int set_quiz(){
        input = new Scanner(System.in);
        System.out.print("Please enter quiz question: ");
        this.quiz = input.nextLine();
        System.out.print("Please enter answer: ");
        this.answer = input.nextLine();
        System.out.println("Quiz is added");
        return 1;
    }
    //remove quiz method
    public int remove_quiz(){
        if(quiz == null || answer == null){
            System.out.println("There is no quiz to delete");
            return 0;
        }
        this.quiz = null;
        this.answer = null;
        this.student_answer = null;
        System.out.println("The quiz is deleted");
        return 1;
    }
    //display method
    public int display(){
        super.display();
        if(quiz != null)
            System.out.println("Quiz question: " + quiz);
        return 1;
    }
    //take quiz method
    public int take_quiz(){
        if(quiz == null || answer == null){
            System.out.println("There is no quiz in this media");
            return 0;
        }
        input = new Scanner(System.in);
        System.out.println("Quiz question: " + quiz);
        System.out.print("Enter your answer: ");
        this.student_answer = input.nextLine();
        if(this.answer.equals(student_answer)){
            System.out.println("Correct!");
            return 1;
        }
        else{
            System.out.println("Wrong!");
            return 0;
        }
    }
    //display class name method
    public void display_class_name(){
        System.out.println(type);
    }
}
