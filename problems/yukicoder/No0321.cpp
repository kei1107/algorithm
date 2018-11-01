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
 <url:https://yukicoder.me/problems/no/321>
 問題文============================================================
 =================================================================
 解説=============================================================
 ざ　数学
 ================================================================
 */

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

ll solve(){
    ll res = 0;
    ll P,Q; cin >> P >> Q;
    ll GCD = gcd(P,Q);
    if(GCD){P /= GCD;Q /= GCD;}
    
    ll N; cin >> N;
    
    for(int i = 0; i < N;i++){
        ll x,y; cin >> x >> y;
        if(P == 0 && Q == 0){
            if(x == 0 && y == 0) res++;
        }else{
            if(x%GCD == 0 && y%GCD == 0){
                x /= GCD; y /= GCD;
                if((P%2) == (Q%2)){
                    if((x+y)%2 == 0) res++;
                }else{
                    res++;
                }
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
