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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2149>
 問題文============================================================
 =================================================================
 解説=============================================================
 乱数生成回数が最大でも10,000回なので、愚直に回しても間に合う
 ================================================================
 */

int N,A,B,C,X;
ll solve(){
    ll res = -1;
    vector<ll> Y(N); for(auto& in:Y) cin >> in;
    ll L = 0;
    int idx = 0;
    while(L <= 10000){
        if(X == Y[idx]) idx++;
        if(idx == N) return L;
        X = (A*X+B)%C;
        L++;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N >> A >> B >> C >> X,N){
        cout << solve() << endl;
    }
    return 0;
}
