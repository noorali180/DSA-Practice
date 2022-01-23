#include <iostream>

using namespace std;

#define N 10

class CircularQueue{
    public:
        int Q[N];
        int front;
        int rear;

    // Default Constructor...
        CircularQueue(){
            front = rear = -1;
        }

    public:
    // Function to check whether queue is full...
        bool isFull(){
            if((rear + 1) % N == front) return true;
            else return false;
        }

    // Function to check whether queue is empty...
        bool isEmpty(){
            if(front == -1 && rear == -1) return true;
            else return false;
        }

    // Function to enqueue an element into the queue...
        void enqueue(int value){
            if(isFull()) cout<<"\nSorry, Queue is FULL.\n"<<endl;
            else if(isEmpty()){
                front = rear = 0;
                Q[rear] = value;
            }
            else{
                rear = (rear + 1 ) % N;
                Q[rear] = value;
            }
        }

    // Function to dequeue an element from the queue...
        int dequeue(){
            if(isEmpty()) cout<<"\nSorry, Queue is EMPTY.\n"<<endl;
            
            int temp = Q[front];
            if (front == rear) {
                front = rear = -1;
                return temp;
            }
            else{
                front = (front + 1) % N;
                return temp;
            }
        }
    // Function to display first element of the queue...
        int lookFront(){
            if(isEmpty()) cout<<"\nSorry, Queue is EMPTY.\n"<<endl;
            else return Q[front];
        }

    // Function to display the all elements in the queue...
        void display(){
            if(isEmpty()) cout<<"\nSorry, Queue is EMPTY.\n"<<endl;
            else{
                int i;

                for(i = front; i != rear; i = (i + 1) % N){
                    cout<<Q[i]<<" ";
                }
                cout<<Q[i]<<" ";
            }
        }
};

int main(){

    CircularQueue queue;

    queue.display();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);

    queue.display();
    
    cout<<endl;
    cout<<endl;

    queue.enqueue(11);

    int first = queue.dequeue();
    int second = queue.dequeue();

    queue.display();

    cout<<endl;
    cout<<endl;

    queue.enqueue(11);
    queue.enqueue(12);

    queue.display();

    cout<<endl;

    queue.enqueue(13);

    cout<<first<<" "<<second<<" "<<endl;

    return 0;
}
