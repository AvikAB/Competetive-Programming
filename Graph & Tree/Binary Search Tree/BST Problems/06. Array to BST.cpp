// Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution {
public:
    TreeNode* createBST(vector<int>&nums, int start, int end){
        if(start>end) return NULL;

        int mid = start+(end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = createBST(nums, start, mid-1);
        root->right = createBST(nums, mid+1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        return createBST(nums, start, end);
    }
};

/*
TC: O(n)
SC: O(log n), because of divide & conquer approch.
*/
