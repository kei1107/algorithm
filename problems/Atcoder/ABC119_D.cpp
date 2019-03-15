#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://atcoder.jp/contests/abc119/tasks/abc119_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 lower_boundで境界を探して、
 直近の寺と神社の組み合わせを全部試す
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll A,B,Q; cin >> A >> B >> Q;
    vector<ll> s(A),t(B),x(Q);
    for(auto& in:s) cin >> in;
    for(auto& in:t) cin >> in;
    s.push_back(-LINF); s.push_back(LINF);
    t.push_back(-LINF); t.push_back(LINF);
    
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    
    while(Q--){
        ll x; cin >> x;
        auto sit = lower_bound(s.begin(),s.end(),x);
        auto tit = lower_bound(t.begin(),t.end(),x);
        
        ll ans = LINF;
        ans = min(ans,max(*sit,*tit)-x);
        ans = min(ans,*sit-*(tit-1) + min(*sit-x,x-*(tit-1)));
        ans = min(ans,*tit-*(sit-1) + min(*tit-x,x-*(sit-1)));
        ans = min(ans,x-min(*(sit-1),*(tit-1)));
        cout << ans << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
