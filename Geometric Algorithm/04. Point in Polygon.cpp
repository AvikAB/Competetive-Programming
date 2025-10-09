// Problem Link: https://cses.fi/problemset/task/2192/

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
    ll val = (y2-y1)*(x3-x2) - (x2-x1)*(y3-y2);
    if(val>0) return 1;  // clockwise
    else if(val<0) return 2;   // anti-clockwise
    else return 0;  // linear
}

bool onSeg(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    return (x3<=max(x1,x2) and x3>=min(x1,x2) and y3<=max(y1,y2) and y3>=min(y1,y2));
}

bool intersect(pair<ll,ll>a, pair<ll,ll>b, pair<ll,ll>c, pair<ll,ll>d){
    ll x1=a.first, y1=a.second, x2=b.first, y2=b.second, x3=c.first, y3=c.second, x4=d.first, y4=d.second;
    ll o1 = orientation(x1,y1,x2,y2,x3,y3);
    ll o2 = orientation(x1,y1,x2,y2,x4,y4);
    ll o3 = orientation(x3,y3,x4,y4,x1,y1);
    ll o4 = orientation(x3,y3,x4,y4,x2,y2);
    if(o1!=o2 and o3!=o4) return true;
    else return false;
}

int main(){
    FASTER

    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>vertices;
    for(int i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        vertices.push_back({x,y});
    }
    vector<pair<ll,ll>>points;
    for(int i=0; i<m; i++){
        ll x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }
    for(auto currPoints: points){
        pair<ll,ll> endPoints = {INF, currPoints.second+1};  // horizontal ray, horizontal line from that currentPoints
        ll intersectionCnt = 0;
        bool boundary = false;
        for(int i=0; i<n; i++){
            pair<ll,ll> a = vertices[i];
            pair<ll,ll> b = vertices[(i+1)%n];
            if(orientation(a.first, a.second, b.first, b.second, currPoints.first, currPoints.second)==0 and onSeg(a.first, a.second, b.first, b.second, currPoints.first, currPoints.second)){
                boundary = true;  // check that the points on line touch or not
                break;
            }
            if(intersect(a,b,currPoints,endPoints)) intersectionCnt++;
        }
        if(boundary) cout<<"BOUNDARY\n";
        else if(intersectionCnt%2) cout<<"INSIDE\n";
        else cout<<"OUTSIDE\n";
    }
}
