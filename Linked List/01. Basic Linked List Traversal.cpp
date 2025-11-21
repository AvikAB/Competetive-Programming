#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e5+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

struct Node {
    public:
        int data;
        Node* next;

    public:
        // constructor with default next = nullptr
        Node (int data1, Node* next1=nullptr){
            data = data1;
            next = next1;
        }
};

int main(){
    FASTER

    vector<int>arr = {2,5,8,7};
    // create head node
    Node* head = new Node(arr[0], nullptr);
    Node* temp = head;
    // link the rest
    for(int i=1; i<arr.size(); i++){
        temp -> next = new Node(arr[i]);
        temp = temp -> next;
    }
    // print the linked list
    temp = head;
    while(temp != nullptr){
        cout<<temp -> data << " ";
        temp = temp -> next;
    }
    cout<<nl;
}




// Using Custom Print Function:

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e5+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

struct Node {
    public:
        int data;
        Node* next;

    public:
        // constructor with default next = nullptr
        Node (int data1, Node* next1=nullptr){
            data = data1;
            next = next1;
        }
};

Node* convertArr2LL(vector<ll>&arr){
    Node* head = new Node (arr[0]);   // create a head node of first ele
    Node* mover = head;   // head as a mover
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node (arr[i]);   // create temp node for curr ele
        mover -> next = temp;    // link pointer to the temp node
        mover = temp; 
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<nl;
}

int main(){
    FASTER

    vector<ll>arr = {12,5,8,7};
    Node* head = convertArr2LL(arr);
    print(head);
}
