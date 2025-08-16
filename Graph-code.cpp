#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e3+1234;
const ll mod = 1e9+7;

vector<ll> adjList[N];
bool vis[N];

void dfsTraverse(ll vertex){
    // 1st Step: Take action on vertex after entering the vertex
    vis[vertex] = true;
    cout<<vertex<<" ";
    for(ll child : adjList[vertex]){
        // 2nd Step: Take action on child before entering the child node
        if(!vis[child]){
            dfsTraverse(child);
        }
        //3rd Step: Take action on child after entering the child node
    }
    // 4th Step: Take action on vertex before exiting the vertex
}

bool dfsCycle(ll vertex, ll par){
    vis[vertex] = true;   // this step is must for basic dfs traversal
    //cout<<"Visited: "<<vertex<<nl;
    for(ll child : adjList[vertex]){
        //cout<<"par: "<<vertex<<", Child: "<<child<<nl;
        if(vis[child]){
            if(child != par) return true;
            continue;
        }
        if(dfsCycle(child, vertex)) return true;
    }
    return false;
}

ll depth[N], height[N];
void dfs(ll vertex, ll par=0){
    for(ll child:adjList[vertex]){
        if(child==par) continue;
        depth[child] = depth[vertex]+1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child]+1);
    }
}

// Pre-computation using DFS:
// Subtree Sum & Even or Odd Count for each Node:
ll subtreeSum[N], evnCnt[N];
void dfs2(ll vertex, ll par=0){
    if(vertex%2==0) evnCnt[vertex]++;
    subtreeSum[vertex] += vertex;
    for(ll child:adjList[vertex]){
        if(child==par) continue;
        dfs2(child, vertex);
        subtreeSum[vertex] += subtreeSum[child];
        evnCnt[vertex] += evnCnt[child];
    }
}

// This is for find the diameter 
void dfs3(ll vertex, ll par=-1){
    for(ll child:adjList[vertex]){
        if(child == par) continue;
        depth[child] = depth[vertex]+1;
        dfs3(child, vertex);
    }
}

// Lowest common ancestor (LCA):
ll parent[N];
void dfsTree(ll vertex, ll par=-1){
    parent[vertex] = par;
    for(ll child:adjList[vertex]){
        if(child==par) continue;
        dfsTree(child, vertex);
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
        adjList[v].push_back(u);  // when directed graph then it will remove
    }

    // cycle detection:
    bool isCycle = false;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(i, 0)){
                isCycle = true;
                break;
            }
        }
    }
    cout<<isCycle<<nl;

    // component count:
    ll cnt = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, 0);
            cnt++;
        } else continue;
    }
    cout<<cnt<<nl;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cout<<"Starting at: "<<i<<nl;
            dfs(i);
        }
    }
    
    
    cout<<"start ->"<<" ";
    dfsTraverse(1);
    cout<<nl;
    dfs(1);
    for(int i=1; i<=n; i++){
        cout<<depth[i]<<" "<<height[i]<<nl;
    }
    
    dfs2(1);  // precomputation for subtreeSum & evnCnt
    for(int i=1; i<=n; i++){
        cout<<subtreeSum[i]<<" "<<evnCnt[i]<<nl;
    }

    
    // Find the diameter of a tree
    dfs3(1);
    ll mx_depth = -1;
    ll mx_depth_node;
    for(int i=1; i<=n; i++){
        if(mx_depth<depth[i]){
            mx_depth = depth[i];
            mx_depth_node = i;
        }
        depth[i] = 0;  // reset for 2nd time dfs
    }
    dfs(mx_depth_node);
    for(int i=1; i<=n; i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
        }
    }
    cout<<mx_depth<<nl;

    // Lowest common ancestor (LCA):
    dfsTree(1);
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
