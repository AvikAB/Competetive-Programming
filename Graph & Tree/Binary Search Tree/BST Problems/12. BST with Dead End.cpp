// Link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

class Solution {
  public:
    bool Dead(Node* root, int lower, int upper){
        if(!root) return false;
        
        // leaf node
        if(!root->left and !root->right){
            if(root->data-lower==1 and upper-root->data==1) return true;
        }
        
        // if not leaf node then check any side
        return Dead(root->left, lower, root->data) or Dead(root->right, root->data, upper);
    }
    
    bool isDeadEnd(Node *root) {
        return Dead(root, 0, INT_MAX);
    }
};

/*
TC: O(n), where n = num of nodes
SC: O(h), h = height, [In worst Case (skewed tree), it becomes O(n)]
*/
