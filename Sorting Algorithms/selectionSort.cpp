// NOTE: 
/*
• Method:
    – Find the smallest/largest element in the array
    – Exchange it with the element in the first/last position position
    – Find the second smallest/largest element and exchange it with the element in the second/second last position
    – Continue until the array is sorted
• Nested Loops: 
    – Outer Loop is used to place the element/item at its correct position.
    – Inner loop traverses through the list for finding kth minimum/maximum excluding settled elements.

*/
/*
TIME COMPLEXITY     T(n) = O(n²)

best case : sorted list => n-1 (at most)
medium case : mixed list => n-1 (at most)
worst case : reverse sorted list => n-1 (at most)
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

// function for selection sort...
void selectionSort(int *arr, int size){
    int min;
    for(int i = 0; i < size; i++){
        min = i;
        for(int j = i + 1; j < size; j++){
            if(arr[min] > arr[j]) min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
// main function...
int main(){
    int arr[] = {8, 6, 2, 4, 5, 9, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<"Array before sort"<<endl;
    printArray(arr, size);

    cout<<"Array after sort"<<endl;
    selectionSort(arr, size);
    printArray(arr, size);


    return 0;
}

