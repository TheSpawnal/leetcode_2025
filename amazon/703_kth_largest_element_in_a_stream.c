/*
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8

Example 2:

Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

Output: [null, 7, 7, 7, 8]

Explanation:

KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8
 

Constraints:

0 <= nums.length <= 104
1 <= k <= nums.length + 1
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
*/


#include <stdlib.h>

// Define the KthLargest structure
typedef struct {
    int k;         // The k value to track the kth largest element
    int size;      // Current size of the heap
    int capacity;  // Maximum capacity of the heap (will be set to k)
    int* heap;     // Min-heap array to store the k largest elements
} KthLargest;

// Helper function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to heapify down (maintain min-heap property)
void heapifyDown(int* heap, int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    // Find the smallest among the node and its children
    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    // If the smallest is not the current node, swap and continue heapifying
    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Helper function to heapify up (maintain min-heap property)
void heapifyUp(int* heap, int idx) {
    // Calculate parent index
    int parent = (idx - 1) / 2;
    
    // If current node is smaller than its parent, swap and continue heapifying up
    if (idx > 0 && heap[idx] < heap[parent]) {
        swap(&heap[idx], &heap[parent]);
        heapifyUp(heap, parent);
    }
}

// Create a new KthLargest object
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    // Allocate memory for the KthLargest structure
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    
    // Initialize the object properties
    obj->k = k;
    obj->size = 0;
    obj->capacity = k;
    obj->heap = (int*)malloc(sizeof(int) * k);
    
    // Add initial elements from nums array to the heap
    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }
    
    return obj;
}

// Add a new value to the KthLargest object and return the kth largest element
int kthLargestAdd(KthLargest* obj, int val) {
    // Case 1: Heap is not full yet (size < k)
    if (obj->size < obj->capacity) {
        // Add value to the end of the heap
        obj->heap[obj->size] = val;
        // Heapify up to maintain min-heap property
        heapifyUp(obj->heap, obj->size);
        // Increment size
        obj->size++;
    }
    // Case 2: Heap is full and new value is larger than the smallest value in heap
    else if (val > obj->heap[0]) {
        // Replace the root (smallest) with the new value
        obj->heap[0] = val;
        // Heapify down to maintain min-heap property
        heapifyDown(obj->heap, obj->size, 0);
    }
    
    // Return the kth largest element (root of min-heap)
    return obj->heap[0];
}

// Free the KthLargest object
void kthLargestFree(KthLargest* obj) {
    // Free the heap array
    free(obj->heap);
    // Free the KthLargest structure
    free(obj);
}

