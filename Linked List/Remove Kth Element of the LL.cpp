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

Node* removeK(Node* head, int k){
    if(head == NULL) return head;
    if(k==1){
        Node* temp = head;   // store head in temp
        head = head->next;  // move head to the next node
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){  // traversal
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            delete temp;  // delete current node which is k
            break; 
        }
        prev = temp;   // curr node will be prev & then it move right or move to the next node
        temp = temp->next;  // move to the next node==
    }
    return head;
}

int main(){
    FASTER

    vector<ll>arr = {12,5,8,7};
    Node* head = convertArr2LL(arr);
    print(head);
    head = removeK(head, 3);
    cout<<"After Kth Deletion: ";
    print(head);
}
