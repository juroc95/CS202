//Juhwan Lee
//CS202
//Program 5
//This file is the canvas class implementation.
//It is an AVL tree data structure, and initial data is entered from an external file.
//Since I did not implement the balanced tree in the 3rd program,
//I implemented the balanced tree in this program.

import java.util.*;

public class Canvas {
    protected Node2 root;
    protected static Scanner input = null;
    //default constructor
    public Canvas(){
        this.root = null;
    }
    //Inserting initial data from external data files
    public void upload_from_file(){
        Playlist temp1 = new Playlist(1);
        Playlist temp2 = new Playlist(2);
        Playlist temp3 = new Playlist(3);
        Playlist temp4 = new Playlist(4);
        temp1.openFile(1);
        temp1.readFile();
        temp1.closeFile();
        temp2.openFile(2);
        temp2.readFile();
        temp2.closeFile();
        temp3.openFile(3);
        temp3.readFile();
        temp3.closeFile();
        temp4.openFile(4);
        temp4.readFile();
        temp4.closeFile();
        insert(temp1);
        insert(temp2);
        insert(temp3);
        insert(temp4);
    }
    //Inserting data from the user
    public void upload_from_user(){
        Playlist temp = new Playlist(0);
        insert(temp);
    }
    //It is a method that returns the height of a specific node in the AVL tree
    protected int height(Node2 node){
        if(node == null)
            return -1;
        return node.get_height();
    }
    //Right rotation
    protected Node2 right_rotation(Node2 parentnode){
        //Left child node becomes new parent node
        Node2 newparentnode = parentnode.get_left();
        //Left child node's right child node (null node)
        Node2 nullnode = newparentnode.get_right();
        //Set the existing parent node to the right child node of the new parent node
        newparentnode.set_right(parentnode);
        //Set the left child node of the existing parent node as a null node
        parentnode.set_left(nullnode);
        //Update height of rotated nodes
        parentnode.set_height(Math.max(height(parentnode.get_left()), height(parentnode.get_right())) + 1);
        newparentnode.set_height(Math.max(height(newparentnode.get_left()), height(newparentnode.get_right())) + 1);
        //Return new parent node
        return newparentnode;
    }
    //Left rotation
    protected Node2 left_rotation(Node2 parentnode){
        //Right child node becomes new parent node
        Node2 newparentnode = parentnode.get_right();
        //Right child node's left child node (null node)
        Node2 nullnode = newparentnode.get_left();
        //Set the existing parent node to the left child node of the new parent node
        newparentnode.set_left(parentnode);
        //Set the left child node of the existing parent node as a null node
        parentnode.set_right(nullnode);
        //Update height of rotated nodes
        parentnode.set_height(Math.max(height(parentnode.get_left()), height(parentnode.get_right())) + 1);
        newparentnode.set_height(Math.max(height(newparentnode.get_left()), height(newparentnode.get_right())) + 1);
        //Return new parent node
        return newparentnode;
    }
    //Insertion method (wrapper)
    public void insert(Playlist data){
        root = insert(root, data);
    }
    //Insertion method (recursive)
    protected Node2 insert(Node2 node, Playlist data){
        if(node == null){
            return new Node2(data);
        }
        if(data.compare(node.get_data()) < 0)
            node.set_left(insert(node.get_left(), data));
        else
            node.set_right(insert(node.get_right(), data));
        //set new height
        node.set_height(Math.max(height(node.get_left()), height(node.get_right())) + 1);
        //check if balance (if not balance, rotation)
        node = settle_violation(data, node);
        return node;
    }
    //Perform rotation (when inserted)
    protected Node2 settle_violation(Playlist data, Node2 node){
        //Determine if the tree is unbalanced
        int balance = get_balance(node);
        //Left-Left
        if(node.get_left() != null && balance > 1 && data.compare(node.get_left().get_data()) < 0)
            return right_rotation(node);
        //Right-Right
        if(node.get_right() != null && balance < -1 && data.compare(node.get_right().get_data()) > 0)
            return left_rotation(node);
        //Left-Right
        if(node.get_left() != null && balance > 1 && data.compare(node.get_left().get_data()) > 0) {
            node.set_left(left_rotation(node.get_left()));
            return right_rotation(node);
        }
        //Right-Left
        if(node.get_right() != null && balance < -1 && data.compare(node.get_right().get_data()) < 0) {
            node.set_right(right_rotation(node.get_right()));
            return left_rotation(node);
        }
        return node;
    }
    //Determine whether the tree is balanced/unbalanced
    protected int get_balance(Node2 node){
        if(node == null)
            return 0;
        return height(node.get_left()) - height(node.get_right());
    }
    //display all subjects (wrapper)
    public void display_all(){
        if(root == null){
            System.out.println("Canvas is empty!");
            return;
        }
        display_all(root);
    }
    //display all subjects (recursive)
    protected void display_all(Node2 node){
        if(node.get_left() != null){
            display_all(node.get_left());
        }
        System.out.print("Subject: ");
        node.get_data().display_playlist_name();
        //Test
        //System.out.print("Height: ");
        //System.out.println(node.height);
        if(node.get_right() != null){
            display_all(node.get_right());
        }
    }
    //remove all subjects
    public void remove_all(){
        this.root = null;
        System.out.println("All subjects are removed");
    }
    //This method allows the professor (administrator) to navigate to a specific subject and perform various functions.
    public void move_to_subject_professor(){
        String subject = "";
        input = new Scanner(System.in);
        display_all();
        System.out.print("Please enter the subject name you want to go: ");
        subject = input.nextLine();
        root = move_to_subject_professor(root, subject);
    }
    //Recursive method for professor move to specific subject method
    protected Node2 move_to_subject_professor(Node2 node, String subject){
        if(node == null) {
            System.out.println("There was no match!");
            return null;
        }
        if(node.get_data().compare_string(subject) < 0)
            node.set_right(move_to_subject_professor(node.get_right(), subject));
        if(node.get_data().compare_string(subject) > 0)
            node.set_left(move_to_subject_professor(node.get_left(), subject));
        if(node.get_data().compare_string(subject) == 0) {
            node.get_data().main_menu_professor();
            return node;
        }
        return node;
    }
    //This method allows the students to navigate to a specific subject and perform various functions.
    public void move_to_subject_students(){
        String subject = "";
        input = new Scanner(System.in);
        display_all();
        System.out.print("Please enter the subject name you want to go: ");
        subject = input.nextLine();
        root = move_to_subject_students(root, subject);
    }
    //Recursive method for students move to specific subject method
    protected Node2 move_to_subject_students(Node2 node, String subject){
        if(node == null) {
            System.out.println("There was no match!");
            return null;
        }
        if(node.get_data().compare_string(subject) < 0)
            node.set_right(move_to_subject_students(node.get_right(), subject));
        if(node.get_data().compare_string(subject) > 0)
            node.set_left(move_to_subject_students(node.get_left(), subject));
        if(node.get_data().compare_string(subject) == 0){
            node.get_data().main_menu_students();
            return node;
        }
        return node;
    }
}
