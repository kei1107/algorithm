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
 <url:http://codeforces.com/contest/1016/problem/A>
 問題文============================================================
 1ページにm文字まで名前を書くことができるノートがある
 ここでn人の名前を書くとき、
 それぞれの人の名前を書いたときにめくるページ数を答えよ
 =================================================================
 解説=============================================================
 累積和使ってシミュレーションでえい
 ================================================================
 */
vector<ll> solve(){
    vector<ll> res;
    ll n,m; cin >> n >> m;
    vector<ll> a(n); for(auto& in:a) cin >> in;
    vector<ll> cusum(n+1);
    for(int i = 0; i < n;i++){
        cusum[i+1] = cusum[i] + a[i];
    }
    for(int i = 0; i < n;i++){
        res.push_back(cusum[i+1]/m-cusum[i]/m);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
