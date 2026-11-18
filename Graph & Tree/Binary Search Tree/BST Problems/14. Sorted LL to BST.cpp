// Link: https://www.geeksforgeeks.org/problems/sorted-list-to-bst/1

class Solution {
  public:
    TNode* BuildBST(vector<int>&v, int start, int end){
        if(start>end) return NULL;
        
        int mid = start+(end-start+1)/2;
        TNode* root = new TNode(v[mid]);   // create a new node of mid val
        
        root->left = BuildBST(v, start, mid-1);
        root->right = BuildBST(v, mid+1, end);
        return root;
    }
    
    TNode *sortedListToBST(LNode *head) {
        vector<int>v;
        while(head){
            v.push_back(head->data);
            head = head->next;
        }
        return BuildBST(v, 0, v.size()-1);
    }
};

/*
TC: O(n)
SC; O(n) for an auxiliary space
*/
