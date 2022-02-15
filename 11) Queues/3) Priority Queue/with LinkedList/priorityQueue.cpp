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

    void enqueue(int d, int p){
        Node* newNode = new Node(d, p);
        if(front == NULL){
            front = newNode;
            front->next = NULL;
        }
        else{
            Node* temp = front;
            while(temp->next != NULL && temp->priority <= p){
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

    Node* dequeue(){
        if(front == NULL) cout<<"Sorry queue is empty."<<endl;
        else{
            Node* temp = front;
            front = front->next;

            return temp;
        }
    }

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


int main(){
    PriorityQueue list;

    list.enqueue(2, 1);
    list.enqueue(3, 2);
    list.enqueue(5, 4);
    list.enqueue(6, 5);
    list.enqueue(4, 3);

    list.display();

    return 0;
}
