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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2767>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 同じ係数のものはまとめることが可能であればできるだけまとめたほうがいい
 
 あとは係数が1の時と種類が1の時に気をつけて実装すればいい
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    string S; cin >> S;
    vector<int> alpha;
    for(int i = 0; i < 26;i++){
        int x = (int)count(S.begin(),S.end(),'a'+i);
        if(x == 0) continue;
        alpha.push_back(x);
    }
    for(int x = 1; x <= 9; x++){
        int y = (int)count(alpha.begin(),alpha.end(),x);
        if(y == 0) continue;
        if(x == 1){
            res += (2*y-1);
        }else{
            if(y == 1){
                res += 3*y;
            }else{
                res += (4+2*y-1);
            }
        }
    }
    sort(alpha.begin(),alpha.end());
    alpha.erase(unique(alpha.begin(),alpha.end()),alpha.end());
    res += alpha.size()-1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
