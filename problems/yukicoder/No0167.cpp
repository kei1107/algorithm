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
 <url:https://yukicoder.me/problems/no/167>
 問題文============================================================
 =================================================================
 解説=============================================================
 mod 10 なので
 Nには1の位しか用がない
 あとはMだが M = 0の時は例外として
 それ以外の時は、値がループするので実装
 ================================================================
 */

ll solve(){
    ll res = 0;
    string N,M; cin >> N >> M;
    if(M == "0") return 1;
    int V = *N.rbegin() - '0';
    int FromV = V;
    vector<int> cycle(10);
    vector<int> cyclev;
    
    int cyclelen = 0;
    while(cycle[V] == 0){
        cycle[V] = ++cyclelen;
        cyclev.push_back(V);
        V = V*FromV%10;
    }
    int cycleid = 0;
    for(auto c:M){
        cycleid = 10*cycleid + c - '0';
        cycleid%=cyclelen;
    }
    res = cyclev[(cycleid+cyclelen-1)%cyclelen];
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
