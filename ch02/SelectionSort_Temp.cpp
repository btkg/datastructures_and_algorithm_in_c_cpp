#include "Student.h"

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
    int a[6] = {10, 9, 8, 7, 3, 6};
    selectionSort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    float b[3] = {1.1, 3.3, 2.3};
    selectionSort(b, 3);
    for (int i = 0; i < 3; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    string c[4] = {"D", "B", "C", "A"};
    selectionSort(c, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;

    Student d[4] = {{"D", 90}, {"C", 40}, {"B", 95}, {"A", 95}};
    selectionSort(d, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << d[i];
    }
    return 0;
}
