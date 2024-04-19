// Derrick_BinarySearchAnalysis_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
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
    mt19937 rng(random_device{}()); // create random number generator
    uniform_int_distribution<int> distribution(1, 100); // define a range

    vector<int> arr;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(distribution(rng)); // fill vector with random numbers
    }
    int target = distribution(rng); // generate target value

    // display vector & target
    cout << "VECTOR: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl << "\n";
    cout << "TARGET: " << target << endl << "\n";

    // test recursive binary search
    int index1 = recursiveBinarySearch(arr, target, 0, arr.size() - 1); // target in vector
    cout << "RECURSIVE BINARY SEARCH" << endl;
    if (index1 > 0)
        cout << "Target " << target << " was found at location " << index1 << endl;
    else
        cout << "Target " << target << " was not found, return value is " << index1 << endl << "\n";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl << "\n";
    cout << "TARGET: " << target << endl << "\n";

    // test iterative binary search
    int index2 = iterativeBinarySearch(arr, target);
    cout << "ITERATIVE BINARY SEARCH" << endl;
    if (index2 > 0)
        cout << "Target " << target << " was found at location " << index2 << endl;
    else
        cout << "Target " << target << " was not found, return value is " << index2 << endl << "\n";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl << "\n";
    

    // test sequential search
    int index3 = sequentialSearch(arr, target);
    cout << "SEQUENTIAL SEARCH" << endl;
    if (index3 > 0)
        cout << "Target " << target << " was found at location " << index3 << endl;
    else
        cout << "Target " << target << " was not found, return value is " << index3 << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl << "\n";
    
}
