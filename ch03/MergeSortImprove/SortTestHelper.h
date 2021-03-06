#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include <ctime>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

namespace SortTestHelper
{
    template <typename T>
    void insertionSort(T arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {

            T e = arr[i];
            int j;
            for (j = i; j > 0 && arr[j - 1] > e; j--)
                arr[j] = arr[j - 1];
            arr[j] = e;
        }

        return;
    }

    int *generateRandomArray(int n, int rangeL, int rangeR)
    {
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    int *gengerateNearlyOrderdArray(int n, int swapTimes)
    {
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = i;
        }

        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++)
        {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    template <typename T>
    void printArray(T arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    bool isSorted(T arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    template <typename T>
    void testSort(string sortName, void (*sort)(T[], int), T arr[], int n)
    {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }

    int *copyIntArray(int a[], int n)
    {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }
} // namespace SortTestHelper

#endif