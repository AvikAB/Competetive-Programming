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

// Pre-computation using DFS:
// Subtree Sum & Even or Odd Count for each Node (val will be their node num):

ll subtreeSum[N], evnCnt[N];
void dfs(ll vertex, ll par=0){
    if(vertex%2==0) evnCnt[vertex]++;
    subtreeSum[vertex] += vertex;
    for(ll child:adjList[vertex]){
        if(child==par) continue;
        dfs(child, vertex);
        subtreeSum[vertex] += subtreeSum[child];
        evnCnt[vertex] += evnCnt[child];
    }
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

    dfs(1);  // precomputation for subtreeSum & evnCnt
    for(int i=1; i<=n; i++){
        cout<<subtreeSum[i]<<" "<<evnCnt[i]<<nl;
    }
}
