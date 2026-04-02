// Binary Tree

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

vector<ll>spiral(Node* root){
    if(!root) return {};
    
    stack<Node*>RL;
    stack<Node*>LR;
    RL.push(root);
    vector<ll>ans;
    while(!RL.empty() or !LR.empty()){
        if(!RL.empty()){    // RL is not empty then take RL ele's child to LR
            while(!RL.empty()){
                Node* curr = RL.top();
                RL.pop();
                ans.push_back(curr->data);   // push the current node in ans
                
                // if right is present of curr then store it in LR in Right to Left order, thats why Right first & then left
                if(curr->right) LR.push(curr->right);
                if(curr->left) LR.push(curr->left);
            }
        } else {    // LR is not empty then process it in same way
            while(!LR.empty()){
                while(!LR.empty()){
                    Node* curr = LR.top();
                    LR.pop();
                    ans.push_back(curr->data);

                    // if left is present of curr then store it in RL in Left to Right order,
                    if(curr->left) RL.push(curr->left);
                    if(curr->right) RL.push(curr->right);
                }
            }
        }
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

    vector<ll> res = spiral(root);
    for(auto av:res){
        cout<<av<<" ";
    }
    cout<<nl;
}
