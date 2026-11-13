// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    void inorder(TreeNode* node, int &k, int &ans){
        if(node==NULL or k<=0) return;  // bc
        // traverse left
        inorder(node->left, k, ans);
        // process the node
        k--;
        if(k==0){
            ans = node->val;
            return;
        }
        // traverse right
        inorder(node->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
