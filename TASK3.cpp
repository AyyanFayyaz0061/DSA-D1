#include <iostream>
#include <string>
using namespace std;

template <class T>
int linearSearch(T arr[], int size, T value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }

    return -1;
}

template <class T>
void printSearchResult(int index, T value)
{
    if (index != -1)
    {
        cout << value << " found at index " << index << endl;
    }
    else
    {
        cout << value << " not found" << endl;
    }
}

int main()
{
    int size;

    cout << "Enter array size: ";
    cin >> size;

    int arr[100];

    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    int index = linearSearch(arr, size, value);

    printSearchResult(index, value);

    return 0;
}
