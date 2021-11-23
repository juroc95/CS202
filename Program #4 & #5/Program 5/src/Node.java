//Juhwan Lee
//CS202
//Program 5
//This is an implementation of node class for an array of linear linked lists.
//This node class has media data and next pointer.
//This node class has a "Has a" relationship with the media class and uses setters and getters.

public class Node {
    protected Media data;
    protected Node next;
    //default constructor
    public Node(){
        this.data = null;
        this.next = null;
    }
    //setter (data)
    public void set_data(Media data){
        this.data = data;
    }
    //setter (next)
    public void set_next(Node next){
        this.next = next;
    }
    //getter (data)
    public Media get_data(){
        return data;
    }
    //getter (next)
    public Node get_next(){
        return next;
    }
}
