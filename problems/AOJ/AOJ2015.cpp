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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2015>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 縦方向と横方向は独立に考えることが可能。
 
 ================================================================
 */

int N,M;
ll solve(){
    ll res = 0;
    vector<ll> h(N+1),w(M+1);
    for(int i = 1; i <= N;i++){
        cin >> h[i];
        h[i] += h[i-1];
    }
    for(int i = 1; i <= M;i++){
        cin >> w[i];
        w[i] += w[i-1];
    }
    set<ll> s;
    map<ll,ll> x,y;
    for(int i = 0; i <= N;i++){
        for(int j = i+1; j <= N;j++){
            ll dif = h[j]-h[i];
            s.insert(dif);
            x[dif]++;
        }
    }
    for(int i = 0; i <= M;i++){
        for(int j = i+1; j <= M;j++){
            ll dif = w[j] - w[i];
            s.insert(dif);
            y[dif]++;
        }
    }
    
    for(auto v:s){
        res += x[v]*y[v];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N>>M,N|M){
        cout<< solve() << endl;
    }
    return 0;
}
