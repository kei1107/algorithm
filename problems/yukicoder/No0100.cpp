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
 <url:https://yukicoder.me/problems/no/100>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 あみだくじは置換と同義である。
 
 同じあみだくじを二つ繋げてできるということは、
 ある置換の自乗であるということと同じである。
 
 よって、実験すると、偶数サイズのループが偶数個あればいいことがわかる
 ================================================================
 */

void dfs(ll n,int& cnt,vector<ll>& a,vector<int>& f){
    f[n] = 1;
    cnt++;
    if(f[a[n]] == 1) return;
    dfs(a[n],cnt,a,f);
}
string solve(){
    ll N; cin >> N;
    vector<ll> a(N+1);
    for(int i = 1; i <= N;i++) cin >> a[i];
    vector<int> f(N+1,0);
    map<int,int> mp;
    for(int i = 1; i <= N;i++){
        if(f[i] == 1) continue;
        int cnt = 0;
        dfs(i,cnt,a,f);
        mp[cnt]++;
    }
    for(auto p:mp){
        if(p.first%2 == 0 && p.second%2 == 1) return "No";
    }
    return "Yes";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
