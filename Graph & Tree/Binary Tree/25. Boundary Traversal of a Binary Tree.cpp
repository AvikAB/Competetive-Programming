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

// function to check leaf or not
bool isLeaf(Node* node){
    return ((node->left==NULL) and (node->right==NULL));
}

void addLeft(Node* root, vector<ll>&ans){
    Node* curr = root->left;
    while(curr){
        // add if not a leaf node
        if(!isLeaf(curr)) ans.push_back(curr->data);

        // move to left if exist, otherwise right
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeaf(Node* root, vector<ll>&ans){
    if(!root) return;

    // if leaf node add it
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }

    // recursively traverse left & right if they are not leaf
    addLeaf(root->left, ans);
    addLeaf(root->right, ans);
}

void addRight(Node* root, vector<ll>&ans){
    Node* curr = root->right;
    vector<ll>temp;  // for reverse order

    while(curr){
        // add to ans if not a leaf node
        if(!isLeaf(curr)) temp.push_back(curr->data);

        // move to right if exist, else move to left
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    // add temp in reverse order to ans
    for(int i=temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }
}

vector<ll>boundaryTraversal(Node* root){
    vector<ll>ans;
    if(!root) return ans;

    // s1: root into the ans
    ans.push_back(root->data);

    //s2: traverse left subtree, add nodes (avoid leaf)
    if(root->left){
        addLeft(root, ans);
    }

    //s3: traverse leaf nodes
    addLeaf(root, ans);

    // s4: traverse right subtree, add nodes (avoid leaf)
    if(root->right){
        addRight(root, ans);
    }
    return ans;
}

int main(){
    ll x, first, second;   // root, left val, right val
    cout<<"Enter root value: ";
    cin>>x;
    queue<Node*>q;   // queue stores node's pointers
    Node *root = new Node(x);    // creating a root node of x
    q.push(root);

    // build the binary tree
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        // left node:
        cout<<"Enter left child of "<<temp->data<<": ";
        cin>>first;   // val of left node
        if(first!=-1){
            temp->left = new Node(first);   // creating a new node of left & the value is first
            q.push(temp->left);      // push the val into queue
        }

        // right node:
        cout<<"Enter right child of "<<temp->data<<": ";
        cin>>second;
        if(second!=-1){
            temp->right = new Node(second);    // creating a new node of right & the value is second
            q.push(temp->right);    // push the val into queue
        }
    }
    cout<<"Tree Successfully Created!"<<nl;

    vector<ll>sam = boundaryTraversal(root);
    for(auto av:sam){
        cout<<av<<" ";
    }
    cout<<nl;
}


// TC: O(n)
// SC: O(n)
