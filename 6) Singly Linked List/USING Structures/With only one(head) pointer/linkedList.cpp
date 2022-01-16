// LINKED LIST USING STRUCTURES, (HEAD) POINTER...

#include <iostream>

using namespace std;

struct node{
    int data;
    node* next = NULL;
};
node* head = NULL;

// Function Signatures...
void display();

void append(int value);
void prepend(int value);
void insertAtPos(int pos, int value);

node* deleteFromLast();
node* deleteFromStart();
node* deleteFromPos(int pos);

int main(){

    append(25);
    append(30);
    append(35);
    prepend(20);
    prepend(10);

    insertAtPos(3, 2);
    insertAtPos(1, 0);
    insertAtPos(8, 0);

    deleteFromLast();
    deleteFromStart();
    deleteFromPos(3);

    display();


    return 0;
}

// Function Declarations...

// function to display linked list.
void display(){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// function to append a node.
void append(int value){
    node* n = new node;
    n->data = value;
    if(head == NULL){
        head = n;
        head->next = NULL;
    }
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
        n->next = NULL;
    }
}

// function to prepend a node.
void prepend(int value){
    node* n = new node;
    n->data = value;
    if(head == NULL){
        head = n;
        head->next = NULL;
    }
    else{
        n->next = head;
        head = n;
    }
}

// function to insert a node at certain position.
void insertAtPos(int pos, int value){
    node* n = new node;
    n->data = value;

    if(pos == 1) prepend(value);
    else{
        node* temp = head;
        for(int i=1; i < pos - 1; i++){
            temp = temp->next;
        }
        if(temp->next == NULL) append(value);
        else{
            n->next = temp->next;
            temp->next = n;
        }
    }
}

// function to delete a node from last.
node* deleteFromLast(){
    if(head == NULL) cout<<"LIST is empty."<<endl;
    else{
        node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        node* n = temp->next;
        temp->next = NULL;

        return n;
    }
}

// function to delete a node from start.
node* deleteFromStart(){
    if(head == NULL) cout<<"LIST is empty."<<endl;
    else{
        node* n = head;
        head = head->next;

        return n;
    }
}

// function to delete a node from a certain position.
node* deleteFromPos(int pos){
    if(head == NULL) cout<<"LIST is empty."<<endl;
    else if(pos == 1) {
        node* n = deleteFromStart();
        return n;
    }
    else{
        node* temp = head;
        for(int i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        if(temp->next == NULL) {
            node* n = deleteFromLast();
            return n;
        }
        else{
            node* n = temp->next;
            temp->next = temp->next->next;

            return n;
        }
    }
}
