// when using arrays, circular queue is far better than linear queue 🙃...
// FIFO (first in first out)...
// must follow, O(1), for every functionality...
// DRAWBACK OF LINEAR QUEUE >> "In a linear queue, the traversal through the queue is possible only once,i.e.,once an element is deleted, we cannot insert another element in its position. This disadvantage of a linear queue is overcome by a circular queue, thus saving memory."

#include <iostream>

using namespace std;

#define SOQ 10

int queue[SOQ];
int front = -1;
int rear = -1;

// FUNCTION SIGNATURES...

// function to check if queue is full...
bool isFull(){
    if(rear == SOQ - 1) return true;
    else return false;
}

// function to check if queue is empty...
bool isEmpty(){
    if(front == -1 && rear == -1) return true;
    else return false;
}

// function to insert element (enqueue) in the queue... (always to last).
void enqueue(int value){
    if(isFull()) cout<<"\nSorry, Queue is full."<<endl;
    else if(isEmpty()) {
        front = rear = 0;
        queue[rear] = value;
    }
    else{
        queue[++rear] = value;
    }
}

// function to delete element (dequeue) from the queue... (always from front).
int dequeue(){
    if(isEmpty()) cout<<"\nSorry, Queue is empty."<<endl;
    int value = queue[front];
    if(front == rear) {
        front = rear = -1;
        return value;
    }
    else{
        front++;
        return value;
    }
}

// function to look the first element in the queue...
int lookFront(){
    if(isEmpty()) cout<<"\nSorry, Queue is empty."<<endl;
    else return queue[front];
}

// function to display the queue...
void display(){
    for(int i = front; i <= rear; i++){
        cout<<queue[i]<<" ";
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);

    int first = dequeue();
    int second = dequeue();
    int third = dequeue();

    display();

    cout<<endl;
    cout<<"deleted elements: "<<first<<" "<<second<<" "<<third<<" "<<endl;
    
    enqueue(11);

    return 0;
}
