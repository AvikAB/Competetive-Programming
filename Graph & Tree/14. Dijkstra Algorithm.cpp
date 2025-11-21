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

vector<pair<ll,ll>> adjList[N];   // {node, weight}

vector<ll> dijkstra(ll source){
    vector<ll> vis(N, 0);
    vector<ll> dist(N, INF);
    set<pair<ll,ll>> st;     // {dist, node} -> dist first because we want to sort for distance
    st.insert({0, source});
    dist[source] = 0;

    while(st.size()>0){
        auto node = *st.begin();
        ll v = node.second;    // vertex
        ll v_dist = node.first;  // distance of vertex
        st.erase(st.begin());
        if(vis[v]) continue;   // skip the visited node
        vis[v] = 1;
        for(auto child:adjList[v]){
            ll child_v = child.first;   // v er child er node no.
            ll wt = child.second;
            if(dist[v]+wt < dist[child_v]){      // dist[child_v] -> current distance
                dist[child_v] = dist[v] + wt;    // updated distance
                st.insert({dist[child_v], child_v});    // take it into the set as {dis, node}
            }
        }
    }
    return dist;
}

int main(){
    FASTER

    ll n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        ll x,y,wt;
        cin>>x>>y>>wt;
        adjList[x].push_back({y, wt});
    }
    ll source;
    cin>>source;
    vector<ll>dist = dijkstra(source);
    for(int i=1; i<=n; i++){
        if(dist[i]==INF) cout<<"INF ";
        else cout<<dist[i]<<" ";
    }
    cout<<nl;
}



/*
// Traverse all nodes from source and print their distance.
Inputs:
  4 3
  2 1 1
  2 3 1
  3 4 1
  2  -> source node

Output: 1 0 1 2
*/
