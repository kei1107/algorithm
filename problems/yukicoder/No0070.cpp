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
 <url:https://yukicoder.me/problems/no/70>
 問題文============================================================
 太郎君は健康のために、毎日、寝た時刻と起きた時刻の記録をとっています。
 
 入力に、寝た時刻と起きた時刻のリストが与えられるので、
 睡眠時間の合計を出力してください。
 
 太郎君は、1回につき24時間以上眠り続けることは無いものとします。
 太郎君の世界は1日あたり24時間、1時間は60分で表されます.
 
 =================================================================
 解説=============================================================
 じゃけん計算しましょうね-
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    for(int i = 0; i < N;i++){
        ll H,M,h,m; char c;
        cin >> H >> c >> M >> h >> c >> m;
        ll T = 60*H+M, t = 60*h+m;
        if(t < T) t += 24*60;
        res += t-T;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
