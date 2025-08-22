#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e5+1234;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

ll vis[8][8];
ll lvl[8][8];

ll getX(string s){  // x coordinates are char, it will converts in int and end up with string
    return s[0]-'a';
}

ll getY(string s){  // y coordinates are int, it will end up with string
    return s[1]-'1';
}

bool isValid(ll x, ll y){
    return x>=0 and y>=0 and x<8 and y<8;
}

vector<pair<ll,ll>> movements = {
    {-1, 2}, {1, 2},
    {-1, -2}, {1, -2},
    {2, -1}, {2, 1},
    {-2, -1}, {-2, 1},
};

ll bfs(string source, string dest){
    ll sourceX = getX(source);
    ll sourceY = getY(source);
    ll destX = getX(dest);
    ll destY = getY(dest);
    queue<pair<ll,ll>>q;   // {x,y}
    q.push({sourceX, sourceY});
    vis[sourceX][sourceY] = 1;
    lvl[sourceX][sourceY] = 0;

    while(!q.empty()){
        pair<ll,ll> curr_v = q.front();
        ll x = curr_v.first, y = curr_v.second;
        q.pop();
        for(auto movement:movements){
            ll childX = movement.first + x;
            ll childY = movement.second + y;
            if(!isValid(childX, childY)) continue;
            if(!vis[childX][childY]){
                q.push({childX, childY});
                lvl[childX][childY] = lvl[x][y] + 1;
                vis[childX][childY] = 1;
            }
        }
        if(lvl[destX][destY] != INF) break;
    }
    return lvl[destX][destY];
}

void reset(){  // for multiple tc and its 2d/matrix thats why reset is neccesary
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            vis[i][j] = 0;
            lvl[i][j] = INF;
        }
    }
}

int main(){
    FASTER;

    ll t;
    cin>>t;
    while(t--){
        reset();
        string s1, s2;
        cin>>s1>>s2;
        cout<<bfs(s1, s2)<<nl;
    }
}
