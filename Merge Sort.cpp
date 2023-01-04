#include <iostream>
using namespace std;
void Merge(int* arr, int low, int mid, int high);
void Merge_sort(int* arr, int low, int high)
{
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        Merge_sort(arr, low, mid);
        Merge_sort(arr, mid + 1, high);
        
        Merge(arr, low, mid, high);
    }
}

void Merge(int* arr, int low, int mid, int high)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}

int main()
{
    int arrin[10] = { 12,4,3,1,100,415,323,213,120,2 };
    int num = sizeof(arrin) / sizeof(arrin[0]);
    cout << "Unsorted list is :\n";
    for (int i = 0; i < num; i++)
    {
        cout << arrin[i] << "\t";
    }
    Merge_sort(arrin, 0, num - 1);
    cout << "\nSorted array with merge sort\n";
    for (int i = 0; i < num; i++)
    {
        cout << arrin[i] << "\t";
    }
    return 0;
}

