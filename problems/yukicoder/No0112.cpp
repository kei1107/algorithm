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
 <url:https://yukicoder.me/problems/no/112>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ややこしい、
 
 各aの値は全ての足の総和から自身の足の本数を引いただけなので、
 最大でも２パターンしかない。
 
 あとはその数見て場合わけ
 ================================================================
 */

vector<ll> solve(){
    vector<ll> res;
    ll N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    map<ll,ll> mp; for(auto& v:a) mp[v]++;
    
    if(mp.size() == 2){
        res.push_back(mp.begin()->second);
        res.push_back(mp.rbegin()->second);
        reverse(res.begin(),res.end());
    }else{
        res.push_back(mp.begin()->second);
        res.push_back(0);
        if((N-1)*2 != mp.begin()->first){
            reverse(res.begin(),res.end());
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
