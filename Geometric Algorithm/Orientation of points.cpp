// Problem: Given 3 points (a,b,c) in 2D space. Find out orientation (colinear, clockwise, anti-clockwise) of points a,b,c.

// CSES Poin Location Test: https://cses.fi/problemset/task/2190

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

    ll t;
    cin>>t;
    while(t--){
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        ll val = ((y2-y1)*(x3-x2)) - ((y3-y2)*(x2-x1));
        if(val==0) cout<<"TOUCH\n";
        else if(val<0) cout<<"LEFT\n";
        else cout<<"RIGHT\n";
    }
}


/*
The formula is: slope of ab - slope of bc = (y2-y1)/(x2-x1) - (y3-y2)/(x3-x2)
                                          = (y2-y1)*(x3-x2) - (y3-y2)*(x2-x1)
If that val < 0 -> Anti-Clockwise
If that val > 0 -> Clockwise
If that val = 0 -> Co-linear
*/
