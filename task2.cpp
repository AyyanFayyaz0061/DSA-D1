#include <iostream>
using namespace std;

template <class T>
void selectionSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallSub = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[smallSub])
            {
                smallSub = j;
            }
        }

        T temp = arr[i];
        arr[i] = arr[smallSub];
        arr[smallSub] = temp;
    }
}

template <class T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    cout << "Original array: ";
    printArray(arr, size);

    selectionSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
