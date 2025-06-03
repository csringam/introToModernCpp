#include "searchAlgo.h"

searchAlgo::searchAlgo() {
	// Constructor implementation (if needed)
}

searchAlgo::~searchAlgo() {
	// Destructor implementation (if needed)
}

int searchAlgo::BST(int arr[], int key) {
	int left = 0, right = sizeof(arr) / sizeof(arr[0]) - 1;

	while (left <= right) {
		int mid = left + (left + right) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
}
