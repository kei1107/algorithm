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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2631>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 頑張って考えて気合場合わけ
 ================================================================
 */

ll solve(){
    ll n; cin >> n;
    vector<ll> a(n); for(auto& in:a) cin >> in;
    ll res = 0;
    sort(a.begin(),a.end());
    ll X = accumulate(a.begin(),a.end(),0LL);
    if(n == 1) return X;
    if(n == 2) return X - 1;
    if(n == 3) return X - 3;
    if(n == 4){
        if(*a.rbegin() == 2) return X-4;
        else if(*a.begin() == 2) return X - 5;
        else return X - 6;
    }
    if(n == 5){
        if(*a.rbegin() <= 3){
            if(X < 12) return X - 6;
            else if(X < 14) return X - 7;
            else return X - 8;
        }else{
            if(a[1] == 2) return X - 7;
            else if(X <= 20) return X - 8;
            else return X - 6 - min(a[0],4LL);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() <<endl;
    return 0;
}
