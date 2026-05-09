// Method 1:

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

void find(Node* root, ll pos, ll &l, ll &r){
    if(!root) return;   // base case
    l = min(l, pos);   // gives min val of indexing
    r = max(r, pos);  // gives max val of indexing
    find(root->left, pos-1, l, r);
    find(root->right, pos+1, l, r);
}

vector<ll>verticalOrder(Node* root){
    if(!root) return {};
    ll l=0, r=0;
    find(root, 0, l, r);  // l & r will give min & max val of indexing
    vector<vector<ll>>positive(r+1);
    vector<vector<ll>> negative(abs(l)+1);

    queue<Node*>q;
    queue<ll>idx;
    q.push(root);
    idx.push(0);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        ll pos = idx.front();
        idx.pop();
        if(pos>=0) positive[pos].push_back(curr->data);
        else negative[abs(pos)].push_back(curr->data);

        if(curr->left){
            q.push(curr->left);
            idx.push(pos-1);
        }
        if(curr->right){
            q.push(curr->right);
            idx.push(pos+1);
        }
    }

    vector<ll>ans;
    // negative in descending order
    for(int i=negative.size()-1; i>0; i--){
        for(int j=0; j<negative[i].size(); j++){
            ans.push_back(negative[i][j]);
        }
    }

    // positive in ascending order
    for(int i=0; i<positive.size(); i++){
        for(int j=0; j<positive[i].size(); j++){
            ans.push_back(positive[i][j]);
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

    vector<ll>res = verticalOrder(root);
    for(auto av:res){
        cout<<av<<" ";
    }
    cout<<nl;
}


// TC: O(n)
// SC: O(n)

// Method 2: Using map
class Solution {
public:
    vector<vector<ll>> verticalTraversal(Node* root) {
        map<ll, map<ll, multiset<ll>>> nodes;
        queue<pair<Node*, pair<ll, ll>>> q;  // this is for BFS (level order traversal)
        q.push({root, {0, 0}});
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            Node* curr = p.first;  // node
            ll vertical_line = p.second.first;  // col
            ll level = p.second.second;  // row
            
            nodes[vertical_line][level].insert(curr->data);

            if(curr->left) {
                q.push({curr->left, {vertical_line - 1, level + 1}});
            }
            if(curr->right) {
                q.push({curr->right, {vertical_line + 1, level + 1}});
            }
        }
        
        vector<vector<ll>> ans;
        for(auto line_entry : nodes) {
            vector<ll> vertical_nodes;
            // for each level in this vertical line from top to bottom
            for(auto level_entry : line_entry.second) {
                // add all vals at this (vertical_line, level) position
                vertical_nodes.insert(vertical_nodes.end(), level_entry.second.begin(), level_entry.second.end());
            }
            // add this vertical line to final ans
            ans.push_back(vertical_nodes);
        }
        return ans;
    }
};

// TC: O(nlogn)
// SC: O(n)
