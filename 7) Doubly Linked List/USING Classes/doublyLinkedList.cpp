#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(){
            data = 0;
        }

        Node(int d){
            data = d;
        }
};

class DoublyLinkedList
{
    public:
        Node* term1;
        Node* term2;

        DoublyLinkedList(){
            term1 = term2 = NULL;
        }

        // Search a Node...
        Node* searchNodePos(int pos){
            if(term1 == NULL && term2 == NULL) cout<<"Sorry LIST is empty"<<endl;
            else{
                Node* temp = term1;
                for(int i = 0; i < pos; i++){
                    temp = temp->next;
                }

                if (temp != NULL) return temp;
                else return NULL;
            }
        }

        // Append a NODE...
        void appendNode(int value){
            Node* node = new Node(value);
            if(term1 == NULL) term1 = term2 = node;
            else{
                term2->next = node;
                node->prev = term2;
                node->next = NULL;
                term2 = node;
            }
        }
        
        // Prepend a Node...
        void prependNode(int value){
            Node* node = new Node(value);
            if(term1 == NULL) term1 = term2 = node;
            else{
                term1->prev = node;
                node->next = term1;
                node->prev = NULL;
                term1 = node;
            }
        }

        // Insert Node at Pos...
        void insertNodeAtAfter(int pos, int value){
            if(term1 == NULL && term2 == NULL) cout<<"Sorry LIST is empty"<<endl;
            else{
                Node* curr = searchNodePos(pos);
                if(curr != NULL){
                    Node* node = new Node(value);
                    node->next = curr->next;
                    curr->next->prev = node;
                    curr->next = node;
                    node->prev = curr;
                }
                else cout<<"Position not found in the list."<<endl;
            }


        }

        // Displaying List...
        void displayList(){
            if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
            else{
                Node* temp = term1;
                while(temp->next != NULL){
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
                cout<<temp->data<<" ";
            }
        }
};

int main(){
    DoublyLinkedList list;

    list.appendNode(25);
    list.appendNode(30);
    list.prependNode(2);
    list.prependNode(1);

    list.insertNodeAtAfter(3, 5);

    list.displayList();

    return 0;
}
