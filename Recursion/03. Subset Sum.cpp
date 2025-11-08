// Subset Sum (Direct Print):

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

void subsetSum(ll pos, vector<ll>&v, ll currSum){
    if(pos==v.size()){
        cout<<currSum<<nl;
        return;
    }
    subsetSum(pos+1, v, currSum+v[pos]);  // include
    subsetSum(pos+1, v, currSum);     // exclude
}

int main(){
    FASTER

    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    subsetSum(0,v,0);
}



// Subset Sum (store in a vector):

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

vector<ll>allSums;

void subsetSum(ll pos, vector<ll>&v, ll currSum){
    if(pos==v.size()){
        allSums.push_back(currSum);
        return;
    }
    subsetSum(pos+1, v, currSum+v[pos]);  // include
    subsetSum(pos+1, v, currSum);     // exclude
}

int main(){
    FASTER

    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    subsetSum(0,v,0);

    for(auto av:allSums){
        cout<<av<<" ";
    }
    cout<<nl;
}
