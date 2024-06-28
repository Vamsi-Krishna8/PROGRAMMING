#include <iostream>
#include <vector>

using namespace std;

// Function to perform binary search
int binarySearch(vector<int> arr, int target) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      return mid; // Target found at index mid
    } else if (arr[mid] < target) {
      left = mid + 1; // Search in the right half
    } else {
      right = mid - 1; // Search in the left half
    }
  }

  return -1; // Target not found
}

int main() {
  vector<int> arr = {2, 5, 7, 8, 11, 12};
  int target = 13;

  int index = binarySearch(arr, target);

  if (index != -1) {
    cout << "Target found at index: " << index << endl;
  } else {
    cout << "Target not found." << endl;
  }

  return 0;
}