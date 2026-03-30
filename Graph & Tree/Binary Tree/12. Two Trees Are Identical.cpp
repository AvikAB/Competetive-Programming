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

bool isIdentical(Node* r1, Node* r2){
    // Base Cases:
    if(r1==NULL and r2==NULL) return true;  // if the nodes are leaf nodes or both are reached their end of tree
    if((!r1 or r2) and (r1 or !r2)) return false;    // if r1 present or r2 not or vice versa then its false
    if(r1->data != r2->data) return false;    // if both nodes are not equal then its false

    return isIdentical(r1->left, r2->left) and isIdentical(r1->right, r2->right);
}

int main(){
    // Build First Tree
    cout << "Build First Tree" << nl;
    ll x;
    cout << "Enter root value: ";
    cin >> x;
    
    queue<Node*> q1;
    Node *root1 = new Node(x);
    q1.push(root1);

    // Build the first binary tree
    while(!q1.empty()){
        Node *temp = q1.front();
        q1.pop();

        // Left child
        cout << "Enter left child of " << temp->data << " (enter -1 for NULL): ";
        ll first;
        cin >> first;
        if(first != -1){
            temp->left = new Node(first);
            q1.push(temp->left);
        }

        // Right child
        cout << "Enter right child of " << temp->data << " (enter -1 for NULL): ";
        ll second;
        cin >> second;
        if(second != -1){
            temp->right = new Node(second);
            q1.push(temp->right);
        }
    }
    cout << "First Tree Successfully Created!" << nl;
    
    // Build Second Tree
    cout << nl << "Build Second Tree" << nl;
    cout << "Enter root value: ";
    cin >> x;
    
    queue<Node*> q2;
    Node *root2 = new Node(x);
    q2.push(root2);

    // Build the second binary tree
    while(!q2.empty()){
        Node *temp = q2.front();
        q2.pop();

        // Left child
        cout << "Enter left child of " << temp->data << " (enter -1 for NULL): ";
        ll first;
        cin >> first;
        if(first != -1){
            temp->left = new Node(first);
            q2.push(temp->left);
        }

        // Right child
        cout << "Enter right child of " << temp->data << " (enter -1 for NULL): ";
        ll second;
        cin >> second;
        if(second != -1){
            temp->right = new Node(second);
            q2.push(temp->right);
        }
    }
    cout << "Second Tree Successfully Created!" << nl;
    
    // Compare Trees
    cout << boolalpha << isIdentical(root1, root2) << nl;
}
