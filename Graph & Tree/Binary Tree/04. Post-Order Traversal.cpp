// Method 1: Using recursive way

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
    int data;
    Node *left, *right;   // pointer of left, right

    // Constructor to initialize the node with a value
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void PostOrder(Node *root){
    if(root==NULL) return;   // Base case: end of branch
    // LRN
    PostOrder(root->left);    // visit left
    PostOrder(root->right);   // visit right
    cout<<root->data<<" ";   // visit root
}

int main(){
    int x, first, second;   // root, left val, right val
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

    cout<<"PostOrder: ";
    PostOrder(root);
}



/*
TC: O(n)
SC: O(n)
*/

// Method 2: Using iterative way:
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

vector<ll>postorder(Node* root){  // LRN but here we will use NRL
    stack<Node*>s;
    s.push(root);
    vector<ll>ans;

    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        // left first then right
        if(temp->left) s.push(temp->left);
        if(temp->right) s.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
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

    vector<ll> ans = postorder(root);
    for(auto &av:ans){
        cout<<av<<" ";
    }
    cout<<nl;
}


// TC: O(n)
// SC: O(n)
