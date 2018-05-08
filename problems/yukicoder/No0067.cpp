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
 <url:https://yukicoder.me/problems/no/67>
 問題文============================================================
 ユキさんは N 本の棒を持っていて、i 番目の棒の長さは Li です。
 棒は（長さを分割する方向に）自由に切ることができますが、繋げることはできません。
 ユキさんは同じ長さの K 本の棒を作りたいのです。
 作れる K 本の棒の長さの最大値を求めるプログラムを書いて下さい。
 =================================================================
 解説=============================================================
 
 評価関数 C(m) := 長さmの棒をK本以上作れるかどうか
 として、二分探索をすればよい
 ================================================================
 */

bool C(double m,const vector<ll>& L,ll & K){
    ll cnt = 0;
    for(auto v:L){
        cnt += (ll)(v/m);
    }
    return cnt >= K;
}
double solve(){
    double res = 0.;
    ll N; cin >> N;
    vector<ll> L(N); for(auto& in:L) cin >> in;
    ll K; cin >> K;
    double l = 0, r = LINF;
    for(int i = 0; i < 1000;i++){
        double m = (l+r)/2;
        if(C(m,L,K)){
            l = m;
        }else{
            r = m;
        }
    }
    res = l;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
