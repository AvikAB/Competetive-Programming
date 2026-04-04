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

void levelOrder(Node* root){
    if(root==NULL) return;  // base case
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        //process current node
        cout<<current->data<<" ";

        // add left child to queue if it exist
        if(current->left!=NULL){
            q.push(current->left);
        }

        // add right child to queue if it exist
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
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
    cout<<nl;
    cout<<"Level Order: ";
    levelOrder(root);
}



/*
TC: O(n)
*/

// Level Order Traversal using vector:

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
    Node *left, *right ;   // pointer of left, right

    // Constructor to initialize the node with a value
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

vector<int>levelOrder(Node* root){
    vector<int>ans;
    if(root==NULL) return ans;

    queue<Node*>q;
    q.push(root);
    Node *curr;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        ans.push_back(curr->data);

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return ans;
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

    cout<<"Level Order: ";
    vector<int>lvl = levelOrder(root);
    for(auto av:lvl){
        cout<<av<<" ";
    }
    cout<<nl;
}
