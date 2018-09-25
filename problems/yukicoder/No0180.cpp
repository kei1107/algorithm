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
 <url:https://yukicoder.me/problems/no/180>
 問題文============================================================
 =================================================================
 解説=============================================================
 自身がなかったけど、三分探索書いたら通ったので正義
 ================================================================
 */

ll f(ll m,vector<ll>& a,vector<ll>& b){
    ll minv = LINF,maxv = 0;
    for(int i = 0; i < a.size();i++){
        ll c = a[i] + b[i]*m;
        minv = min(minv,c);
        maxv = max(maxv,c);
    }
    return maxv - minv;
}
ll solve(){
    ll res = 0;
    int N; cin >> N;
    vector<ll> a(N),b(N);
    for(int i = 0; i < N;i++) cin >> a[i] >> b[i];
    ll l = 1, r = INF;
    for(int kassa = 0; kassa < 10000;kassa++){
        ll ml = (r-l)/3 + l;
        ll mr = (r-l)*2/3 + l;
        
        ll fl = f(ml,a,b);
        ll fr = f(mr,a,b);
        if(fl <= fr){
            r = mr;
        }else{
            l = ml;
        }
    }
    ll V = LINF;
    res = LINF;
    for(ll m = l; m <= r;m++){
        ll F = f(m,a,b);
        if(F < V){
            res = m;
            V = F;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
