#include <iostream>

using namespace std;

// function to print array...
void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout<<"Array["<<i<<"]: "<<arr[i]<<endl;
    }
    cout<<endl;
}

// function for insertion sort...
void insertionSort(int *arr, int size){
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = {34, 4, 5, 19, 2, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<"Array before sort"<<endl;
    printArray(arr, size);

    cout<<"Array after sort"<<endl;
    insertionSort(arr, size);
    printArray(arr, size);

    return 0;
}
