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
        
        LinkedList(){
            head = NULL;
        }

        // Insert Element at LAST of the linked list...
        void insertNodeAtLast(int value){
            Node* node = new Node(value);
            if(head == NULL) {
                head = node;
            }
            else{
                Node* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = node;
            }
        }

        // Insert Node at BEGINING of the linked list...
        void insertNodeAtStart(int value){
            Node* node = new Node(value);
            if(head == NULL){
                head = node;
            }
            else{
                node->next = head;
                head = node;
            }
        }

        // Insert Node at CERTAIN POSITION of the linked list...
        void insertNodeAtPos(int pos, int value){
            Node* node = new Node(value);

            if(head == NULL) return;
            if(pos == 1) {
                node->next = head;
                head = node;
            }
            else{
                Node* temp = head;
                for(int i = 1; i < pos - 1; i++){
                    temp = temp->next;
                }
                if(temp->next == NULL){
                    temp->next = node;
                    node->next = NULL;
                }
                else{
                    node->next = temp->next;
                    temp->next = node;
                }
            }
        }

        // Delete a Node from LAST of the linked list...
        Node* deleteNodeFromLast(){
            if(head == NULL) cout<<"sorry, list is empty.";
            else{
                Node* temp = head;
                while(temp->next->next != NULL){
                    temp = temp->next;
                }
                Node* node = temp;
                temp->next = NULL;

                return node;
            }
        }

        // Delete a Node from START of the linked list...
        Node* deleteNodeFromStart(){
            if(head == NULL) cout<<"sorry, list is empty.";
            else{
                Node* node = head;
                head = head->next;

                return node;
            }
        }

        // Delete a Node from CERTAIN POSITION of the linked list...
        Node* deleteNodeFromPos(int pos){
            if(head == NULL) cout<<"sorry, list is empty.";
            else if(pos == 1){
                Node* node = head;
                head = head->next;

                return node;
            }
            else{
                Node* temp = head;
                for(int i = 1; i < pos - 1; i++){
                    temp = temp->next;
                }
 
                Node* node = temp;
                temp->next = temp->next->next;

                return node;
            }
        }

        // Searching a Node in the linked list...
        int searchNode(int data){
            if(head == NULL) cout<<"sorry, list is empty.";
            else{
                Node* temp = head;
                int i = 0;
                for(i = 1; temp->data != data && temp->next != NULL; i++){
                    temp = temp->next;
                }
                if(temp->data == data) return i;
                else return -1;
            }
        }

        // Function for displaying LINKED LIST...
        void displayList(){
            if(head == NULL) cout<<"List is empty."<<endl;
            else{
                Node* temp = head;
                while(temp->next != NULL){
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
                cout<<temp->data<<endl;
            }
        }
};

int main(){
    LinkedList list;

    cout<<endl;
    cout<<"Trying to display an empty list: "<<endl;
    list.displayList();
    cout<<endl;

    list.insertNodeAtLast(5);
    list.insertNodeAtLast(10);
    list.insertNodeAtLast(15);
    list.insertNodeAtLast(20);
    list.insertNodeAtLast(25);
    list.insertNodeAtLast(30);

    cout<<"Displaying the list: "<<endl;
    cout<<"LIST = ";
    list.displayList();
    cout<<endl;

    cout<<"Inserting an element at the first of the list:"<<endl;
    list.insertNodeAtStart(2);
    cout<<"LIST = ";
    list.displayList();
    cout<<endl;

    cout<<"Inserting an element at the last of the list:"<<endl;
    list.insertNodeAtLast(4);
    cout<<"LIST = ";
    list.displayList();
    cout<<endl;

    cout<<"Deleting the element from 3rd position:"<<endl;
    list.deleteNodeFromPos(3);
    cout<<"LIST = ";
    list.displayList();
    cout<<endl;

    cout<<"Searching an element (25):"<<endl;
    cout<<"LIST: ";
    list.displayList();
    int elementIndex = list.searchNode(25);
    if(elementIndex != -1) cout<<"searched element found at index "<<elementIndex<<endl;
    else cout<<"searched element is not found.";
    cout<<endl;

    cout<<"Searching an element (40):"<<endl;
    cout<<"LIST: ";
    list.displayList();
    int elementIndex2 = list.searchNode(40);
    if(elementIndex2 != -1) cout<<"searched element found at index "<<elementIndex2<<endl;
    else cout<<"searched element is not found.";
    cout<<endl;
    cout<<endl;

    return 0;
}
