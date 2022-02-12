#include<iostream>

using namespace std;

// function for performing swaping...
void swap(int* arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// function to divide the array for conquerence...
int partition(int* arr, int lower, int upper){
    int pivot = lower;
    int p = lower + 1;
    int q = upper;
    while(p <= q){
        while(arr[p] < arr[pivot]) p++;
        while(arr[q] > arr[pivot]) q--;
        if(p < q) swap(arr, p, q);
    }
    swap(arr, pivot, q);

    return q;
}

// function to sort the divided arrays recursiveley...
void quickSort(int* arr, int lower, int upper){
    if(lower < upper){
        int i = partition(arr, lower, upper);

        quickSort(arr, lower, i - 1);
        quickSort(arr, i + 1, upper);
    }
}

// function to display elements present in the array...
void display(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

// main function...
int main(){
    int arr[] = {59, 32, 57, 33, 31, 15, 17, 91, 89, 66, 128, 64, 79, 83, 99, 101};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, size - 1);
    display(arr, size);

    return 0;
}
