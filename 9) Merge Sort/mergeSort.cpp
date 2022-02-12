#include <iostream>
#include <cmath>

using namespace std;

// function to merge two divided arrays...
void merge(int* arr, int lower, int mid, int upper){
    int i = lower;
    int j = mid + 1;
    int k = lower;
    int b[16];
    
    while(i <= mid && j <= upper){
        if(arr[i] < arr[j]) b[k++] = arr[i++];
        else b[k++] = arr[j++];
    }
    while(i <= mid) b[k++] = arr[i++];
    while(j <= upper) b[k++] = arr[j++];

    for(int i = lower; i <= upper; i++){
        arr[i] = b[i];
    }
}

// function of mergeSort...
void mergeSort(int* arr, int lower, int upper){
    if(lower < upper){
        int mid = floor((upper + lower) / 2);

        mergeSort(arr, lower, mid);
        mergeSort(arr, mid + 1, upper);
        merge(arr, lower, mid, upper);
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

    mergeSort(arr, 0, size - 1);
    display(arr, size);

    return 0;
}
