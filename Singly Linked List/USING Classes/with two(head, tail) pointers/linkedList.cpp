#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(){
            data = 0;
            next = NULL;
        }

        Node(int d){
            data = d;
            next = NULL;
        }
};

class LinkedList
{
    public:
        Node* head;
        Node* tail;

        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        // append function ...
        void appendNode(int value){
            Node *node = new Node(value);
            if (head == NULL){
                head = node;
                tail = node;
                head->next = NULL;
            }
            else{
                tail->next = node;
                tail = node;
                tail->next = NULL;
            }
        }

        // prepend function...
        void prependNode(int value){
            Node* node = new Node(value);
            if(head == NULL){
                head = node;
                tail = node;
                head->next = NULL;
            }
            else{
                
            }
        }

        // function to display linked list...
        void displayList(){
            Node* temp = head;
            while(temp->next != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data<<" ";
        }
};

int main(){
    LinkedList list;

    list.appendNode(5);
    list.appendNode(10);
    list.appendNode(2);
    list.appendNode(8);

    list.displayList();


    return 0;
}
