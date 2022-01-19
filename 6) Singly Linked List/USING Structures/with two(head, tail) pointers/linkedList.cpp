#include <iostream>

using namespace std;

struct node{
    int data;
    node* next = NULL;
};
node* head = NULL;
node* tail = NULL;

// Function Signatures...
void display();

void append(int value);
void prepend(int value);
void insertAtPos(int pos, int value);

node* deleteFromLast();
node* deleteFromStart();
node* deleteFromPos(int pos);

int searchNode(int data);



int main(){
    
    append(6);
    append(8);
    append(10);
    append(12);
    append(14);
    prepend(4);
    prepend(2);

    insertAtPos(1, 1);
    insertAtPos(9, 1);
    insertAtPos(6, 1);

    deleteFromLast();
    deleteFromStart();
    deleteFromPos(5);

    int searched = searchNode(8);

    display();

    cout<<"\nsearched node at index: "<<searched<<endl;

    return 0;
}



// Function Definitions...

// Function for appending a node...
void append(int value){
    node* n = new node;
    n->data = value;
    if(head == NULL){
        head = tail = n;
        head->next = NULL;
    }
    else{
        tail->next = n;
        tail = n;
        tail->next = NULL;
    }
}

// Funtion to insert a node at start of the LIST...
void prepend(int value){
    node* n = new node;
    n->data = value;
    if(head == NULL){
        head = tail = n;
        head->next = NULL;
    }
    else{
        n->next = head;
        head = n;
    }
}

// Function to insert a node at certain position...
void insertAtPos(int pos, int value){
    node* n = new node;
    n->data = value;

    if (head == NULL) cout<<"Sorry LIST is empty."<<endl;
    else if(pos == 1) prepend(value);
    else{
        node* temp = head;
        for(int i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        if(temp->next == NULL) append(value);
        else{
            n->next = temp->next;
            temp->next = n;
        }
    }
}

// Function to delete a node from last of list...
node* deleteFromLast(){
    if(head == NULL) cout<<"Sorry LIST is empty"<<endl;
    else{
        node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        node* n = temp->next;

        temp->next = NULL;
        tail = temp;

        return n;
    }
}

// Function to delete a node from start of list...
node* deleteFromStart(){
    if(head == NULL) cout<<"Sorry LIST is empty."<<endl;
    else{
        node* n = head;
        head = head->next;

        return n;
    }
}

// Function to delete a node from a certain pos...
node* deleteFromPos(int pos){
    if(head == NULL) cout<<"Sorry LIST is empty."<<endl;
    else if(pos == 1) return deleteFromStart();
    else{
        node* temp = head;
        for(int i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        if(temp->next->next == NULL) return deleteFromLast();
        else{
            node* n = temp->next;
            temp->next = temp->next->next;

            return n;
        }
    }
}

// Searching a Node in the linked list...
    int searchNode(int value){
    if(head == NULL) cout<<"sorry, list is empty.";
    else{
        node* temp = head;
        int i;
        for(i = 1; temp->data != value && temp->next != NULL; i++){
            temp = temp->next;
        }
        if(temp->data == value) return i;
        else return -1;
    }
}

// Function for displaying the list...
void display(){
    if (head == NULL) cout<<"LIST is empty."<<endl;
    else{
        node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}
