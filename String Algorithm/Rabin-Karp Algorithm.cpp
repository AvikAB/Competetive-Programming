// Its based on the concept of hashing. Match the pattern
// Given a text & a pattern, print all the occurences of pattern present in the given text.

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

const ll d = 256;   // base

ll computeHash(const string &str, ll M){
    ll hash = 0;
    for(int i=0; i<M; i++){
        hash = (d*hash + (str[i]-'a'+1))%mod;
    }
    return hash;
}

// Rabin-Karp Pattern Search
void PatternSearch(const string &txt, const string &pat){
    ll M = pat.size();
    ll N = txt.size();
    ll p = computeHash(pat, M);   // hash of pattern
    ll t = computeHash(txt, M);   // hash of 1st window
    ll h = 1;  // precompute, h = (d^(M-1))%mod
    for(int i=0; i<M-1; i++){
        h = (h*d) % mod;
    }
    for(int i=0; i<=N-M; i++){
        if(p==t and txt.substr(i,M)==pat){
            cout<<"Found at index: "<<i<<nl;
        }
        // update hash for next window
        if(i<N-M){
            t = (d*(t-(txt[i]-'a'+1)*h)+(txt[i+M]-'a'+1)) % mod;
            if(t<0) t += mod;  // ensure non-neg hash
        }
    }
}

int main(){
    FASTER

    string txt, pat;
    cin>>txt>>pat;
    PatternSearch(txt, pat);
}
