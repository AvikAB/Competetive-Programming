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

ll orientation(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    ll val = ((y2-y1)*(x3-x2)) - ((y3-y2)*(x2-x1));
    if(val==0) return 0;
    return (val>0) ? 1:2;
}

bool ValidProjection(ll a, ll b, ll c, ll d){
    // a & c are starting point, b & d are ending point
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    return max(a,c) <= min(b,d);  // checking intersect
}

bool doIntersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){
    ll o1 = orientation(x1,y1, x2,y2, x3,y3);
    ll o2 = orientation(x1,y1, x2,y2, x4,y4);
    ll o3 = orientation(x3,y3, x4,y4, x1,y1);
    ll o4 = orientation(x3,y3, x4,y4, x2,y2);
    if(o1!=o2 and o3!=o4) return true;
    if(o1==0 and o4==0){  // if they are linear then check that they are projection or not
        if(ValidProjection(x1,x2,x3,x4) and ValidProjection(y1,y2,y3,y4)) return true;
    }
    return false;
}

int main(){
    FASTER

    ll t;
    cin>>t;
    while(t--){
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        bool ans = doIntersect(x1,y1,x2,y2,x3,y3,x4,y4);
        if(ans==0) cout<<"NO\n";
        else cout<<"YES\n";
    }
}
