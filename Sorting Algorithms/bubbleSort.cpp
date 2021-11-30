// NOTE: In bubble sort adjacent elements are compared...
/*
TIME COMPLEXITY     T(n) = O(n²)

best case : sorted list => zero swaps
medium case : mixed list => swaps b/w 1 & max
worst case : reverse sorted list => maximum
*/

#include <iostream>

using namespace std;

// function to prit array...
void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout<<"Array["<<i<<"]: "<<arr[i]<<endl;
    }
    cout<<endl;
}

// function of bubble sort...
void bubbleSort(int *arr, int size){
    // loop for passes
    for(int i = 0; i < size; i++){
        // loop for comparisions
        for(int j = 0; j < size -1; j++){
            if(arr[j] > arr[j+1]){
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function...
int main(){
    int arr[] = {56, 44, 33, 23, 20, 12, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<"Array before sort:"<<endl;
    printArray(arr, size);

    cout<<"Array after sort:"<<endl;
    bubbleSort(arr, size);
    printArray(arr, size);

    return 0;
}
