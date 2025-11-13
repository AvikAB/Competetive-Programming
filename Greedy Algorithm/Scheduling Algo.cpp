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

bool cmp(vector<ll>&a, vector<ll>&b){
    return a[1]<b[1];
}

int main(){
    FASTER

    ll n;
    cin>>n;
    vector<vector<ll>>v(n, vector<ll>(2));
    for(int i=0; i<n; i++){
        cin>>v[i][0]>>v[i][1];
    }
    sort(v.begin(), v.end(), cmp);
    ll ans = 0, freeAt = 0;
    for(int i=0; i<n; i++){
        if(freeAt <= v[i][0]){
            ans++;
            freeAt = v[i][1];
        }
    }
    cout<<ans<<nl;
}

// TC: O(n log n)

/*
Inputs:
5
1 3
2 5
4 7
6 9
8 10
*/
