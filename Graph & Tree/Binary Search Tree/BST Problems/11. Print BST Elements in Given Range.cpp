// LinK: https://www.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1

void find(Node* root, vector<int>&ans, int low, int high){
      if(!root) return;
        
      if(root->data>low){  // only go in left side
          find(root->left, ans, low, high);
      }
      if(root->data>=low and root->data<=high){  // in the range
          ans.push_back(root->data);
      }
      if(root->data<high){  // only go in right side
          find(root->right, ans, low, high);
      }
}
    
vector<int> nodesInRange(Node *root, int low, int high) {
    vector<int>ans;
    find(root, ans, low, high);
    return ans;
}


/*
TC: O(h+k), h = height, k = num of valid nodes. In worst case (skewed tree), it becomes O(n), n = Number of all Nodes.
SC: O(h), because of recursion stack. In worst case it becomes O(n).
*/
