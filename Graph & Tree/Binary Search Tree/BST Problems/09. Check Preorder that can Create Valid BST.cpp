// Link: https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

class Solution {
  public:
    void BST(vector<int>arr, int &idx, int lower, int upper, int n){
        if(idx==n or arr[idx]<lower or arr[idx]>upper) return;  // bc
        
        // no need to create tree here, just track & check that it can 
        // represent a valid BST by preorder
        int value = arr[idx++];
        // Left subt [lower, currVal]
        BST(arr, idx, lower, value, n);
        // Right subt [currVal, upper]
        BST(arr, idx, value, upper, n);
    }
    
    bool canRepresentBST(vector<int> &arr) {
        int idx = 0;
        int n = arr.size();
        BST(arr, idx, INT_MIN, INT_MAX, n);
        return idx==n;
    }
};

/* This is valid but will gives segmentation fault or Runtime Error or sometimes TLE for big inputs.
Because recursive approch takes stack memory area, which has limited capacity. Arround 10^5 or 10^6 it takes too much time & processing large num of eles recursively then
the system tries to allocate memory for all those calls simultaneously, exceeding the stack's capacity and causing a segmentation fault.

Solution: Iterative Approach.
  The iterative approach works because it typically uses containers (like stack, vector) is the part of STL, and this data structures allocate memory in heap area. This is larger
  than the memory's stack area. It easily handles large num of inputs.

Thats why Iterative approach is must needed sometimes when constraints are high and tree can be skewed.
If it says balanced tree will given then recursion is ok.
  */


// AC: Iterative Approach:

bool canRepresentBST(vector<int> &arr) {
    int n = arr.size();
    stack<int>lower, upper;
    lower.push(INT_MIN);
    upper.push(INT_MAX);
    int leftR, rightR;   // range [leftRange, rightRange]
    for(int i=0; i<n; i++){
        // 1. less than lower, out of range
        if(arr[i]<lower.top()) return 0;    // bc
            
        // 2. greater than upper, out of range, make it in range
        while(arr[i]>upper.top()){
            upper.pop();
            lower.pop();
        }
            
        // 3. ele lies in the range
        leftR = lower.top();
        rightR = upper.top();
        lower.pop();
        upper.pop();
        // Add new range for the curr ele's (arr[i]) left subtree & right subtree
        // Add right subtrees's range
        lower.push(arr[i]);
        upper.push(rightR);
        // Add left subtree's range
        lower.push(leftR);
        upper.push(arr[i]);
    }
    return 1;
}
