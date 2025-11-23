// Backtrack Related
// Generate Permutation (directly print):

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

void permute(string s, ll pos){
    ll len = s.size();
    if(pos==len-1){
        cout<<s<<nl;
        return;
    }
    for(int i=pos; i<len; i++){
        swap(s[pos], s[i]);
        permute(s, pos+1);
        swap(s[pos], s[i]);   // backtrack
    }
}

int main(){
    FASTER;
    
    string s;
    cin>>s;
    permute(s,0);
}


// Using Vector: for store it:

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

vector<vector<ll>>allPermute;

void permute(vector<ll>&v, ll pos){
    ll len = v.size();
    if(pos==len-1){
        allPermute.push_back(v);
        return;
    }
    for(int i=pos; i<len; i++){
        swap(v[pos], v[i]);
        permute(v, pos+1);
        swap(v[pos], v[i]);   // backtrack
    }
}

int main(){
    FASTER;

    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    permute(v,0);
    for(auto per:allPermute){
        for(auto av:per){
            cout<<av<<" ";
        }
        cout<<nl;
    }
}
