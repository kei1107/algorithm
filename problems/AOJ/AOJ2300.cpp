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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2300>
 問題文============================================================
 
 各要素の二乗和が距離となるLABカラーがある。
 
 N個の中からM個選ぶ時、LABカラーの距離の総和の最大値を述べよ
 =================================================================
 解説=============================================================
 
 制約小さいので全探索できる
 ================================================================
 */

#define square(x) (x)*(x)
typedef long double ld;
ld solve(){
    ld res = 0;
    int N,M; cin >> N >> M;
    vector<ld> L(N),a(N),b(N);
    for(int i = 0; i < N;i++) cin >> L[i] >> a[i] >> b[i];
    for(int i = 0; i < (1<<N);i++){
        if(__builtin_popcount(i) != M) continue;
        ld T = 0;
        for(int j = 0; j < N;j++){
            if((i>>j)&1){
                for(int k = j+1;k < N;k++){
                    if((i>>k)&1){
                        T += (square(L[j]-L[k]) + square(a[j]-a[k]) + square(b[j]-b[k]));
                    }
                }
            }
        }
        res = max(res,T);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
