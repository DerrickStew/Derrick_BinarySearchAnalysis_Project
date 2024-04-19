// Derrick_BinarySearchAnalysis_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

// recursive binary search
int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid; //target found
        else if (arr[mid] < target)
            return recursiveBinarySearch(arr, target, mid + 1, high);
        else
            return recursiveBinarySearch(arr, target, low, mid - 1);
    }
    else
        return -1; // target not found
}


// iterative binary search
int iterativeBinarySearch(const vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid; //target found
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; //target not found
}


// sequential search
int sequentialSearch(const vector<int>& arr, int target)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target) // target found
            return i;
    }
    return -1; // target not found
}


// test search functions
int main()
{
    // fill vector
    vector<int> arr = { 1,3,5,7,2,4,6,8,12 };
    int target1 = 6;
    int target2 = 20;

    // display vector
    cout << "VECTOR: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl << "\n";

    // test recursive binary search
    int index1 = recursiveBinarySearch(arr, target1, 0, arr.size() - 1); // target in vector
    int index2 = recursiveBinarySearch(arr, target2, 0, arr.size() - 1); // target not in vector
    cout << "RECURSIVE BINARY SEARCH" << endl;
    cout << "Target " << target1 << " was found at location " << index1 << endl;
    cout << "Target " << target2 << " was not found, return value is " << index2 << endl << "\n";

    // test iterative binary search
    int index3 = iterativeBinarySearch(arr, target1);
    int index4 = iterativeBinarySearch(arr, target2);
    cout << "ITERATIVE BINARY SEARCH" << endl;
    cout << "Target " << target1 << " was found at location " << index3 << endl;
    cout << "Target " << target2 << " was not found, return value is " << index4 << endl << "\n";

    // test sequential search
    int index5 = sequentialSearch(arr, target1);
    int index6 = sequentialSearch(arr, target2);
    cout << "SEQUENTIAL SEARCH" << endl;
    cout << "Target " << target1 << " was found at location " << index5 << endl;
    cout << "Target " << target2 << " was not found, return value is " << index6 << endl;

}
