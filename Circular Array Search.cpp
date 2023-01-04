#include<iostream>
using namespace std;
int CircularArraySearch(int A[], int n, int x) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] == x) 
			return mid;
		if (A[mid]<= A[high]){
			if (x>A[mid] && x<=A[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
		else {
			if (A[low]<=x && x<A[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return -1;
}
int main() {
	int A[] = { 2,2,2,2,2,0,2,2 };
	int x;
	cout << "Enter a number:";
	cin >> x;
	int index = CircularArraySearch(A, 2, x);
	if (index == -1)
		printf("%d not found in the array.");
	else
		printf("%d was found at index %d", x, index);
	return 0;
}