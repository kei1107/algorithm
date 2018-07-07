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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2331>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 imos法を用いる
 
 [a,b]の区間に+1しておく。
 
 ここでimos[i]を見たとき imos[i] >= i-1 であれば
 i人を許容する人が少なくともi-1人いることになるため、i-1人誘うことができる
 
 あとは順番に見ていけば良い
 ================================================================
 */

int solve(){
    int res = 0;
    int N; cin >> N;
    vector<int> imos(100010,0);
    for(int i = 0; i < N;i++){
        int a,b; cin >> a >> b;
        imos[a]++; imos[b+1]--;
    }
    for(int i = 1; i <= N+1;i++){
        imos[i] += imos[i-1];
        if(imos[i] >= i-1) res = i-1;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
