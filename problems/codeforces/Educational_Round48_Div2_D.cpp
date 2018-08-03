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
 <url:http://codeforces.com/contest/1016/problem/D>
 問題文============================================================
 
 n x m のますがある。
 ここでi行目の全ての値のxorとなるai
      i列目の全ての値のxorとなるbi
 が与えられる。
 
 条件を満たす行列が存在するか？

 =================================================================
 解説=============================================================
 
 照明はきちんとやってないけど、とりあえず、
 aiとbiの全てのxorが0でなければ NO
 0でなければ作れる。
 
 ここで、構成方法は 一番右列と一番下列以外を0にすることによって、
 右下のマス以外は一意にきまる。
 あとは右下のマスに対して条件を満たすような値を入れれば良い
 ================================================================
 */

void solve(){
    ll n,m; cin >> n >> m;
    vector<ll> a(n),b(m);
    for(auto& in:a) cin >> in;
    for(auto& in:b) cin >> in;
    ll XOR = 0;
    for(auto v:a) XOR ^= v;
    for(auto v:b) XOR ^= v;
    
    if(XOR){
        cout << "NO" << endl;
        return;
    }
    vector<vector<ll>> M(n,vector<ll>(m));
    ll T1 = 0;
    for(int i = 0; i < n-1;i++){
        M[i][m-1] = a[i];
        T1^= a[i];
    }
    ll T2 = 0;
    for(int i = 0; i < m-1;i++){
        M[n-1][i] = b[i];
        T2 ^= b[i];
    }
    
    cout << "YES" << endl;
    M[n-1][m-1] = T1^b[m-1];
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cout << M[i][j];
            if(j != m-1) cout << " ";
            else cout << endl;
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
