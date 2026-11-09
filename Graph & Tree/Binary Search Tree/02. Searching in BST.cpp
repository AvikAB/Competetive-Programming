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

bool search(Node* root, int target){
    if(!root) return 0;   // base case

    if(target == root->data) return 1;

    if(target < root->data) return search(root->left, target);  // key < curr_node = go to left
    else return search(root->right, target);                    // key > curr_node = go to right
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

    cout<<boolalpha<<search(root, 4)<<nl;
    cout<<boolalpha<<search(root, 14)<<nl;
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
true  // 4
false // 14
*/
