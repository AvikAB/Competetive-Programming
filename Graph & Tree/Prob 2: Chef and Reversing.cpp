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

vector<pair<ll,ll>>adjList[N];
vector<ll>lvl(N, -1);
ll n,m;

ll bfs(){
    deque<ll>dq;
    dq.push_back(1);
    lvl[1] = 0;

    while(!dq.empty()){
        ll curr_v = dq.front();
        dq.pop_front();
        for(auto child:adjList[curr_v]){
            ll child_v = child.first;
            ll wt = child.second;
            if(lvl[child_v] == -1 or lvl[curr_v]+wt < lvl[curr_v]){
                lvl[child_v] = lvl[curr_v]+wt;
                if(wt==0) dq.push_front(child_v);
                else dq.push_back(child_v);
            }
        }
    }
    return lvl[n];
}

int main(){
    FASTER

    cin>>n>>m;
    for(int i=0; i<m; i++){
        ll x,y;
        cin>>x>>y;
        if(x==y) continue;   // self loop will skip
        adjList[x].push_back({y, 0});
        adjList[y].push_back({x, 1});    // reverse edge
    }

    cout<<bfs()<<nl;
}



// Input:
7 7
1 2 
3 2
3 4
7 4
6 2
5 6
7 5
// Output: 2
