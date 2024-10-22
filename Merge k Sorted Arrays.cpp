#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    int row;
    int col;
    
    node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// Custom comparator for the priority queue.
class compare {
public:
    bool operator()(node*& a, node*& b) {
        return a->data > b->data;  // Min-heap based on the 'data' field.
    }
};

class Solution {
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // Min-heap to store the smallest element of each array.
        priority_queue<node*, vector<node*>, compare> pq;

        // Initialize the heap with the first element of each array.
        for (int i = 0; i < K; i++) {
            node* temp = new node(arr[i][0], i, 0);  // First element from each row.
            pq.push(temp);
        }

        vector<int> ans;

        // Process the priority queue.
        while (!pq.empty()) {
            node* temp = pq.top();
            pq.pop();
            
            int element = temp->data;
            int row = temp->row;
            int col = temp->col;

            ans.push_back(element);

            // If there are more elements in the current row, push the next one.
            if (col + 1 < K) {
                node* newNode = new node(arr[row][col + 1], row, col + 1);
                pq.push(newNode);
            }
        }

        return ans;
    }
};
