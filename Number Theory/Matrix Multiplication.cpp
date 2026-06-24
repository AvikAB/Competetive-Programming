#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 101;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

ll ar[N][N], I[N][N];   // identity matrix (result)

void mul(ll A[N][N], ll B[N][N], ll n){
    // matrix multiplication here
    ll res[N][N] = {0};
    // A*B
    for(int i=1; i<=n; i++){   // row of matrix A
        for(int k=1; k<=n; k++){
            if(A[i][k]==0) continue;
            for(int j=1; j<=n; j++){   // col of mat B
                res[i][j] += (A[i][k] * B[k][j]) % mod;
            }
        }
    }

    // shift the res mat to main mat
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            A[i][j] = res[i][j];
        }
    }
}

void power(ll a[N][N], ll n, ll p){
    // create identity matrix
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) I[i][j] = 1;
            else I[i][j] = 0;
        }
    }

    while(p){
        if(p%2==1){
            mul(I, a, n);  // result in I
        }
        mul(a,a,n);
        p >>= 1;  // power = power/2
    }

    // copy result
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[i][j] = I[i][j];
        }
    }
}

void solve(){
    ll n,p;    // n = size, p = power
    cin>>n>>p;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>ar[i][j];
        }
    }
    power(ar, n, p);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<ar[i][j]<<" ";
        }
        cout<<nl;
    }
}

int main(){
    FASTER
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}


// TC: O(n^3 log p)
// SC: O(n^2)
