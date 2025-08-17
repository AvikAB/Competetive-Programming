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

// edge deletion
ll subtreeSum[N];
ll val[N];
void dfs(ll vertex, ll par=0){
    subtreeSum[vertex] += val[vertex];
    for(ll child:adjList[vertex]){
        if(child==par) continue;
        dfs(child, vertex);
        subtreeSum[vertex] += subtreeSum[child];
    }
}

int main(){
    FASTER

    ll n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>val[i];
    }

    for(int i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // edge deletion
    dfs(1);
    ll ans = 0;
    for(int i=2; i<=n; i++){
        ll part1 = subtreeSum[i];   // directly got 1 subtree
        ll part2 = subtreeSum[1]-part1;   // totalSum - 1 subtreeSum = another SubtreeSum
        ans = max(ans, (part1*1LL*part2)%mod);
    }
    cout<<ans<<nl;
}
