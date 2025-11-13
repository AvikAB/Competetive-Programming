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

vector<ll>LPS(const string &pattern){
    ll m = pattern.size();
    vector<ll>lps(m, 0);
    ll j = 0; // len of previous longest suffix prefix
    ll i = 1; // start from the 2nd char in the pattern, because LPS[0]=0
    while(i<m){
        if(pattern[i]==pattern[j]){
            j++;
            lps[i] = j;
            i++;
        } else {
            if(j!=0){  // it means some part of patterns are matched & the comparison will resume from that index based on the value of j
                j = lps[j-1];
            } else {  // j==0 means no prefix-suffix matched, so lps value at the current index = 0
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMP(const string &text, const string &pattern){
    ll n = text.size();
    ll m = pattern.size();
    vector<ll>lps = LPS(pattern);  // call the lps array
    ll i = 0;   // index for text
    ll j = 0;  //  index for pattern
    bool found = false;
    while(i<n){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j==m){  // pattern found
            cout<<"Found at: "<<i-j<<nl;
            found = true;
            j = lps[j-1];
        }
        else if(i<n and pattern[j]!=text[i]){
            // mismatch after j matches
            if(j!=0){   // if j is not at the 0th index then it will take the lps value of j-1
                j = lps[j-1];
            } else {   // j!=0 then i++, because when it j=0 then lps[-1] not exist
                i++;
            }
        }
    }
    if(!found) cout<<-1<<nl;
}

int main(){
    FASTER

    string text, pattern;
    cin>>text>>pattern;
    KMP(text, pattern);
}

// TC: O(n+m)
