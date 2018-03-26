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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day1/problems/A>
問題文============================================================
 N  個の相違なる自然数 ai が与えられる。与えられた自然数から相違なる自然数を選び、ペアを作ることにした。
 作ることができるペアのうち、値の差が N−1 の倍数であるペアを一つ出力せよ。
 
 なお、そのようなペアは必ず存在する。
=================================================================

解説=============================================================

 N^2 試すだけ
 
================================================================
*/
void solve(){
    ll N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    [&]{
        for(int i = 0; i < N;i++){
            for(int j = i+1; j < N;j++){
                if(a[i] == a[j]) continue;
                if(abs(a[i] - a[j])%(N-1) == 0){
                    cout << a[i] << " " << a[j] << endl;
                    return;
                }
            }
        }
        return;
    }();
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
