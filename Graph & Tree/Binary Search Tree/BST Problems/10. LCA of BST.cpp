// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    if(root->val>p->val and root->val>q->val) // go to left
        return lowestCommonAncestor(root->left, p, q);
    else if(root->val<p->val and root->val<q->val)  // go to right
        return lowestCommonAncestor(root->right, p, q);
    else return root;  // both are in both sides, this is LCA
}

/*
In LC, the 2 nodes are in a pointer, not in a int val, that why using p->val & q->val.

TC: O(h) [for balance tree, h = log n]
         [for skewed tree, h = n-1, so O(h) becomes O(n) in worst case]
         -- In Worst case, skewed tree, height becomes the num of nodes.
SC: O(1) [for iterative solution]
    O(h) [it becomes O(log n) in avg, O(n) in worst]
*/
