// Link: https://leetcode.com/problems/validate-binary-search-tree/

// Method 1: inorder + vector
class Solution {
public:
    void inorder(TreeNode* root, vector<int>&ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root, ans);
        for(int i=1; i<ans.size(); i++){
            if(ans[i-1]>=ans[i]) return false;
        }
        return true;
    }
};

/*
TC; O(n)
SC: O(n)
n = num of nodes
*/


// Method 2: Inorder + prev reference

class Solution {
public:
    // optimized
    bool BST(TreeNode* root, long long &prev){
        if(!root) return true;

        bool l = BST(root->left, prev);
        if(l==false) return false;

        if(root->val <= prev) return false;
        else prev = root->val;

        return BST(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return BST(root, prev);
    }
};

/*
TC: O(n)
SC: O(h), h = height of tree
no extra space, so it is optimal
*/
