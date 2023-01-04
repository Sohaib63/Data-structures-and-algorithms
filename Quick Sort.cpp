#include <iostream>
using namespace std;
 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];     
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        
        if (arr[j] <= pivot)
        {
            i++;     
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int arr[] = { 12,23,3,43,51,35,19,45 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }

    cout << endl;
    quickSort(arr, 0, n - 1);
    cout << "Array sorted with quick sort" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    return 0;
}
