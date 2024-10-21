void MaxHeap(vector<int> &arr, int i, int N) {
    int largest = i;
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    // Check if left child is larger than root
    if (left < N && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child is larger than the largest so far
    if (right < N && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeap(arr, largest, N);  // Recursively heapify the affected sub-tree
    }
}

// Function to convert min-heap to max-heap
void convertMinToMaxHeap(vector<int> &arr, int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = (n / 2) - 1; i >= 0; i--) {
        MaxHeap(arr, i, n);
    }
}
