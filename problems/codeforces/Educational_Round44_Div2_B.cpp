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
 <url:http://codeforces.com/contest/985/problem/B>
 問題文============================================================
 n個のスイッチとそのスイッチを押した時付く照明の対応が与えられる（照明は全部でm個）
 
 全てのスイッチを押せば必ず全ての照明がつくが、面倒なのでn-1回のスイッチで全ての
 照明をつけたい。
 
 これが可能かどうかのべよ
 =================================================================
 解説=============================================================
 
 全員がそれでしかつけることのできない照明を持っている場合はNO
 そうでなければYES
 ================================================================
 */

string solve(){
    string res = "NO";
    ll n,m; cin >> n >> m;
    vector<vector<char>> a(n,vector<char>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    }
    
    vector<int> f(n,0);
    for(int j = 0; j < m;j++){
        
        int cnt = 0;
        int num = -1;
        for(int i = 0; i < n;i++){
            if(a[i][j] == 1){ cnt++; num = i;}
        }
        if(cnt == 1){
            f[num] = true;
        }
    }
    for(int i = 0; i < n;i++){
        if(f[i] == false) return res = "YES";
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
