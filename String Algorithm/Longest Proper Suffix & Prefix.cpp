// Problem on CF: Prefix and Suffix Can Be the Same

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
const ll INF = 1e9+10;

int main(){
    FASTER

    ll n;
    while(cin>>n and n!=0){
        string s;
        cin>>s;
        string ans = s;
        for(int i=n-1; i>=1; i--){
            if(s.substr(i) == s.substr(0, n-i)){
                ans = s.substr(n-i);
            }
        }
        cout<<s+ans<<nl;
    }
}
