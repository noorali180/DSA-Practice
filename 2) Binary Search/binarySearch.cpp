// NOTE: Binary search wants a sorted array for searching...

#include <iostream>
#include <math.h>

using namespace std;

// function to print array...
void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout<<"Array["<<i<<"]: "<<arr[i]<<endl;
    }
    cout<<endl;
}

// function of binary search...
int binarySearch(int *arr, int lower, int upper, int value){
    int i = lower;
    int j = upper;

    while(i <= j){
        int mid = floor((i + j) / 2);

        if(arr[mid] == value) return mid;
        if(arr[mid] < value) i = mid + 1;
        if(arr[mid] > value) j = mid - 1;
    }

    return -1;
}

// Main function...
int main(){
    int arr[] = {13, 25, 26, 35, 39, 42, 45, 48, 60, 72, 98, 110};
    int size = sizeof(arr) / sizeof(arr[0]);
    int searchedIndex;

    cout<<"Array before search:"<<endl;
    printArray(arr, size);

    searchedIndex = binarySearch(arr, 0, size - 1, 98);

    if(searchedIndex == -1) cout<<"Sorry Element not found"<<endl;
    else cout<<"Element found at index: "<<searchedIndex<<endl;


    return 0;
}
