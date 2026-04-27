// Approach 1: Using Mathematical formula of left subtree [idx-(InEnd-pos)-1] from postorder
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
    Node *left, *right;

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

Node* Tree(vector<ll>&inorder, vector<ll>&postorder, ll InSt, ll InEnd, ll idx){
    if(InSt>InEnd) return NULL;   // base case
    
    Node* root = new Node(postorder[idx]);
    ll pos = find(inorder, postorder[idx], InSt, InEnd);

    // build right first
    root->right = Tree(inorder, postorder, pos+1, InEnd, idx-1);

    // then left
    root->left  = Tree(inorder, postorder, InSt, pos-1, idx-(InEnd-pos)-1);

    return root;
}

vector<ll> levelOrder(Node* root){
    vector<ll> ans;
    if(root==NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr){
            ans.push_back(curr->data);
            q.push(curr->left);
            q.push(curr->right);
        } else {
            ans.push_back(-1);
        }
    }

    // remove trailing nulls
    while(!ans.empty() and ans.back()==-1){
        ans.pop_back();
    }
    return ans;
}

int main(){
    ll n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    vector<ll> postorder(n), inorder(n);
    cout<<"Enter inorder traversal: ";
    for(int i=0; i<n; i++) cin>>inorder[i];

    cout<<"Enter postorder traversal: ";
    for(int i=0; i<n; i++) cin>>postorder[i];
    
    Node* root = Tree(inorder, postorder, 0, n-1, n-1);

    vector<ll> level=levelOrder(root);
    cout<<"Level Order Traversal (Output): ";
    for(int i=0; i<level.size(); i++){
        if(level[i] == -1) cout<< "null, ";
        else cout << level[i]<<", ";
    }
}


// TC: O(n^2)
// SC: O(n)


// Approach 2: idx pass by reference
// Just change in Tree() where just do idx-- and call for left & right using idx and chaneg in main(), just doing a variable and call it by variable
Node* Tree(vector<ll>&inorder, vector<ll>&postorder, ll InSt, ll InEnd, ll &idx){
    if(InSt>InEnd) return NULL;   // base case
    
    Node* root = new Node(postorder[idx]);
    ll pos = find(inorder, postorder[idx], InSt, InEnd);
    idx--;

    // build right first
    root->right = Tree(inorder, postorder, pos+1, InEnd, idx);
    // then left
    root->left  = Tree(inorder, postorder, InSt, pos-1, idx);

    return root;
}

int main(){
    ll n;
    cout<<"Enter number of nodes: ";
    cin >> n;
    vector<ll> postorder(n), inorder(n);
    cout<<"Enter inorder traversal: ";
    for(int i=0; i<n; i++) cin>>inorder[i];

    cout<<"Enter postorder traversal: ";
    for(int i=0; i<n; i++) cin>>postorder[i];
    
    ll idx = n-1;
    Node* root = Tree(inorder, postorder, 0, n-1, idx);

    vector<ll> level=levelOrder(root);

    cout<<"Level Order Traversal (Output): ";
    for(int i=0; i<level.size(); i++){
        if(level[i]==-1) cout<< "null, ";
        else cout<<level[i]<<", ";
    }
}


// Approach 3: Using hashmap [TC: O(n)]
class Solution {
  public:
    unordered_map<int,int> InorderMap;
    
    TreeNode* Tree(vector<int> &inorder, vector<int> &postorder, int InSt, int InEnd, int &idx){
        if(InSt>InEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[idx]);
        int pos = InorderMap[postorder[idx]];
        idx--;    // move backward for postorder
        
        // Right:
        root->right = Tree(inorder, postorder, pos+1, InEnd, idx);
        // left:
        root->left = Tree(inorder, postorder, InSt, pos-1, idx);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for(int i=0; i<inorder.size(); i++){
            InorderMap[inorder[i]] = i;
        }

        int postOidx = postorder.size()-1;
        return Tree(inorder, postorder, 0, inorder.size()-1, postOidx);
    }
};
