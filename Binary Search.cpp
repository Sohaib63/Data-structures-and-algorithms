#include<iostream>
using namespace std;
int BinarySearch(int A[], int n, int x, bool searchFirst) {
	int low = 0, high = n - 1, result = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] == x) {
			result = mid;
			if (searchFirst)
				high = mid - 1;
			else
				low = mid + 1;
		}
		else if (x < A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return result;
}
int main() {
	int A[] = { 1,1,2,2,3,3,5,5,6,6,6,7,7,8,9,11,12 };
	int x;
	cout << "Enter a number:";
	cin >> x;
	int firstIndex = BinarySearch(A, sizeof(A) / sizeof(A[0]), x, true);
	if (firstIndex == -1) {
		printf("Count of %d is %d", x, 0);
	}
	else {
		int lastIndex= BinarySearch(A, sizeof(A) / sizeof(A[0]), x, false);
		printf("Count of %d is %d", x, lastIndex - firstIndex + 1);
	}
	return 0;
}