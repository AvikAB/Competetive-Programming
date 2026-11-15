// Link: https://www.geeksforgeeks.org/problems/construct-bst-from-post-order/1

class Solution {
  public:
    Node* BST(vector<int>&post, int &idx, int lower, int upper){
        if(idx<0 or post[idx]<lower or post[idx]>upper) return NULL;
        
        Node* root = new Node(post[idx--]);  // add a new node
        // right before left
        root->right = BST(post, idx, root->data, upper);
        root->left = BST(post, idx, lower, root->data);
        return root;
    }
 
    Node* constructTree(vector<int>& post) {
        int n = post.size()-1;
        return BST(post, n, INT_MIN, INT_MAX);
    }
};
