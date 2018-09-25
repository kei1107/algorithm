#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://beta.atcoder.jp/contests/arc097/tasks/arc097_a>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 文字列に関しては最大でもK文字まで見れば良い
 
 よってKの制約が小さいので O(|S|K)で十分間に合う
 ================================================================
 */

string solve(){
    string res;
    string s; cin >> s;
    ll K; cin >> K;
    vector<string> str;
    for(int i = 0; i < s.length();i++){
        for(int j = 1; j <= K && i+j<=s.length();j++){
            str.push_back(s.substr(i,j));
        }
    }
    sort(str.begin(),str.end());
    str.erase(unique(str.begin(),str.end()),str.end());
    res = str[K-1];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
