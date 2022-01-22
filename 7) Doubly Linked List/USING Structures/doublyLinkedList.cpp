#include<iostream>

using namespace std;

struct node{
    int data;
    node* next = NULL;
    node* prev = NULL;
};
node* term1 = NULL;
node* term2 = NULL;

// FUNCTION SIGNATURES...
node* searchNodePos(int pos);

void appendNode(int value);
void prependNode(int value);
void insertNodeAfter(int pos, int value);
void insertNodeBefore(int pos, int value);

node* deleteNodeFromLast();
node* deleteNodeFromStart();
node* deleteNodeFromPos(int pos);

void displayList();
void displayListBackward();

int main(){

    appendNode(4);
    appendNode(8);
    appendNode(12);
    appendNode(16);
    appendNode(20);

    prependNode(2);

    insertNodeAfter(6, 1);
    insertNodeBefore(1, 9);

    node* deletednode = deleteNodeFromPos(4);
    cout<<"deleted Node = "<<deletednode->data<<endl;

    displayList();
    cout<<endl;
    displayListBackward();

    return 0;
}


// FUNCTION DEFINATIONS...

// Search a Node...
    node* searchNodePos(int pos){
        if(term1 == NULL) {
            cout<<"Sorry LIST is empty"<<endl;
            return NULL;
        }
        else{
            node* temp = term1;
            for(int i = 1; i < pos; i++){
                temp = temp->next;
            }
            return temp;
            }
        }

// Function to append a node in a list.
void appendNode(int value){
    node* n = new node;
    n->data = value;
    if(term1 == NULL){
        term1 = term2 = n;
        term1->next = NULL;
        term1->prev = NULL;
    }
    else{
        term2->next = n;
        term2->next->prev = term2;
        term2 = n;
        term2->next = NULL;
    }
}

// Function to prepend a node in a list.
void prependNode(int value){
    node* n = new node;
    n->data = value;
    if(term1 == NULL){
        term1 = term2 = n;
        term1->next = term1->prev = NULL;
    }
    else{
        term1->prev = n;
        term1->prev->next = term1;
        term1 = n;
        term1->prev = NULL;
    }
}

// Insert Node at Pos.(After)...
void insertNodeAfter(int pos, int value){
    if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
    else{
        node* curr = searchNodePos(pos); 

        if(curr == term2){     // EXCEPTION (inserting after last node)
            appendNode(value);
        } 
        else{
            node* n = new node;
            n->data = value;

            n->next = curr->next;
            curr->next->prev = n;
            curr->next = n;
            curr->next->prev = curr;   
        }             
                
    }
}

// Insert Node at Pos (Before)...
void insertNodeBefore(int pos, int value){
    if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
    else{
        node* curr = searchNodePos(pos);

        if(curr == term1){      // EXCEPTION (inserting before first node)
            prependNode(value);
        }
        else{
            node* n = new node;
            n->data = value;

            n->prev = curr->prev;
            curr->prev->next = n;
            curr->prev = n;
            curr->prev->next = curr;
        }
    }
}

// Delete Node from LAST...
node* deleteNodeFromLast(){
    if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
    else{
        node* n = term2;

        term2 = term2->prev;
        term2->next = NULL;
            
        return n;
    }
}

// Delete Node from START...
node* deleteNodeFromStart(){
    if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
    else{
        node* n = term1;

        term1 = term1->next;
        term1->prev = NULL;
                
        return n;
    }
}

// Delete Node from Postion...
node* deleteNodeFromPos(int pos){
    if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
    else{
        node* curr = searchNodePos(pos);

        if(curr == term1) return deleteNodeFromStart();
        else if(curr == term2) return deleteNodeFromLast();
        else{
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            return curr;
        }
    }
}
        
// Displaying List...
void displayList(){
    if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
    else{
        node* temp = term1;
        while(temp->next != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<" ";
    }
}

// Displaying List in Backward Direction...
void displayListBackward(){
    if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
    else{
        node* temp = term2;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
    }
}
