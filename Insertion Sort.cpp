#include<iostream>  
using namespace std;

void InsertionSort(int A[], int length) {
    for (int i = 1; i < length; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && key <= A[j])
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
    cout << "\nSorted list with insertion sort :\n";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << "\t";
    }
}

int main()
{
    int arrin[10] = { 12,4,3,1,15,45,33,21,10,2 };
    int len = sizeof(arrin) / sizeof(arrin[0]);
    cout << "Unsorted list is :\n";
    for (int i = 0; i < len; i++)
    {
        cout << arrin[i] << "\t";
    }

    InsertionSort(arrin, len);
    
    return 0;
}
