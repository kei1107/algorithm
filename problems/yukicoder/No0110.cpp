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
 <url:https://yukicoder.me/problems/no/110>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 一番最上段を白or黒にするかどうかの２パターンを考える。
 
 最上段の色が決まったら次に選ぶ長さは今見ている長さよりも大きく最小な長さを選択すればよく
 これはupper_boundで求まる。
 
 あとはシミュレーションすれば良い
 
 ================================================================
 */


ll check(ll now,ll cnt,bool turn,vector<ll>& W,vector<ll>& B){
    ll ret = cnt;
    if(turn){
        auto it = upper_bound(W.begin(), W.end(), now);
        if(it == W.end()) return ret;
        ret = max(ret,check(*it,cnt+1,!turn,W,B));
    }else{
        auto it = upper_bound(B.begin(), B.end(), now);
        if(it == B.end()) return ret;
        ret = max(ret,check(*it,cnt+1,!turn,W,B));
    }
    return ret;
}
ll solve(){
    ll res = 0;
    ll Nw; cin >> Nw;
    vector<ll> W(Nw); for(auto& in:W) cin >> in;
    ll Nb; cin >> Nb;
    vector<ll> B(Nb); for(auto& in:B) cin >> in;
    
    sort(W.begin(),W.end()); sort(B.begin(),B.end());
    
    res = max(check(W[0],1,false,W,B),check(B[0],1,true,W,B));
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
