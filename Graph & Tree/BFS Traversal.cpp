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
ll level[N];

void bfs(ll source){
    queue<ll>q;
    q.push(source);
    vis[source] = 1;

    while(!q.empty()){
        ll curr_v = q.front();
        q.pop();
        cout<<curr_v<<" ";   // for print the nodes
        for(ll child:adjList[curr_v]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[curr_v]+1;
            }
        }
    }
    cout<<nl;
}

int main(){
    FASTER

    ll n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        ll u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bfs(1);
    for(int i=1; i<=n; i++){
        cout<<i<<": "<<level[i]<<nl;
    }
}
