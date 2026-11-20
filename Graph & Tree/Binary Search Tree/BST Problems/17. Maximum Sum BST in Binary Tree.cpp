// Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

// Same as previous, just add sum instead of size.

 class Box{
    public:
    bool isBST;
    int sum;
    int mn, mx;
    Box(){
        isBST = 1;
        sum = 0;
        mn = INT_MAX;
        mx = INT_MIN;
    }
 };

class Solution {
public:
    Box* find(TreeNode* root, int &mxSum){
        // child doesn't exist
        if(!root) return new Box(); // return the box with its initial val

        // child exists
        Box* currLeft = find(root->left, mxSum);
        Box* currRight = find(root->right, mxSum);

        // just check with BST condtitions
        if(currLeft->isBST and currRight->isBST and currLeft->mx < root->val and currRight->mn > root->val){
            // this whole side is BST
            Box* curr = new Box();  // create a new box with initial vals
            // now update the vals
            curr->sum = root->val + currLeft->sum + currRight->sum;
            curr->mn = min(root->val, currLeft->mn);
            curr->mx = max(root->val, currRight->mx);

            mxSum = max(mxSum, curr->sum);
            return curr;
        } else {  // the whole are not BST, make any side is false
            currLeft->isBST = 0;
            return currLeft;
        }
    }

    int maxSumBST(TreeNode* root) {
        int mxSum = 0;
        find(root, mxSum);
        return mxSum;
    }
};
