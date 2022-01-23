#include <iostream>

using namespace std;

struct node{
    int data;
    node* next = NULL;
};
node* front = NULL;
node* rear = NULL;

// function to check if Queue is empty...
bool isEmpty(){
    if(front == NULL && rear == NULL) return true;
    else return false;
}

// function to insert element (enqueue) in the queue... (always to last).
void enqueue(int value){
    node* n = new node;
    n->data = value;

    if(front == NULL){
        front = rear = n;
        n->next = NULL;
    }
    else{
        rear->next = n;
        rear = n;
        rear->next = NULL;
    }
}

// function to delete element (dequeue) from the queue... (always from front).
node* dequeue(){
    if(isEmpty()) cout<<"Sorry, Queue is empty.."<<endl;
    else{
        node* n = front;
        front = front->next;

    return n;
    }
}

// function to look the first element in the queue...
node* lookFront(){
    if(isEmpty()) cout<<"Sorry, Queue is empty.."<<endl;
    else return front;
}

// function to display the queue...
void display(){
    if(isEmpty()) cout<<"Sorry, Queue is empty.."<<endl;
    else{
        node* temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

// main function (DRIVER)...
int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);

    dequeue();
    dequeue();

    display();

    cout<<endl;

    node* firstNode = lookFront();
    cout<<firstNode->data<<endl;

    return 0;
}
