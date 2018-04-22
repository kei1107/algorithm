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
 <url:https://yukicoder.me/problems/no/40>
 問題文============================================================
 ある日の宿題で多項式の割り算の問題が出ました。
 しかしあなたは多項式の割り算がとても苦手です。
 そこであなたはプログラムをつくり代わりにコンピュータに計算してもらうことにしました。
 与えられた多項式を x3−x で割った余りを出力してください。
 =================================================================
 解説=============================================================
 
 通常の多項式の割り算通りに実装すれば良い
 ================================================================
 */

void solve(){
    ll D; cin >> D;
    vector<ll> a(D+1); for(auto& in:a) cin >> in;
    for(ll d = D; d >= 3; d--){
        a[d-2] += a[d];
        a[d] = 0;
    }
    vector<ll> ans;
    for(int i = 2; i >= 0; i--){
        if(a[i] == 0){
            if(ans.size()) ans.push_back(a[i]);
        }else{
            ans.push_back(a[i]);
        }
    }
    cout << (ans.size()?ans.size()-1:0) << endl;
    reverse(ans.begin(),ans.end());
    cout << (ans.size()?ans:vector<ll>(1,0))<< endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
