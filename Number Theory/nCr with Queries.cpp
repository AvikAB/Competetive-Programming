#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 2e5+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;
ll fact[N+1], modinv[N+1];

ll bigmod(ll a,ll b,ll m){
    if(b==0) return 1%m;
    if(b%2==0){
        ll t = bigmod(a,b/2,m);
        return (1LL*t*t%m);
    } else {
        ll t = bigmod(a,(b-1)/2,m);
        t = (1LL*t*t)%m;
        return (1LL*a*t%m);
    }
}

void precomp(){
    fact[0] = 1;
    modinv[0] = 1;
    for(ll i=1; i<=N; i++){
        fact[i] = (fact[i-1]*i)%mod;
        modinv[i] = bigmod(fact[i], mod-2, mod);
    }
}

ll nCr(ll n, ll r){
    if(r>n or r<0 or n<0) return 0;
    ll numo = fact[n];
    ll invdeno = (modinv[r]*modinv[n-r]) % mod;
    ll ans = (numo * invdeno) % mod;
    return ans;
}

int main(){
    FASTER;

    precomp();
    ll q;
    cin>>q;
    while(q--){
        ll n,r;
        cin>>n>>r;
        cout<<nCr(n,r)<<nl;
    }
}
