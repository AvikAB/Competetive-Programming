// BST
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

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

Node* insert(Node* root, int target){ 
    if(!root){
        Node* temp = new Node(target);
        return temp;
    }

    if(target < root->data){
        root->left = insert(root->left, target);
    } else if(target > root->data){
        root->right = insert(root->right, target);
    }
    return root;
}

Node* deleteNode(Node* root, int x){
    if(!root) return NULL;   // base case

    // search the x
    if(root->data > x){   // go to left side
        root->left = deleteNode(root->left, x);
        return root;
    } else if(root->data < x){   // go to right side
        root->right = deleteNode(root->right, x);
        return root;
    } else {   // root->data==x, found the x node
        // C1: leaf node
        if(!root->left and !root->right){
            delete root;
            return NULL;
        }

        // c2: 1 child exist
        else if(!root->right){   // only left child exist
            Node* temp = root->left;
            delete root;
            return temp;
        } else if(!root->left){    // only right child exist
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // c3: 2 childs exist
        else {
            // find the largest ele from the left
            Node* child = root->left;
            Node* parent = root;

            // go to rightmost node in the left subtree
            while(child->right){
                parent = child;
                child = child->right;
            }

            // that 2 conditions
            if(root!=parent){
                parent->right = child->left;
                // replace with x node, which gonna delete
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            } else {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    // BST CReation
    Node* root = NULL;
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    for(int i=0; i<n; i++){
        root = insert(root, v[i]);
    }

    int x;
    cin>>x;
    root = deleteNode(root, x);
    
    // traversal
    inorder(root);   // printed in sorted order
    cout<<nl;
}



/*
Time Comp:
    Avg: O(log N), N = num of nodes
    Worst: O(N)

SC: O(h), h = height
*/


/*
Input:
5
1 6 3 4 0
3

Output:
0 1 4 6 
*/
