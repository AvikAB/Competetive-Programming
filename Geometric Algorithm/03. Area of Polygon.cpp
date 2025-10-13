// Using structure and double:

#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x;
    double y;
};

double cross_product(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}

double area(Point vertices[], int n){
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += cross_product(vertices[i], vertices[(i + 1) % n]);
    }
    return fabs(sum) / 2.0;
}

int main(){
    int n;
    cin >> n;
    Point vertices[n];
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].x >> vertices[i].y;
    }
    double a = area(vertices, n);
    cout<<a<<endl;
}


// CSES Problem: https://cses.fi/problemset/task/2191

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
    FASTER

    ll n;
    cin>>n;
    vector<pair<ll,ll>> points;
    for(int i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
        ll x1 = points[i].first, y1 = points[i].second;
        ll x2 = points[(i+1)%n].first, y2 = points[(i+1)%n].second;
        ans += ((x1*y2)-(y1*x2));    // it gives 2*area
    }
    cout<<abs(ans)<<nl;
}
