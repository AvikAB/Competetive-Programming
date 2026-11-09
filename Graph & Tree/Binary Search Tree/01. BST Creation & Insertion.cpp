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

Node* insert(Node* root, int target){    // (copy_of_the_pointer(address_value), next_node's_val)
    if(!root){   // base case: when its leaf then add new node to it
        Node* temp = new Node(target);
        return temp;
    }

    if(target < root->data){          // curr<root = put it in left side
        root->left = insert(root->left, target);
    } else if(target > root->data){   // curr>root = go to right side
        root->right = insert(root->right, target);
    }
    // curr==root do nothing or to the right subtree
    return root;
}

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

void InOrder(Node *root){
    if(root==NULL) return;
    // LNR
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

int main(){
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

    // Traversal
    levelOrder(root);
    cout<<nl;
    InOrder(root);
}



/*
Time Comp:
    Best: O(1)
    Avg: O(log N), N = num of nodes
    Worst: O(N)

SC: O(h), h = height
*/


/*
Input:
5
1 6 3 4 0

Output:
1 0 6 3 4 
0 1 3 4 6 
*/
