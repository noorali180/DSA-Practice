#include <iostream>

using namespace std;

int* mergerOfTwoSortedArrays(int* arr1, int* arr2, int n1, int n2){
    int* arr3 = new int[n1 + n2];
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    while(i < n1){
        arr3[k] = arr1[i];
        k++;
        i++;
    }

    while(j < n2){
        arr3[k] = arr2[j];
        k++;
        j++;
    }


    return arr3;
}

int main() {
    int arr1[] = {1, 2, 8, 12, 13, 27, 31, 35};
    int arr2[] = {3, 4, 5, 9, 12, 15};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int * arr3 = mergerOfTwoSortedArrays(arr1, arr2, size1, size2);

    for (int i = 0; i < size1 + size2; i++)
    {
        cout << arr3[i] << endl;
    }

    return 0;
}
