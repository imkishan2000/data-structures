import java.util.Scanner;


class Stack
{
    int top,item;
    int stack[]=new int[5];
    Stack()
    {
        top=-1;
    }
    void push(Scanner sc)
    {
        if(top==4)
        {
            System.out.println("StackOverFlow...");
        }
        else
        {
            System.out.println("Enter the element to be popped:");
            item=sc.nextInt();
            top++;    
            stack[top]=item;
        }
    
    }

    void pop()
    {
        if(top<0)
        {
            System.out.println("StackUnderFlow....");
        }
        else
        {
            System.out.println("popped element is:"+stack[top]);
            top--;
        }
    }
    void display()
    {
        if(top<0)
        {
            System.out.println("Stack is empty....");
        }
        else
        {
            System.out.println("printing stack.....");
            for(int i=top; i>=0; i--)
            {
                System.out.println(stack[i]);
            }
        }
    }
}


public class JavaStack {  
public static void main(String[] args) {  
    int choice=0;  
    Scanner sc = new Scanner(System.in);  
    Stack s = new Stack();  
    System.out.println("*********Stack operations using array*********\n");  
    System.out.println("\n------------------------------------------------\n");  
    while(choice != 4)  
    {  
        System.out.println("\nChose one from the below options...\n");  
        System.out.println("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        System.out.println("\n Enter your choice \n");        
        choice = sc.nextInt();  
        switch(choice)  
        {  
            case 1:  
            {   
                s.push(sc);  
                break;  
            }  
            case 2:  
            {  
                s.pop();  
                break;  
            }  
            case 3:  
            {  
                s.display();  
                break;  
            }  
            case 4:   
            {  
                System.out.println("Exiting....");  
                System.exit(0);  
                break;   
            }  
            default:  
            {  
                System.out.println("Please Enter valid choice ");  
            }   
        };  
    }  
}  
}  