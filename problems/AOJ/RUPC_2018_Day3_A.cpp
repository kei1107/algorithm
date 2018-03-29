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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day3/problems/A>
問題文============================================================
 
 林檎農家で働くMonの仕事は「林檎の収穫」と「林檎の出荷」の二つである。
 育てている林檎の種類は N 種あり、収穫した林檎はそれぞれ区別された N 個の箱に保管される。
 出荷は箱に保管されている林檎から行われ、指定された種類の林檎を出荷する。
 林檎は (1≤i≤N) の番号付けによって種類が区別されており、 i 番目の種類の林檎は 箱 i に保管されるものとする。
 各箱 i (1≤i≤N) には最大 ci 個の林檎をいれることができ、初め各箱に入っている林檎の個数は 0 個である。
 
 Monはこれらの仕事を上司であるKukuiの指示に完全に従う。
 指示は全部で Q 回あり、各指示は以下の 2 つのうちのどちらかである。
 
 林檎の収穫 ：箱 x に、収穫した d 個の林檎 x を入れる
 林檎の出荷 ：箱 x から、 d 個の林檎 x を取り出す
 ただし、kukuiの指示は必ずしも理にかなっているとは言えず、理不尽なものが含まれている可能性がある。
 それを判定するプログラムを作ってほしい。 ここで理不尽な指示とは以下の 2 つのことを指す。
 
 林檎の収穫をする際に箱の最大容量を超える
 林檎の出荷をする際に箱の中の林檎が足りなくなる

=================================================================

解説=============================================================

 愚直シミュレーション
 
================================================================
*/

int solve(){
    int N; cin >> N;
    vector<int> c(N);
    for(auto& in:c) cin >> in;
    int Q; cin >> Q;
    vector<int> t(Q),x(Q),d(Q);
    vector<int> hako(N,0);
    for(int i = 0; i < Q;i++){
        int t,x,d; cin >> t >> x >> d;
        x--;
        if(t==1){
            hako[x] += d;
            if(hako[x] > c[x]) return x+1;
        }else{
            hako[x] -= d;
            if(hako[x] < 0) return x+1;
        }
    }
    return 0;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
