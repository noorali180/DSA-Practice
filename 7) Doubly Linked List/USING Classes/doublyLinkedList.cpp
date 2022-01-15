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
            if(term1 == NULL) {
                cout<<"Sorry LIST is empty"<<endl;
                return NULL;
            }
            else{
                Node* temp = term1;
                for(int i = 1; i < pos; i++){
                    temp = temp->next;
                }
                 return temp;
            }
        }

        // Append a NODE...
        void appendNode(int value){
            Node* node = new Node(value);
            if(term1 == NULL) {
                term1 = term2 = node;
                term1->prev = NULL;
                term2->next = NULL;
            }
            else{
                term2->next = node;
                term2->next->prev = term2;
                term2 = node;
                term2->next = NULL;
            }
        }
        
        // Prepend a Node...
        void prependNode(int value){
            Node* node = new Node(value);
            if(term1 == NULL) {
                term1 = term2 = node;
                term1->prev = NULL;
                term2->next = NULL;
            }
            else{
                term1->prev = node;
                term1->prev->next = term1;
                term1 = node;
                term1->prev = NULL;
            }
        }

        // Insert Node at Pos.(After)...
        void insertNodeAtAfter(int pos, int value){
            if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
            else{
                Node* curr = searchNodePos(pos); 

                if(curr == term2){     // EXCEPTION (inserting after last node)
                    appendNode(value);
                } 
                else{
                    Node* node = new Node(value);
                    node->next = curr->next;
                    curr->next->prev = node;
                    curr->next = node;
                    node->prev = curr;   
                }             
                
            }
        }

        // Insert Node at Pos (Before)...
        void insertNodeBefore(int pos, int value){
            if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
            else{
                Node* curr = searchNodePos(pos);

                if(curr == term1){      // EXCEPTION (inserting before first node)
                    prependNode(value);
                }
                else{
                    Node* node = new Node(value);
                    node->prev = curr->prev;
                    curr->prev->next = node;
                    node->next = curr;
                    curr->prev = node;
                }
            }
        }

        // Delete Node from LAST...
        Node* deleteNodeFromLast(){
            if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
            else{
                Node* node = term2;

                term2 = term2->prev;
                term2->next = NULL;
            
                return node;
            }
        }

        // Delete Node from START...
        Node* deleteNodeFromStart(){
            if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
            else{
                Node* node = term1;

                term1 = term1->next;
                term1->prev = NULL;
                
                return node;
            }
        }

        // Delete Node from Postion...
        Node* deleteNodeFromPos(int pos){
            if(term1 == NULL) cout<<"Sorry LIST is empty"<<endl;
            else{
                Node* curr = searchNodePos(pos);

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
                Node* temp = term1;
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
                Node* temp = term2;
                while(temp != NULL){
                    cout<<temp->data<<" ";
                    temp = temp->prev;
                }
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
    list.insertNodeBefore(3, 10);

    list.deleteNodeFromStart();
    list.deleteNodeFromLast();

    list.deleteNodeFromPos(3);

    list.displayList();
    cout<<endl;
    list.displayListBackward();

    return 0;
}
