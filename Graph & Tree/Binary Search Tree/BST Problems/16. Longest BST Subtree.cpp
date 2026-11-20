// Link: https://www.geeksforgeeks.org/problems/largest-bst/1

class Solution {
  public:
    class Box{
        public:
        bool isBST;
        int size;
        int mn, mx;
        // constructor
        Box(int data){
            // it will start create from a leaf node
            isBST = 1;
            size = 1;
            mn = data;
            mx = data;
        }
    };
    
    Box* find(Node* root, int &totSize){
        // Leaf node
        if(!root->left and !root->right){
            totSize = max(totSize, 1);
            return new Box(root->data);    // new box created
        }
        
        // Only right side exist
        else if(!root->left and root->right){
            Box* curr = find(root->right, totSize);  // giving info for right subt
            // Checking for curr
            if(curr->isBST and curr->mn > root->data){  // for Right subtree's min in BST its > root
                curr->size++;  // its BST & also added with the its root, so size++
                curr->mn = root->data;   // added its root with it thats why min is root's val
                totSize = max(totSize, curr->size);
                return curr;
            } else {   // curr isn't BST
                curr->isBST = 0;
                return curr;
            }
        }
        
        // Only left side exist
        else if(root->left and !root->right){
            Box* curr = find(root->left, totSize);   // giving info about its left side
            // checking for curr
            if(curr->isBST and curr->mx < root->data){   // for left subtree's in BST, left's max < its root
                curr->size++;   // same way
                curr->mx = root->data;
                totSize = max(totSize, curr->size);
                return curr;
            } else {   // left is not BST
                curr->isBST = 0;
                return curr;
            }
        }
        
        // Both side exist
        else {
            // both node exist so find their info
            Box* currLeft = find(root->left, totSize);
            Box* currRight = find(root->right, totSize);
            
            // Now checking, is it BST and conditions of BST
            if(currLeft->isBST and currRight->isBST and currLeft->mx < root->data and currRight->mn > root->data){
                Box* curr = new Box(root->data);  // the whole is BST so create a new box for full info
                curr->size += currLeft->size + currRight->size;  // update the size with left & right subtree's size+1
                curr->mn = currLeft->mn;      // Whole is BST so left side's min will be whole BST's min val
                curr->mx = currRight->mx;     // Whole is BST so right side's max will be whole BST's max val
            
                totSize = max(totSize, curr->size);
                return curr;
            } else {  // the whole is not BST, make any side's isBST = 0
                currRight->isBST = 0;
                return currRight;
            }
        }
    }
    
    int largestBst(Node *root) {
        int totSize = 0;
        find(root, totSize);
        return totSize;
    }
};


/*
TC: O(n)
SC: O(h), O(log n) for balanced tree, O(n) for skewed tree
*/


// Easy way of this:
class Box{
    public:
    bool isBST;
    int size;
    int mn, mx;
    // constructor
    Box(int data){
        isBST = 1;  // initial is all are BST then it enter & checking for isBST
        size = 0;
        // MAX & MIN for if child are present then just update it
        mn = INT_MAX;
        mx = INT_MIN;
    }
};

class Solution {
  public:
    
    Box* find(Node* root, int &totSize){
        // child doesn't exist
        if(!root) return new Box();  // return the box with their initial val whaty I provided in the Box class 
        
        // child exists
        Box* currLeft = find(root->left, totSize);
        Box* currRight = find(root->right, totSize);
        
        // just check with BST conditions
        if(currLeft->isBST and currRight->isBST and currLeft->mx < root->data and currRight->mn > root->data){
            Box* curr = new Box();  // create new box with initial vals
            // now update the all vals in new created box
            curr->size = 1+currLeft->size+currRight->size;
            // check with root->data just because of if there no left child
            curr->mn = min(root->data, currLeft->mn);
            // same for right child, if there is only left child & no right child then thats val update with the root's val
            curr->mx = max(root->data, currRight->mx);
            
            totSize = max(totSize, curr->size);
            return curr;
        } else {   // they are not BST then make any side is false
            currRight->isBST = 0;
            return currRight;
        }
    }
    
    int largestBst(Node *root) {
        int totSize = 0;
        find(root, totSize);
        return totSize;
    }
};
