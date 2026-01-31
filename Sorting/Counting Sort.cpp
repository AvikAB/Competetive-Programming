#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define nl "\n"
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e5+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

int main(){
    FASTER

    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    ll mx = *max_element(v.begin(), v.end());
    vector<ll>freq(mx+1);
    for(auto av:v){
        freq[av]++;
    }
    ll idx = 0;
    for(int i=0; i<=mx; i++){
        while(freq[i]>0){
            v[idx++] = i;
            freq[i]--;
        }
    }
    for(auto av:v){
        cout<<av<<" ";
    }
    cout<<nl;
}
