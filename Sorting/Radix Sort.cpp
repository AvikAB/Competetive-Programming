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

void countSort(vector<ll>&v, ll exp){
    ll n = v.size();
    vector<ll>ans(n);
    ll cnt[10] = {0};  // count array for 0 to 9 digits with zero value
    // count occurence
    for(int i=0; i<n; i++){
        cnt[(v[i]/exp)%10]++;
    }
    // Cumulative Count
    for(int i=1; i<10; i++){
        cnt[i] += cnt[i-1];
    }
    // Build output array
    for(int i=n-1; i>=0; i--){
        ans[cnt[(v[i]/exp)%10]-1] = v[i];
        cnt[(v[i]/exp)%10]--;
    }

    for(int i=0; i<n; i++){
        v[i] = ans[i];
    }
}

void radixSort(vector<ll>&v){
    if(v.empty()) return;
    ll mx = *max_element(v.begin(), v.end());
    // Do counting sort for every digit place
    for(ll exp=1; mx/exp>0; exp*=10){
        countSort(v, exp);
    }
}

int main(){
    FASTER

    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    radixSort(v);
    for(auto av:v){
        cout<<av<<" ";
    }
    cout<<nl;
}
