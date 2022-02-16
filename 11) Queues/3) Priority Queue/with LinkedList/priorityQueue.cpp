#include <iostream>

using namespace std;

class Node{
    public:

    int data;
    int priority;
    Node* next;

    Node(int d, int p){
        data = d;
        priority = p;
        next = NULL;
    }

    Node(){
        next = NULL;
    }
};

class PriorityQueue{
    public:
    Node* front;

    PriorityQueue(){
        front = NULL;
    }

    // Function to enqueue an element into the queue...
    void enqueue(int d, int p){
        Node* newNode = new Node(d, p);
        if(front == NULL){
            front = newNode;
            front->next = NULL;
        }
        else{
            Node* temp = front;
            while(temp->next != NULL && temp->next->priority <= p){
                temp = temp->next;
            }

            if(temp->next == NULL){
                temp->next = newNode;
                newNode->next = NULL;
            }
            else{
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    // Function to dequeue an element from queue...
    Node* dequeue(){
        if(front == NULL) cout<<"Sorry queue is empty."<<endl;
        else{
            Node* temp = front;
            front = front->next;

            return temp;
        }
    }

    // Function to peek into the queue...
    Node* peek(){
        if(front == NULL) cout<<"Sorry queue is empty."<<endl;
        else{
            return front;
        }
    }

    // Function to display elements present in the queue...
    void display(){
        if(front == NULL) cout<<"Sorry queue is empty."<<endl;
        else{
            Node* temp = front;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
    }
};

// Main (DRIVER) Function...
int main(){
    PriorityQueue list;

    list.enqueue(2, 1);
    list.enqueue(3, 2);
    list.enqueue(5, 6);
    list.enqueue(6, 5);
    list.enqueue(4, 3);
    list.enqueue(10, 1);
    list.enqueue(11, 2);

    list.dequeue();
    list.dequeue();
    list.dequeue();

    cout<<list.peek()->data<<endl;

    list.display();

    return 0;
}
