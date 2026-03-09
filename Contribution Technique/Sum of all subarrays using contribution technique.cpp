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

void solve(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    ll sum = 0;
    for(int i=0; i<n; i++){
        ll c = (i+1)*(n-i);
        sum += (c*v[i]);
    }
    cout<<sum<<nl;
}

int main(){
    FASTER
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}




/* Inputs:
1
4
1 2 3 4

Output: 50
*/


/*
Calculating Contribution:
The number of subarray that include A[i] and start before or at A[i]: (i+1).

The number of subarrays that include A[i] and end after or at A[i]: (n−i), where n is the length of the array.

The total number of subarrays that include A[i] is the product of the two counts above: (i+1)×(n−i).

The sum of all subarrays will be (summation of i=0 to n-1) A[i]*(i+1)*(n-i).
*/
