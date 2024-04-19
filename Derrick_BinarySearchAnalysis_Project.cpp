#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Recursive binary search function
int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high) {
    if (low > high) {
        return -1; // Base case: target not found
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid; // Base case: target found at mid
    }
    else if (arr[mid] < target) {
        return recursiveBinarySearch(arr, target, mid + 1, high); // Search in the right half
    }
    else {
        return recursiveBinarySearch(arr, target, low, mid - 1); // Search in the left half
    }
}

// Iterative binary search function
int iterativeBinarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; // Target found
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // Target not found
}

// Sequential search function
int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Target found
        }
    }
    return -1; // Target not found
}

int main() {
    mt19937 mt{ random_device{}() };
    uniform_int_distribution<int> dist{ 1, 100 };

    // Fill vector
    vector<int> arr(9);
    for (int i = 0; i < 9; ++i)
        arr[i] = dist(mt);

    // Display vector
    cout << "VECTOR: ";
    for (int i : arr)
        cout << i << " ";
    cout << endl << "\n";

    // Generate target value within the range of vector elements
    int target1 = arr[dist(mt) % arr.size()];

    // Test recursive binary search
    int index1 = recursiveBinarySearch(arr, target1, 0, arr.size() - 1);
    cout << "RECURSIVE BINARY SEARCH" << endl;
    if (index1 >= 0)
        cout << "Target " << target1 << " was found at location " << index1 << endl;
    else
        cout << "Target " << target1 << " was not found, return value is " << index1 << endl << "\n";

    // Test iterative binary search
    int index2 = iterativeBinarySearch(arr, target1);
    cout << "ITERATIVE BINARY SEARCH" << endl;
    if (index2 >= 0)
        cout << "Target " << target1 << " was found at location " << index2 << endl;
    else
        cout << "Target " << target1 << " was not found, return value is " << index2 << endl << "\n";

    // Test sequential search
    int index3 = sequentialSearch(arr, target1);
    cout << "SEQUENTIAL SEARCH" << endl;
    if (index3 >= 0)
        cout << "Target " << target1 << " was found at location " << index3 << endl;
    else
        cout << "Target " << target1 << " was not found, return value is " << index3 << endl;

    return 0;
}
