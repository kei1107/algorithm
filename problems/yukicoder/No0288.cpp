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
 <url:https://yukicoder.me/problems/no/288>
 問題文============================================================
 =================================================================
 解説=============================================================
 惜しいところまで行ってたけど最後の一歩が詰め切れなかった。
 
 考えが至らなかった最も重要なポイントは
 --------- 解説より
 ゆきうさぎさんはまず手持ちを全額貯金箱さんに支払ってしまい，
 貯金箱さんはお釣りを最小枚数の硬貨で支払えばよい
 (最終的な所持金は決まっているので，それを最小枚数の硬貨で作る方法が存在するならば，それは最適解である)．
 ---------
 
 これがわかれば、ある程度十分な大きさまではAnを用いて全て払う事ができるので
 An*Anぐらいまでの支払い方のdpでえとける
 ================================================================
 */

ll solve(){
    ll res = LINF;
    ll N,M; cin >> N >> M;
    vector<ll> A(N),K(N);
    for(auto& in:A) cin >> in;
    for(auto& in:K) cin >> in;
    
    ll T = 0;
    for(int i = 0; i < N;i++) T += A[i]*K[i];
    if(T < M) return -1;
    T -= M;
    
    ll MaxA = A[N-1];
    vector<ll> min_ret(MaxA*MaxA+1,LINF);
    min_ret[0] = 0;
    for(int i = 0; i <= MaxA*MaxA;i++){
        if(min_ret[i] == LINF) continue;
        for(int j = 0; j < N;j++){
            if(i+A[j]<=MaxA*MaxA){
                min_ret[i+A[j]] = min(min_ret[i+A[j]],min_ret[i]+1);
            }
        }
    }
    ll C = 0;
    if(T>=MaxA*MaxA){
        C = (T-MaxA*MaxA+MaxA)/MaxA;
        T -= MaxA*C;
    }
    if(min_ret[T] == LINF) return -1;
    res = min_ret[T] + C;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
