// Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

class Solution {
public:
    void minDist(TreeNode* root, int &prev, int &ans){
        if(!root) return;

        // inorder - LNR
        minDist(root->left, prev, ans);
        if(prev!=INT_MIN) ans = min(ans, root->val-prev);
        prev = root->val;
        minDist(root->right, prev, ans);

    }
    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;
        int ans = INT_MAX;
        minDist(root, prev, ans);
        return ans;
    }
};
