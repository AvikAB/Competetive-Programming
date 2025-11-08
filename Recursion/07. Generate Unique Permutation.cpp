// Using set:

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

set<string>st;

void uniquePermute(string s, ll pos){
    ll len = s.size();
    if(pos==len-1){
        st.insert(s);
        return;
    }
    for(int i=pos; i<len; i++){
        swap(s[pos], s[i]);
        uniquePermute(s, pos+1);
        swap(s[pos], s[i]);   // backtrack
    }
}

int main(){
    FASTER;

    string s;
    cin>>s;
    uniquePermute(s,0);
    for(auto av:st){
        cout<<av<<nl;
    }
}


// Without set:

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

bool check(string s, ll curr, ll swapping_pos){
    for(int i=curr; i<swapping_pos; i++){
        if(s[i]==s[swapping_pos]) return false;
    }
    return true;
}

void uniquePermute(string s, ll pos){
    ll len = s.size();
    if(pos==len-1){
        cout<<s<<nl;
        return;
    }
    for(int i=pos; i<len; i++){
        if(check(s, pos, i)){
            swap(s[pos], s[i]);
            uniquePermute(s, pos+1);
            swap(s[pos], s[i]);   // backtrack
        }
    }
}

int main(){
    FASTER;

    string s;
    cin>>s;
    uniquePermute(s,0);
}
