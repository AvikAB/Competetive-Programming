#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e3+10;
const ll mod = 1e9+7;

ll n,m;
ll val[N][N];
ll lvl[N][N];
ll vis[N][N];

vector<pair<ll,ll>> movements = {    // lets say (x,y) -> x = movements.first, y = movements.second
    {0, 1}, {0,-1}, {1,0}, {-1,0},    // side
    {1,1}, {-1,-1}, {1,-1}, {-1,1}   // diagonal or corner
};

bool isValid(int i, int j){
    return i>=0 and j>=0 and i<n and j<m;
}

ll bfs(){
    // find all maximum cell
    ll mx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mx = max(mx, val[i][j]);
        }
    }
    // start bfs with the all mxs nodes
    queue<pair<ll,ll>>q;    // {x,y}
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mx==val[i][j]){
                q.push({i, j});    // store the coordinates of mx's
                lvl[i][j] = 0;    // all mxs node will be 0 level
                vis[i][j] = 1;
            }
        }
    }
    ll ans = 0;
    while(!q.empty()){
        auto v = q.front();
        ll v_x = v.first;
        ll v_y = v.second;
        q.pop();
        for(auto movement:movements){
            // checking for side and corner cell
            ll child_x = movement.first + v_x;
            ll child_y = movement.second + v_y;
            if(!isValid(child_x, child_y)) continue;
            if(vis[child_x][child_y]) continue;
            q.push({child_x, child_y});
            lvl[child_x][child_y] = lvl[v_x][v_y]+1;  // parent vertex's level + 1
            vis[child_x][child_y] = 1;
            ans = max(ans, lvl[child_x][child_y]);
        }
    }
    return ans;
}

void reset(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j] = 0;
            lvl[i][j] = -1;
        }
    }
}

int main(){
    FASTER

    ll t;
    cin>>t;
    while(t--){
        reset();
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>val[i][j];
            }
        }
        cout<<bfs()<<nl;
    }
}
