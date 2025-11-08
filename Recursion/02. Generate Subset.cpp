/// Direct Printing:

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

ll arr[100];

void subset(ll n, ll pos, string res=""){
    if(pos==n){
        cout<<res<<nl;
        return;
    }
    subset(n, pos+1, res+" "+to_string(arr[pos]));   // include
    subset(n, pos+1, res);   // exclude
}

int main(){
    FASTER;

    ll n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    subset(n,0);
}


/// Ussing vector:

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

ll arr[100];
ll n;

void subset(ll pos, vector<ll>res){
    if(pos==n){
        for(auto av:res){
            cout<<av<<" ";
        }
        cout<<nl;
        return;
    }
    res.push_back(arr[pos]);  // include
    subset(pos+1, res);
    res.pop_back();       // exclude (backtrack) 
    subset(pos+1, res);
}

int main(){
    FASTER;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<ll>v;
    subset(0, v);
}

/// Using vector to store the all subsets:

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

ll n;
vector<vector<ll>>res;   // need 2d vector to store

void subset(ll pos, vector<ll>&v, vector<ll>&curr){
    if(pos==n){
        res.push_back(curr);
        return;
    }
    curr.push_back(v[pos]);  // include
    subset(pos+1, v, curr);
    curr.pop_back();       // exclude (backtrack) 
    subset(pos+1, v, curr);
}

int main(){
    FASTER;

    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<ll>curr;   // track the current subset
    subset(0, v, curr);
    for(auto subs:res){
        for(auto av:subs){
            cout<<av<<" ";
        }
        cout<<nl;
    }
}
