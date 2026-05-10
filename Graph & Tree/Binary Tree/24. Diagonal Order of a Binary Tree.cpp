// Method 1: Bruteforce

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

ll find(Node* root, ll pos, ll &l){
    if(!root) return 0;   // base case
    l = max(l, pos);
    find(root->left, pos+1, l);  // need left subtree so that increase it when it get left subtree
    find(root->right, pos, l);
    return l;
}

void findDiag(Node* root, ll pos, vector<vector<ll>>&ans){
    if(!root) return;  // base case

    // NLR approach
    ans[pos].push_back(root->data);
    findDiag(root->left, pos+1, ans);
    findDiag(root->right, pos, ans);
}

vector<ll>diagonalOrder(Node* root){
    if(!root) return {};
    ll l=find(root, 0, l);  // gives max left subtree of a tree
    vector<vector<ll>>ans(l+1);
    findDiag(root, 0, ans);  // (node, pos, ans)

    vector<ll>res;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            res.push_back(ans[i][j]);
        }
    }
    return res;
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

    vector<ll>sam = diagonalOrder(root);
    for(auto av:sam){
        cout<<av<<" ";
    }
    cout<<nl;
}


// TC: O(n^2)
// SC: O(n)


// Method 2: Optiaml way
vector<ll>diagonalOrder(Node* root){
    if(!root) return {};
    
    vector<ll>result;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        // Process all nodes in current diagonal
        while(curr){
            result.push_back(curr->data);
            // If left child exists, it belongs to next diagonal
            if(curr->left){
                q.push(curr->left);
            }
            
            // Move to right child in same diagonal
            curr = curr->right;
        }
    }
    return result;
}
