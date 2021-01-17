#include "SortTestHelper.h"

template <typename T>
void __merge(T arr[], int l, int mid, int r)
{
    int *arr_cp = SortTestHelper::copyIntArray(arr, r - l + 1);

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
    {
        if (i > mid)
        {
            arr[k] = arr_cp[j - l];
        }
        else if (j > r)
        {
            arr[k] = arr_cp[i - l];
        }
        else if (arr_cp[i - l] < arr_cp[j - l])
        {
            arr[k] = arr_cp[i - l];
            i++;
        }
        else
        {
            arr[k] = arr_cp[j - l];
            j++;
        }
    }
}

template <typename T>
void __mergeSort(T arr[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n)
{
    __mergeSort(arr, 0, n - 1);
}

int main()
{
    int n = 100000;

    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
    return 0;
}