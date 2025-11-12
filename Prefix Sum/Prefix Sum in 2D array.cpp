#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1010;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

ll ar[N][N];
ll pf[N][N];

int main(){
    FASTER

    ll n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>ar[i][j];
            pf[i][j] = ar[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
        }
    }
    ll q; cin>>q;
    while(q--){
        ll a,b,c,d;  // x1,y1,x2,y2
        cin>>a>>b>>c>>d;
        cout<<pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1]<<nl;
    }
}
