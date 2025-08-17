///  Modular Arithmatic

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll N = 1e7+1234;
const ll mod = 1e9+7;

int mod_add(int a, int b, int m){
    return (a%m + b%m)%m;
}

int mod_sub(int a, int b, int m){
    return (a%m - b%m + m)%m;
}

int mod_mul(int a, int b, int m){
    return (a%m * b%m)%m;
}

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

int power(int a, int b){
    if(b==0) return 1;
    if(b%2==0){
        int t = power(a,b/2);
        return (1LL*t*t);
    } else {
        int t = power(a,(b-1)/2);
        t = (1LL*t*t);
        return (1LL*a*t);
    }
}

int main(){
    FASTER

    // modular inverse:
    // ll a,b,m;
    // cin>>a>>b>>m;
    // ll inv_b = bigmod(b, m-2, m);   // Fermat's little theorem
    // ll res = (a*inv_b)%m;
    // cout<<res<<nl;

    ll a,b,m;
    cin>>a>>b>>m;
    cout<<mod_add(a,b,m)<<nl;
}
