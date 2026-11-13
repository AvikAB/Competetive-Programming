// Link: https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

class Solution {
  public:
    void revInorder(Node* root, int &k, int &ans){
        if(root==NULL or k<=0) return;  // base case
        
        // traverse right
        revInorder(root->right, k, ans);
        
        // process the node
        k--;
        if(k==0){
            ans = root->data;
            return;
        }
        
        // traverse left
        revInorder(root->left, k, ans);
    }
    
    int kthLargest(Node *root, int k) {
        int ans = -1;
        revInorder(root, k, ans);;
        return ans;
    }
};
