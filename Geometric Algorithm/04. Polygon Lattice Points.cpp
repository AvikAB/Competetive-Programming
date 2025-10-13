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

ll latticePointsOnSegXcludingEndPoints(pair<ll,ll>p1, pair<ll,ll>p2){
    // formula: gcd(|x2-x1|,|y2-y1|)-1
    ll a = abs(p1.first-p2.first);
    ll b = abs(p1.second-p2.second);
    return __gcd(a,b)-1;
}

ll AreaOfPolygon(vector<pair<ll,ll>>vertices){  // it gives 2*area
    ll n = vertices.size();
    ll ans = 0;
    for(int i=0; i<n; i++){
        ll x1 = vertices[i].first, y1 = vertices[i].second;
        ll x2 = vertices[(i+1)%n].first, y2 = vertices[(i+1)%n].second;
        ans += ((x1*y2)-(y1*x2));
    }
    return abs(ans);
}

int main(){
    FASTER

    ll n;
    cin>>n;
    vector<pair<ll,ll>> vertices;
    for(int i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        vertices.push_back({x,y});
    }
    ll boundary = 0;
    for(int i=0; i<n; i++){
        pair<ll,ll> p1 = vertices[i];  // point1 -> {x,y}
        pair<ll,ll> p2 = vertices[(i+1)%n];  // point2 -> {x,y}, % for cyclic
        boundary += latticePointsOnSegXcludingEndPoints(p1, p2);
    }
    boundary += n;   // given n points are also lattice points in boundary
    ll area = AreaOfPolygon(vertices)/2;   // 2*area/2 = area

    // picks theorem: area = i+(boundary/2)-1,  i->inside lattice point
    //             or,   i = area-(boundary/2)+1

    cout<<(area-(boundary/2)+1)<<" "<<boundary<<nl;
}
