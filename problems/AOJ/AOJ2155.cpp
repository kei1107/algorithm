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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2155>
 問題文============================================================
 =================================================================
 解説=============================================================
 時系列順に処理していけば良い
 ================================================================
 */
int N,M;
ll solve(){
    ll res = 0;
    using Items = tuple<int,int,int>;
    vector<Items> com(M);
    for(int i = 0; i < M;i++){
        int t,s,d; cin >> t >> s >> d;
        com[i] = Items(t,s,d);
    }
    sort(com.begin(),com.end());
    vector<int> infected(N+1,0); infected[1] = true;
    for(int i = 0; i < M;i++){
        infected[get<2>(com[i])] |= infected[get<1>(com[i])];
    }
    res = accumulate(infected.begin(),infected.end(),0LL);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N >> M,N|M){
        cout << solve() << endl;
    }
    return 0;
}
