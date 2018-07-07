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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1285>
 問題文============================================================
 
 ヒストグラムを書く為のインクの使用量を求めたい
 
 インクは最もの高さの高いものを基準( 1 )として、左から順に単調減少で使用比率が減っていく
 すなわち、一番左は 比率 1 一番みぎは　0 となる
 
 また、その他諸々の使用用途で0.01のインクが必ず使用される
 
 =================================================================
 解説=============================================================
 
 制約通りに実装あるのみ
 
 ================================================================
 */
int n,w;
double solve(){
    double res =0;
    vector<int> v(n); for(auto& in:v) cin >> in;
    vector<int> hist((*max_element(v.begin(),v.end()))/w+1);
    for(int i = 0; i < n;i++){
        hist[v[i]/w]++;
    }
    double ink = 1;
    double base = *max_element(hist.begin(),hist.end());
    for(int i = 0; i < hist.size();i++){
        res += ink*hist[i]/base;
        ink-=1/(double)(hist.size()-1);
    }
    res += 0.01;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n >> w,n){
        cout << fixed << setprecision(12) << solve() << endl;
    }
    return 0;
}
