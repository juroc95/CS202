//Juhwan Lee
//CS202
//Program 5
//This is an implementation of node class for AVL tree.
//This node class has playlist data and left, right pointers, and height.
//This node class has a "Has a" relationship with playlist class and uses setters and getters.

public class Node2 {
    protected Playlist data;
    protected Node2 left;
    protected Node2 right;
    protected int height;
    //default constructor
    public Node2(){
        this.data = null;
        this.left = null;
        this.right = null;
        this.height = 0;
    }
    //copy constructor
    public Node2(Playlist data){
        this.data = data;
    }
    //setter (data)
    public void set_data(Playlist data){
        this.data = data;
    }
    //setter (left)
    public void set_left(Node2 left){
        this.left = left;
    }
    //setter (right)
    public void set_right(Node2 right){
        this.right = right;
    }
    //setter (height)
    public void set_height(int height){
        this.height = height;
    }
    //getter (data)
    public Playlist get_data(){
        return data;
    }
    //getter (left)
    public Node2 get_left(){
        return left;
    }
    //getter (right)
    public Node2 get_right(){
        return right;
    }
    //getter (height)
    public int get_height(){
        return height;
    }
}
