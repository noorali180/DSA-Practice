#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;

    Node(){
        next = NULL;
    }

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Queue{
    public:

    Node* front = NULL;
    Node* rear = NULL;

    bool isEmpty(){
        if(front == NULL && rear == NULL) return true;
        else return false;
    }

    // function to insert element (enqueue) in the queue... (always to last).
    void enqueue(int value){
        Node* node = new Node(value);

        if(front == NULL){
            front = rear = node;
            node->next = NULL;
        }
        else{
            rear->next = node;
            rear = node;
            rear->next = NULL;
        }
    }

    // function to delete element (dequeue) from the queue... (always from front).
    Node* dequeue(){
        if(isEmpty()) cout<<"Sorry, Queue is empty.."<<endl;
        else{
            Node* node = front;
            front = front->next;

            return node;
        }
    }

    // function to look the first element in the queue...
    Node* lookFront(){
        if(isEmpty()) cout<<"Sorry, Queue is empty.."<<endl;
        else return front;
    }

    // function to display the queue...
    void display(){
        if(isEmpty()) cout<<"Sorry, Queue is empty.."<<endl;
        else{
            Node* temp = front;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
    }
};

// MAIN FUNCTION (DRIVER)...
int main(){
    Queue list;

    list.enqueue(1);
    list.enqueue(2);
    list.enqueue(3);
    list.enqueue(4);
    list.enqueue(5);
    list.enqueue(6);
    list.enqueue(7);
    list.enqueue(8);
    list.enqueue(9);
    list.enqueue(10);

    list.dequeue();
    list.dequeue();

    list.display();

    cout<<endl;

    Node* firstNode = list.lookFront();
    cout<<firstNode->data<<endl;

    return 0;
}
