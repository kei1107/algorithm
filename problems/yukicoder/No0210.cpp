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
 <url:https://yukicoder.me/problems/no/210>
 問題文============================================================
 =================================================================
 解説=============================================================
 難しいけど、面白い
 
 x回目に部屋iでメガネが見つかる確率は
 
 x*(1-qi)^(x-1) * pi
 
 期待値が最小になるには、x回目の時点でもっとも見つかる確率が大きいものから順にとっていけばいい
 
 これはpriority_queueで実現できる
 ================================================================
 */

typedef long double ld;
ld solve(){
    ld res = 0;
    int n; cin >> n;
    vector<ld> p(n),q(n);
    for(auto& in:p){ cin >> in; in/=1000.0;}
    for(auto& in:q){ cin >> in; in/=100.0; }
    priority_queue<pair<ld,int>> pq;
    for(int i = 0; i < n;i++) pq.push(make_pair(p[i]*q[i],i));
    int kassa = 0;
    while(kassa++<1000000){
        ld P; int ind; tie(P,ind) = pq.top(); pq.pop();
        res += kassa*P;
        P *= 1-q[ind];
        pq.push(make_pair(P,ind));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
