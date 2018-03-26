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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day1/problems/B>
問題文============================================================
 AORイカちゃんは集合 S={a1,...,aN} と写像 f:S→Sを作った。
 f(ai)=bi である。
 集合 S の任意の要素 x について、g(f(x))=h(f(x)) を満たす全ての写像 g,h:S→S が、
 g(x)=h(x) を満たすかどうか判定し、満たさない場合は反例を一つ構成せよ。

=================================================================

解説=============================================================

 set(b[i]) のサイズがNであれば YES
 Nでなければ、{1..N} のなかで存在しない値に該当する部分を変えれば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> a(N),b(N);
    for(auto& in:a) {cin >> in; in--;}
    for(auto& in:b) {cin >> in; in--;}
    set<ll> s(b.begin(),b.end());
    if(s.size() == N){
        cout << "Yes" << endl;
    }else{
        vector<int> f(N,0);
        for(auto it:s){
            f[it] = 1;
        }
        vector<ll> c(N),d(N);
        iota(c.begin(),c.end(),1);
        iota(d.begin(),d.end(),1);
        for(int i = 0; i < N;i++){
            if(f[a[i]] == 0){
                c[i] = i+1;
                if(i == 0) d[i] = 2;
                else d[i] = 1;
            }else{
                c[i] = i+1;
                d[i] = i+1;
            }
        }
        cout << "No" << endl;
        cout << c << endl;
        cout << d << endl;

    }
	return 0;
}
