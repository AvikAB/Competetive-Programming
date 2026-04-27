// Approach 1: (using mathematical expression of idx+(pos-InSt)+1 of Preorder for right subtree)

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e5+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

class Node {
public:
    ll data;
    Node *left, *right ;   // pointer of left, right

    // Constructor to initialize the node with a value
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

ll find(vector<ll>&inorder, ll target, ll start, ll end){
    for(int i=start; i<=end; i++){
        if(inorder[i]==target) return i;
    }
    return -1;
}

Node* Tree(vector<ll>&inorder, vector<ll>&preorder, ll InSt, ll InEnd, ll idx){
    if(InSt>InEnd) return NULL;  // base case

    Node *root = new Node(preorder[idx]);   // create a new root using preorder[idx] val
    ll pos = find(inorder, preorder[idx], InSt, InEnd);

    // Build left tree
    root->left = Tree(inorder, preorder, InSt, pos-1, idx+1);
    // Build right tree
    root->right = Tree(inorder, preorder, pos+1, InEnd, idx+(pos-InSt)+1);
    return root;
}

vector<ll>levelOrder(Node* root){
    vector<ll>ans;
    if(root==NULL) return ans;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();

        if(curr){
            ans.push_back(curr->data);
            q.push(curr->left);
            q.push(curr->right);
        } else ans.push_back(-1);
    }
    
    // Remove trailing nulls
    while(!ans.empty() and ans.back()==-1){
        ans.pop_back();
    }
    return ans;
}

int main(){
    // Direct input method
    ll n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    
    vector<ll> preorder(n), inorder(n);
    
    cout<<"Enter preorder traversal: ";
    for(int i=0; i<n; i++) cin>>preorder[i];
    
    cout<<"Enter inorder traversal: ";
    for(int i=0; i<n; i++) cin>>inorder[i];
    
    // Build tree
    ll preOidx = 0;
    Node* root = Tree(inorder, preorder, 0, n-1, preOidx);  // (inorder, preorder, start_of_inorder, end_of_inorder, start_index_of_preorder)
    
    // Get level order traversal
    vector<ll> level = levelOrder(root);
    
    cout<<"Level Order Traversal (Output): ";
    for(int i=0; i<level.size(); i++){
        if(level[i]==-1) cout<<"null, ";
        else cout<<level[i]<<", ";
    }
    cout<<nl;
}

// TC: O(n^2)
// SC: O(n)

/*
Sample runs & Output:

Enter number of nodes: 5
Enter preorder traversal: 3 9 20 15 7
Enter inorder traversal: 9 3 15 20 7
Level Order Traversal (Output): 3, 9, 20, null, null, 15, 7
*/

// In Approach 1: In a single call, It will call Left & right together.

// Approach 2: (idx by reference)
// All will be same just changes in Tree():
Node* Tree(vector<ll>&inorder, vector<ll>&preorder, ll InSt, ll InEnd, ll &idx){
    if(InSt>InEnd) return NULL;  // base case

    Node *root = new Node(preorder[idx]);   // create a new root using preorder[idx] val
    ll pos = find(inorder, preorder[idx], InSt, InEnd);
    idx++;
    
    // Build left tree
    root->left = Tree(inorder, preorder, InSt, pos-1, idx);
    // Build right tree
    root->right = Tree(inorder, preorder, pos+1, InEnd, idx);
    return root;
}

/*
Why idx + (pos - InSt) + 1?
    1. (pos - InSt) = number of nodes in left subtree (leftSize)
    2. Need to skip: current root (1) + entire left subtree (leftSize)
    3. So index = idx + 1 + leftSize = idx + leftSize + 1
*/

/*
In Approach 2: In a single call, it will going to all left subtree first by the given range [InSt, pos-1].
               After that it will go to all right subtree by the given range [pos+1, InEnd].
*/

// It takes O(n^2) time comp for the find function.

// Approach 3: O(n) Approach using hashmap:

class Solution {
    unordered_map<int,int> inorderMap;  // val -> index mapping
    
    TreeNode* Tree(vector<int>&preorder, int InSt, int InEnd, int &idx){
        if(InSt>InEnd) return NULL;
        
        TreeNode *root = new TreeNode(preorder[idx]);
        int pos = inorderMap[preorder[idx]];
        idx++;
        
        root->left = Tree(preorder, InSt, pos-1, idx);
        root->right = Tree(preorder, pos+1, InEnd, idx);
        
        return root;
    }
    
public:
    TreeNode *buildTree(vector<int>&preorder, vector<int>&inorder) {
        for(int i=0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        int preorderIndex = 0;
        return Tree(preorder, 0, inorder.size()-1, preorderIndex);
    }
};
