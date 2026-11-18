// Link: https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

class Solution {
  public:
    void inorder(Node* root, vector<int>&v){
        if(!root) return;
        
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    vector<int> merge(Node *r1, Node *r2) {
        vector<int>ans1;
        vector<int>ans2;
        // find their inorder traversal & store it in vector
        inorder(r1, ans1);
        inorder(r2, ans2);
        
        vector<int>ans;
        int i = 0, j = 0;
        while(i<ans1.size() and j<ans2.size()){
            if(ans1[i] < ans2[j]) ans.push_back(ans1[i++]);
            else ans.push_back(ans2[j++]);
        }
        
        // then any remaining ele left
        while(i<ans1.size()){
            ans.push_back(ans1[i++]);
        }
        while(j<ans2.size()){
            ans.push_back(ans2[j++]);
        }
        return ans;
    }
};
