#include <iostream>

using namespace std;

int soa = 10;
int top = -1;

// FUNCTION TO FIND IF STACK IS EMPTY...
void isEmpty(){
    if(top == -1) cout<<"STACK is empty."<<endl;
}

// FUNCTION TO FIND IF STACK IS FULL...
void isFull(){
    if (top == soa - 1) cout<<"STACK is full."<<endl;
}

// FUNCTION TO PUSH ELEMENTS IN STACK...
void push(int* arr, int value){
    if(top == soa - 1) cout<<"Stack is full."<<endl;
    else arr[++top] = value;
}

// FUNCTION TO POP ELEMENTS IN STACK...
int pop(int* arr){
    if(top == -1) cout<<"Stack is empty."<<endl;
    else return arr[top--];
}

// FUNCTION TO PEEK IN STACK...
int peek(int* arr){
    if(top == -1) cout<<"Stack is empty.";
    return arr[top];
}

// FUNCTION TO DISPLAY ELEMENTS IN STACK...
void display(int* arr){
    for(int i = 0; i <= top; i++){
        cout<<arr[i]<<" ";
    }
} 

int main(){
    int arr[soa];

    isEmpty();

    push(arr, 5);
    push(arr, 10);
    push(arr, 15);
    push(arr, 20);

    int popped = pop(arr);

    display(arr);

    cout<<"\nPopped Element: "<<popped<<endl;

    return 0;
}
