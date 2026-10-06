#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e5+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

ll cntOcc(string s, string p){
    ll ans = 0;
    unordered_map<char,ll>mp;

    // storing the occ. of pattern(p) in the map
    for(auto &av:p){
        mp[av]++;
    }

    ll cnt = mp.size();   // total distinct char in pattern(p), if its 0 then its an anagram
    ll k = p.size();   // window size
    ll i=0, j=0;

    while(j<s.size()){
        // calculation part (if char is exist then dec the char freq and cnt), add s[j] and its calculation 
        // calculation means which char in next, how many new distinct char in the window

        if(mp.find(s[j])!=mp.end()){   // s[j] is exist
            mp[s[j]]--;
            if(mp[s[j]]==0) cnt--;
        }

        if(j-i+1<k){
            j++;    // if size is less than k then expand j
        } else if(j-i+1==k){
            // find ans that we process before in calculation part
            if(cnt==0) ans++;  // the window is anagram

            // slide part, remove s[i] from window & its calculation
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                if(mp[s[i]]==1) cnt++;
            }
            i++;
            j++;
        }
    }
    return ans;
}

void solve(){
    string s,p;
    cin>>s>>p;
    cout<<(cntOcc(s, p))<<nl;
}

int main(){
    FASTER
    // ll t;
    // cin>>t;
    // while(t--){
        solve();
    // }
}



/*
Pattern's size will be k here. And I need to find the occurences of k-sized window that is anagram in the main string.


mp -> storing how many times each char in pattern (p).
cnt -> num of distinct char in pattern (p).
**if (cnt==0) then the window is anagram, cnt==0 means the same number of chars in window and the pattern (p). It reduces time O(n*k) to O(k). For checking anagram, compare maps directly
cost O(k) per window while this cost O(1) per window.

** In sliding operation, we remove s[i] & its calculations then in next iteration we add s[j] and its calculations. And the process we do here in reverse way.
  Adding a char = decrease the need.
  Removing a char = increase the need back.
Thats why we do mp[s[i]]++, if(mp[s[i]]==1) cnt++; for removing the s[i] from the window.

TC: O(n+k)
SC: O(1)
*/
