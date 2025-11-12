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

int main(){
    ll n,r;
    cin>>n>>r;
    ll ans = 1;
    for(int i=1; i<=min(r, n-r); i++){
        ans = (ans*(n-i+1))/i;
    }
    cout<<ans<<nl;
}


// Time Comp: O(min(r, n-r))
