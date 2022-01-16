#include <iostream>

using namespace std;

struct node{
    int data;
    node* next = NULL;
};
node* top = NULL;

// FUNCTION TO CHECK IF STACK IS EMPTY...
void isEmpty(){
    if(top == NULL) cout<<"STACK is empty."<<endl;
    else cout<<"STACK is not empty."<<endl;
}

// FUNCTION TO PUSH NODES INTO THE STACK...
void push(int value){
    node* temp = new node;
    temp->data = value;
    if(top == NULL) {
        top = temp;
        top->next = NULL;
    }
    else{
        temp->next = top;
        top = temp;
    }
}

// FUNCTION TO POP NODES FROM THE STACK...
node* pop(){
    if(top == NULL) cout<<"Stack is empty."<<endl;
    else{
        top = top->next;
    }
}

// FUNCTION TO PEEK TOP MOST VALUE OF STACK...
int peek(){
    return top->data;
}

// FUNCTION TO DISPLAY STACK...
void display(){
    if(top == NULL) cout<<"Stack is empty."<<endl;
    else{
        cout<<"TOP to BOTTOM: "<<endl;
        node* temp = top;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

int main() {
    isEmpty();
    cout<<endl;

    push(5);
    push(10);
    push(15);
    push(20);

    display();

    cout<<endl;
    cout<<endl;

    pop();
    display();

    cout<<endl;
    cout<<endl;
    isEmpty();

    return 0;
}
