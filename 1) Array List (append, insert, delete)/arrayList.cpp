#include <iostream>

using namespace std;
int soa = 15; // size of array
int nas = 0;  // next available slot

// function to print array...
void printArray(int *arr)
{
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < nas; i++)
    {
        cout << "Array[" << i << "]: " << arr[i] << endl;
    }
    cout << endl;
}

// function to append elem in array...
void append(int *arr, int value)
{
    if (nas < soa)
    {
        arr[nas] = value;
        nas++;
    }
}

// function to insert elem in array...
void insert(int *arr, int pos, int value)
{
    if (pos < 0 || pos >= nas)
    {
        cout << "\nSorry Position not found\n"
             << endl;
        return;
    }

    for (int i = nas - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = value;
    nas++;
}

// function to delete elem from array...
void deleteElem(int *arr, int pos)
{
    if (pos < 0 || pos >= nas)
    {
        cout << "\nSorry Position not found\n"
             << endl;
        return;
    }

    for (int i = pos; i < nas - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    nas--;
}

// funtion to search elems in array...
int search(int *arr, int value)
{
    for (int i = 0; i < nas; i++)
    {
        if (arr[i] == value)
            return i;
    }

    return -1;
}

// main function...
int main()
{
    int arr[soa];
    char ch;
    int elemToSearch, searchedIndex;

    append(arr, 1);
    append(arr, 2);
    append(arr, 3);
    append(arr, 5);
    append(arr, 6);
    append(arr, 7);

    printArray(arr);

    cout << "after insertion" << endl;

    insert(arr, 3, 4);
    printArray(arr);
    cout << "--------------------------------------\n"
         << endl;
    insert(arr, 4, 25);
    printArray(arr);

    cout << "after deletion" << endl;
    deleteElem(arr, 4);
    printArray(arr);

    cout << "--------------------------------------\n"
         << endl;

    cout << "Do you want to search an element (y/n): ";
    cin >> ch;

    if (ch == 'y')
    {
        cout << "\nEnter an value to search: ";
        cin >> elemToSearch;

        searchedIndex = search(arr, elemToSearch);
        if (searchedIndex == -1)
            cout << "\nSearched element is not found" << endl;
        else
            cout << "\nElement " << elemToSearch << " found at index " << searchedIndex << endl;
    }

    return 0;
}
