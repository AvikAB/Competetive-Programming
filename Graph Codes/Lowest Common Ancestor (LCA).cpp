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

vector<ll> adjList[N];
ll parent[N];

void dfs(ll vertex, ll par=-1){
    parent[vertex] = par;
    for(ll child:adjList[vertex]){
        if(child==par) continue;
        dfs(child, vertex);
    }
}

vector<ll>path(ll v){   // this will store the path
    vector<ll>ans;
    while(v!=-1){  // in dfsTree root node was -1
        ans.push_back(v);
        v = parent[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    FASTER

    ll n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1);
    ll x,y;
    cin>>x>>y;
    vector<ll> path_x = path(x);
    vector<ll> path_y = path(y);
    ll mnLen = min(path_x.size(), path_y.size());
    ll lca = -1;
    for(int i=0; i<mnLen; i++){
        if(path_x[i]==path_y[i]) lca = path_x[i];
        else break;
    }
    cout<<lca<<nl;
}
