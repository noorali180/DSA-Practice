#include <iostream>

using namespace std;

int* mergerOfTwoArrays(int *arr1, int *arr2, int n1, int n2)
{
    int* arr3 = new int[n1 + n2];
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        arr3[k] = arr1[i];
        k++;
    }

    for (int i = 0; i < n2; i++)
    {
        arr3[k] = arr2[i];
        k++;
    }

    return arr3;
}

int main()
{
    int arr1[] = {12, 55, 7, 28, 13, 98, 13, 22};
    int arr2[] = {34, 55, 32, 12, 67, 89};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int * arr3 = mergerOfTwoArrays(arr1, arr2, size1, size2);

    for (int i = 0; i < size1 + size2; i++)
    {
        cout << arr3[i] << endl;
    }

    return 0;
}
