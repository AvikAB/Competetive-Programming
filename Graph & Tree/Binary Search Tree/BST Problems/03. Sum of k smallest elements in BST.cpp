// Link: https://www.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1

class Solution {
  public:
    void inOrderHelper(Node* root, int k, int &cnt, int &sum){
        if(root==NULL or cnt>=k) return;   // base case
        
        // traverse left subtree
        inOrderHelper(root->left, k, cnt, sum);
        
        // process the curr node
        if(cnt<k){
            sum += root->data;
            cnt++;
        }
        
        // traverse the right subtree, if we still more
        if(cnt<k){
            inOrderHelper(root->right, k, cnt, sum);
        }
    }
    
    int sum(Node* root, int k) {
        int cnt = 0, sum = 0;
        inOrderHelper(root, k, cnt, sum);
        return sum;
    }
};


/*
TC: O(min(n,k)
SC: O(h)
*/

// Method 2: Track with k
void inOrderHelper(Node* root, int &k, int &sum){
        if(root==NULL or k<=0) return;   // base case
        
        // traverse left subtree
        inOrderHelper(root->left, k, sum);
        
        // process the curr node
        k--;
        if(k>=0){
            sum += root->data;
        }
        
        // traverse the right subtree
        inOrderHelper(root->right, k, sum);
    }
    
    int sum(Node* root, int k) {
        int sum = 0;
        inOrderHelper(root, k, sum);
        return sum;
    }
