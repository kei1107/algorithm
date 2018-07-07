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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2001>
 問題文============================================================
 =================================================================
 解説=============================================================
 あみだくじの結果の仕様に基づいてシミュレーションしてやれば良い
 ================================================================
 */

int n,m,a;
int solve(){
    int res = 0;
    vector<int> amida(n,0); iota(amida.begin(),amida.end(),0);
    a--;
    
    vector<pair<int,pii>> query(m);
    for(int i = 0; i < m;i++){
        int h,p,q; cin >> h >> p >> q;
        query[i] = {h,{p-1,q-1}};
    }
    sort(query.begin(),query.end());
    for(int i = 0; i < m;i++){
        swap(amida[query[i].second.first],amida[query[i].second.second]);
    }
    return res = amida[a]+1;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n >> m >> a,n|a|m){
        cout << solve() << endl;
    }
    return 0;
}
