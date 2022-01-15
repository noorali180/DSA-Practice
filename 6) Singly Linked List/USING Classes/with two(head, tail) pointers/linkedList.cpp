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
                node->next = head;
                head = node;
            }
        }

        // insert at position...
        void insertNodeAt(int pos, int value){
            if(head == NULL) cout<<"LIST is empty"<<endl;
            else{ 
                Node* node = new Node(value);
                Node* temp = head;

                if(pos == 1){
                    node->next = head;
                    head = node;
                }
                else{
                    for(int i = 1; i < pos - 1; i++){
                        temp = temp->next;
                    }
                    node->next = temp->next;
                    temp->next = node;
                } 
            }
        }

        // delete node from last function...
        Node* deleteNodeFromLast(){
            if(head == NULL) cout<<"LIST is empty"<<endl;
            else{
                Node* temp = head;
                while(temp->next->next != NULL){
                    temp = temp->next;
                }
                Node* node = temp->next;
                tail = temp;
                tail->next = NULL;

                return node;
            }
        }

        // delete node from start function...
        Node* deleteNodeFromStart(){
            if(head == NULL) cout<<"LIST is empty"<<endl;
            else{
                Node* node = head;
                head = head->next;

                return node;
            }
        }

        // delete node from position function...
        Node* deleteNodeFromPos(int pos){
            if(head == NULL) cout<<"LIST is empty"<<endl;
            else{
                if(pos == 1) deleteNodeFromStart();
                else{
                    Node* temp = head;
                    for(int i = 1; i < pos - 1; i++){
                        temp = temp->next;
                    }
                    Node* node = temp->next;

                    if(temp->next->next == NULL){
                        tail = temp;
                        temp->next = NULL;
                    }else{
                        temp->next = temp->next->next;
                    }

                    return node;
                }
            }
        }

        // Searching a Node in the linked list...
        int searchNode(int value){
            if(head == NULL) cout<<"sorry, list is empty.";
            else{
                Node* temp = head;
                int i;
                for(i = 1; temp->data != value && temp->next != NULL; i++){
                    temp = temp->next;
                }
                if(temp->data == value) return i;
                else return -1;
            }
        }

        // function to display linked list...
        void displayList(){
            if(head == NULL) cout<<"List is empty."<<endl;
            else{
                Node* temp = head;
                while(temp != NULL){
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
            }
        }
};

int main(){
    LinkedList list;

    list.appendNode(5);
    list.appendNode(10);
    list.appendNode(2);
    list.appendNode(8);
    list.prependNode(55);
    list.prependNode(56);

    list.insertNodeAt(3, 54);
    list.insertNodeAt(1, 57);
    list.insertNodeAt(8, 3);

    Node* dl = list.deleteNodeFromLast();
    Node* ds = list.deleteNodeFromStart();
    Node* dp1 = list.deleteNodeFromPos(1);
    Node* dpe = list.deleteNodeFromPos(6);

    int s = list.searchNode(2);
    cout<<s<<endl;

    list.displayList();


    return 0;
}
