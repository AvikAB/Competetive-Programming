#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e7+1234;
const ll mod = 1e9+7;

char board[1000][1000];

bool isSafe(ll x, ll y, ll n){
    // for column
    for(int i=0; i<x; i++){
        if(board[i][y]=='Q') return false;
    }
    // for upper-right diagonal
    ll i = x, j = y;
    while(i>=0 and j<n){
        if(board[i][j]=='Q') return false;
        i--;
        j++;
    }
    // for upper-left diagonal
    i = x, j = y;
    while(i>=0 and j>=0){
        if(board[i][j]=='Q') return false;
        i--;
        j--;
    }
    return true;
}

void nQueen(ll row, ll n){
    if(row==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j];
            }
            cout<<nl;
        }
        cout<<nl;
        return;
    }
    for(int col=0; col<n; col++){  // row-wise column
        if(isSafe(row, col, n)){
            board[row][col] = 'Q';
            nQueen(row+1,n);
            board[row][col] = '.';
        }
    }
}

ll cntNqueen(ll row, ll n){
    if(row==n) return 1;
    ll total = 0;
    for(int col=0; col<n; col++){
        if(isSafe(row, col, n)){
            board[row][col] = 'Q';
            total += cntNqueen(row+1,n);
            board[row][col] = '.';
        }
    }
    return total;
}

int main(){
    FASTER

    ll n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = '.';
        }
    }
    nQueen(0,n);
    cout<<cntNqueen(0, n)<<nl;
}
