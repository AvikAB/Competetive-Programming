// Generate Subsequence (Direct Print):

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

void subSeq(vector<ll>&v, ll pos, vector<ll>&curr){
    if(pos==v.size()){
        for(auto av:curr){
            cout<<av<<" ";
        }
        cout<<nl;
        return;
    }
    curr.push_back(v[pos]);  // include
    subSeq(v, pos+1, curr);
    curr.pop_back();   // exclude (backtrack)
    subSeq(v, pos+1, curr);
}

int main(){
    FASTER

    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<ll>curr;
    subSeq(v, 0, curr);
}


// Generate subsequence (store in a vector):

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

vector<vector<ll>>res;

void subSeq(vector<ll>&v, ll pos, vector<ll>&curr){
    if(pos==v.size()){
        res.push_back(curr);
        return;
    }
    curr.push_back(v[pos]);  // include
    subSeq(v, pos+1, curr);
    curr.pop_back();   // exclude (backtrack)
    subSeq(v, pos+1, curr);
}

int main(){
    FASTER

    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<ll>curr;
    subSeq(v, 0, curr);
    for(auto subsequence:res){
        for(auto av:subsequence){
            cout<<av<<" ";
        }
        cout<<nl;
    }
}

// Subsequence Generate using string:

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

void subSeq(string res, ll pos, string s){
    if(pos==s.size()){
        cout<<res<<nl;
        return;
    }
    subSeq(res, pos+1, s);  // exclude
    res = res+s[pos];  // include
    subSeq(res, pos+1, s);
}

int main(){
    FASTER

    ll n;
    cin>>n;
    string s;
    cin>>s;
    string res="";
    subSeq(res, 0, s);
}
