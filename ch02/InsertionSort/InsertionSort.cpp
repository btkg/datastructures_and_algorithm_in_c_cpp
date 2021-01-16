#include "SortTestHelper.h"

template <typename T>
void insertionSort(T arr[], int n)
{
    T a, b, c;
    for (b = 1; b < n; b++)
    {
        c = arr[b];
        a = b - 1;
        while (a >= 0 && arr[a] > c)
        {
            arr[a + 1] = arr[a];
            a--;
        }
        arr[a + 1] = c;
    }
}

template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int n = 10000;
    int *arr = SortTestHelper::gengerateNearlyOrderdArray(n, 10);
    int *arr_cp = SortTestHelper::copyIntArray(arr, n);
    // SortTestHelper::printArray(arr, n);
    SortTestHelper::testSort("Insertion Sort: ", insertionSort, arr, n);
    SortTestHelper::testSort("Selection Sort: ", selectionSort, arr_cp, n);    
    // SortTestHelper::printArray(arr, n);
    delete[] arr;
    delete[] arr_cp;
    return 0;
}
