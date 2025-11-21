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

void dfs(ll vertex, ll par=0){
    // 1st Step: Take action on vertex after entering the vertex
    vis[vertex] = true;
    for(ll child : adjList[vertex]){
        // 2nd Step: Take action on child before entering the child node
        if(!vis[child]){
            dfs(child, vertex);
        }
        //3rd Step: Take action on child after entering the child node
    }
    // 4th Step: Take action on vertex before exiting the vertex
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

    // component count:
    ll cnt = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, 0);
            cnt++;
        } else continue;
    }
    cout<<cnt<<nl;
}
