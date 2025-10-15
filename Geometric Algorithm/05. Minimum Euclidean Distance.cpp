// Solved using Sweep Line Algorithm:

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

ll distSq(ll x1, ll y1, ll x2, ll y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
    FASTER

    ll n;
    cin>>n;
    vector<pair<ll,ll>> points(n);
    for(int i=0; i<n; i++){
        cin>>points[i].first>>points[i].second;  // {x,y}
    }
    // sort by x-coordinate
    sort(points.begin(), points.end());
    // active points stored as {y,x}
    set<pair<ll,ll>> active;
    ll mnDist = LLONG_MAX;
    ll left = 0;
    for(int i=0; i<n; i++){
        ll x = points[i].first;
        ll y = points[i].second;
        ll d = ceil(sqrt((long double)mnDist));  // current distance area
        // remove points too far in x (x er durer point gula remove korbe)
        while(points[i].first-points[left].first>d){
            active.erase({points[left].second, points[left].first}); // remove {y,x}
            left++;
        }

        // find candidates in y range (y-d, y+d)
        auto lower = active.lower_bound({y-d, LLONG_MIN});
        auto upper = active.upper_bound({y+d, LLONG_MAX});

        // check nearby points
        for(auto it=lower; it!=upper; it++){
            ll xx = it->second, yy = it->first;  // beacuse of {y, x}
            mnDist = min(mnDist, distSq(x,y,xx,yy));
        }
        active.insert({y,x});  // add current point
    }
    cout<<mnDist<<nl;
}



/*
How it works (simplified):
    1. Sort all points by x-coordinate.
    2. Use a set (sorted by y) to keep only recent points near the current x.
    3. For each point, only compare with points close in x and y — others are ignored.
    4. Update the minimum squared distance (minDist) as you go.
*/
