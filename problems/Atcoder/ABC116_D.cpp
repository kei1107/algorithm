#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://atcoder.jp/contests/abc116/tasks/abc116_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 種類ボーナスを一旦考えずに、
 おいしさポイントだけを見て貪欲に大きい順にとっていった状態を初期状態として考える
 
 この時、食べた寿司の種類 n の個数を used[n]個
 また、食べていないそれぞれの種類の寿司で一番大きいポイントを持っているものの集合を作る
 
 この時、とった寿司でポイントが小さい順に見ていった時、used[n]が2以上となっていれば
 その寿司を取ることをやめて、まだ食べていない寿司の種類の最も大きいポイントのものを
 取ることができる。
 
 あとは、これを順番に実行した時の中で最もポイントが大きくなったものが答え
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,K; cin >> N >> K;
    vector<pll> td(N);
    for(auto& in:td){ cin >> in.first >> in.second; in.first--;}
    sort(td.begin(),td.end(),[](const pll& l,const pll& r){return l.second > r.second; });
    vector<int> used(N);
    ll S = 0;
    for(int i = 0; i < K;i++){
        used[td[i].first]+=1;
        S += td[i].second;
    }

    vector<int> checked(N);
    queue<pll> q;
    for(int i = K; i < N;i++){
        if(checked[td[i].first]) continue;
        if(used[td[i].first]) continue;
        q.push(td[i]);
        checked[td[i].first] = 1;
    }
    
    ll x = N - count(used.begin(),used.end(),0);
    res = S + x*x;
    
    for(int i = K-1; i >= 0; i--){
        if(q.empty()) break;
        if(used[td[i].first]<=1) continue;
        pll p = q.front(); q.pop();
        S -= td[i].second;
        S += p.second;
        
        x++;
        used[td[i].first]--;
        
        res = max(res,S + x*x);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
