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
 <url:https://yukicoder.me/problems/no/130>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 分割統治
 
 同一桁において 0 0 . . 0 0 や 1 1 .. 1 1などのように全て同じ値であれば、
 0にできる。逆に 0 と 1が混じっているものがあれば、必ずその位に 1 が立つ。
 よって、0 側と 1側において分割統治することによって分けて考えれば良い
 
 ================================================================
 */

ll rec(int x,vector<ll>& a){
    ll ret = 0;
    if(x < 0) return ret;
    vector<ll> l,r;
    for(int i = 0; i < a.size(); i++){
        if((a[i]>>x)&1){
            l.push_back(a[i]);
        }else{
            r.push_back(a[i]);
        }
    }
    
    if(l.empty()){
        ret = rec(x-1,r);
    }else if(r.empty()){
        ret = rec(x-1,l);
    }else{
        ret = (1<<x) + min(rec(x-1,l),rec(x-1,r));
    }
    return ret;
}
ll solve(){
    ll res = -1;
    ll N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    res = rec(32,a);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
