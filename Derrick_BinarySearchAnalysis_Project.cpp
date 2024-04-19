#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    const int N = 200000;
    double SumRBS = 0.;
    double SumIBS = 0.;
    double SumSeqS = 0.;

    for (int run = 1; run <= 10; ++run) {
        mt19937 mt{ random_device{}() };
        uniform_int_distribution<int> dist{ 1, 100 };

        // Fill vector
        vector<int> arr(N);
        for (int i = 0; i < N; ++i)
            arr[i] = dist(mt);

        // Generate random target value
        int target1 = arr[dist(mt) % N];

        // Measure time for recursive binary search
        auto start = high_resolution_clock::now();
        recursiveBinarySearch(arr, target1, 0, arr.size() - 1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        SumRBS += static_cast<double>(duration.count());

        // Measure time for iterative binary search
        start = high_resolution_clock::now();
        iterativeBinarySearch(arr, target1);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        SumIBS += static_cast<double>(duration.count());

        // Measure time for sequential search
        start = high_resolution_clock::now();
        sequentialSearch(arr, target1);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        SumSeqS += static_cast<double>(duration.count());
    }

    cout << "Average Running Time for Recursive Binary Search in microseconds is " << SumRBS / 10 << endl;
    cout << "Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10 << endl;
    cout << "Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10 << endl;

    return 0;
}
