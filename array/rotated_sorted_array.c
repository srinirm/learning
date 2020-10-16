/ Search an element in sorted and rotated 
// array using single pass of Binary Search 
#include <bits/stdc++.h> 
using namespace std; 
  
// Returns index of key in arr[l..h] if 
// key is present, otherwise returns -1 
int search(int arr[], int l, int h, int key) 
{ 
    if (l > h) 
        return -1; 
  
    int mid = (l + h) / 2; 
    if (arr[mid] == key) 
        return mid; 
  
    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid]) { 
        /* As this subarray is sorted, we can quickly 
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid]) 
            return search(arr, l, mid - 1, key); 
        /*If key not lies in first half subarray,  
           Divide other half  into two subarrays, 
           such that we can quickly check if key lies  
           in other half */
        return search(arr, mid + 1, h, key); 
    } 
  
    /* If arr[l..mid] first subarray is not sorted, then arr[mid... h] 
    must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h]) 
        return search(arr, mid + 1, h, key); 
  
    return search(arr, l, mid - 1, key); 
} 





Binary search
********************************

int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
}
