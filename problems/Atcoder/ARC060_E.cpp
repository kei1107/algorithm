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
 <url:https://arc060.contest.atcoder.jp/tasks/arc060_c>
 問題文============================================================
 N 軒のホテルが一直線上に並んでいます。i (1≤i≤N) 番目のホテルは、座標 xi に位置しています。
 
 旅行者である高橋君には、次の 2 つの信念があります。
 
 高橋君の 1 日の移動距離は L を超えない。
 高橋君は野宿をしない。すなわち、1 日の終わりには必ずいずれかのホテルにいなければならない。
 
 Q 個のクエリが与えられます。j (1≤j≤Q) 番目のクエリとして、異なる 2 つの整数 aj, bj が与えられます。
 各クエリについて、前述の信念をともに守った上で、
 高橋君が aj 番目のホテルから bj 番目のホテルに移動するために必要な最小日数を求めてください。
 なお、高橋君が aj 番目のホテルから bj 番目のホテルに移動できることは保証されます。
 =================================================================
 解説=============================================================
 
 ダブリング
 
 i番目のホテルから2^k番目に到達できるホテルのうちもっとも右側にあるもの
 をダブリングによってあらかじめ求めておき、そのテーブルを用いて二分探索を行う
 ================================================================
 */

ll check(ll i,ll d,vector<vector<ll>>& next){
    if(d == 0) return i;
    ll k = 0;
    while(d >= (1<<k)) k++;
    return check(next[k-1][i],d - (1<<(k-1)),next);
}
void solve(){
    ll N; cin >> N;
    vector<ll> x(N); for(auto& in:x) cin >> in;
    ll L; cin >> L;
    ll Q; cin >> Q;
    vector<ll> a(Q),b(Q);
    for(int i = 0; i < Q;i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        if(a[i] > b[i]) swap(a[i],b[i]);
    }
    
    ll LOG_N = 0;
    while(N >= (1<<LOG_N)) LOG_N++;
    vector<vector<ll>> next(LOG_N,vector<ll>(N));
    for(int i = 0; i < N;i++){
        next[0][i] = upper_bound(x.begin(), x.end(), x[i]+L) - x.begin() - 1;
    }
    for(int k = 0; k < LOG_N-1; k++){
        for(int i = 0; i < N;i++){
            next[k+1][i] = next[k][next[k][i]];
        }
    }
    for(int i = 0; i < Q;i++){
        ll _a = a[i], _b = b[i];
        ll l = 0, r = N;
        while(r-l>1){
            ll m = (l+r)/2;
            if(check(_a,m,next) >= _b) r = m;
            else l = m;
        }
        cout << r << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
