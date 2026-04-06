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

bool sameParent(Node* root, ll a, ll b){
    if(!root) return false;

    if(root->left and root->right){
        // if any root's left=a, right=b or left=b, right=a then they're from same parent
        if(root->left->data==a and root->right->data==b) return true;
        if(root->left->data==b and root->right->data==a) return true;
    }

    return sameParent(root->left,a,b) or sameParent(root->right,a,b);  // if root's any subtree (left or right) given true then they're from same parent
}

bool isCousin(Node* root, ll a, ll b){
    // checking both are same level or not
    queue<Node*>q;
    q.push(root);
    ll level = 0;
    ll l1 = -1, l2 = -1;
    while(!q.empty()){
        ll lvlsz = q.size();
        for(int i=0; i<lvlsz; i++){
            Node* curr = q.front();
            q.pop();
            // checking l1 & l2
            if(curr->data==a) l1 = level;
            if(curr->data==b) l2 = level;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        if(l1!=-1 and l2!=-1) break;   // both found at same level

        // if one is found & other is not at this level, they can't be cousins cause they are in different level
        if((l1!=-1 and l2==-1) or (l1==-1 and l2!=-1)) return false;
        level++;
    }

    // If both found at same level, check if they have different parents
    if(l1!=-1 and l2!=-1 and l1==l2){
        return !sameParent(root, a, b);  // if a,b has same parent (return 1) then they are not cousin that why ! here, it turns (return 0)
    }
    return false;  
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

    ll a,b;  // node 1, node 2
    cin>>a>>b;
    if(isCousin(root, a, b)) cout<<"YES\n";
    else cout<<"NO\n";
}

// TC: O(n)
