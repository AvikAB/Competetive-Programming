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
bool vis[N];

bool dfsCycle(ll vertex, ll par){
    vis[vertex] = true;
    for(ll child : adjList[vertex]){
        if(vis[child]){
            if(child != par) return true;
            continue;
        }
        if(dfsCycle(child, vertex)) return true;
    }
    return false;
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

    // cycle detection:
    bool isCycle = false;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfsCycle(i, 0)){
                isCycle = true;
                break;
            }
        }
    }
    cout<<isCycle<<nl;
    
}
