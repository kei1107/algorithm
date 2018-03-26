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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day1/problems/C>
 問題文============================================================
 長さ N の数列 ai が与えられる。 次の条件を満たす整数 K(1≤K≤N) を全て出力せよ。
 
 条件: a1,⋯,aK をうまく並び替えると aN−K+1,⋯,aN と一致する。
 
 =================================================================
 
 解説=============================================================
 
 Kを大きくしていくにつれて、mapなどで、左から見て行った時、右から見て行った時の
 要素が出現した個数を保持して、条件を満たすか判定していく
 
 ================================================================
 */
void solve(){
    ll N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    map<ll,ll> mp1,mp2;
    vector<ll> ans;
    for(int i = 1; i <= N;i++){
        mp1[a[i-1]]++;
        mp2[a[N-i]]++;
        [&]{
            for(auto it:mp1){
                if(it.second == mp2[it.first]) continue;
                return;
            }
            ans.push_back(i);
        }();
    }
    cout << ans << endl;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve();
    return 0;
}
