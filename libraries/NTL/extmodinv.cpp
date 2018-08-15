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

// a^-1 (mod. m)
// aとmが互いに素であれば有効

ll extGCD(ll a,ll b,ll& x,ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
// 負に対応
inline ll mod(ll a,ll m){
    return (a%m+m)%m;
}
// 逆元計算
ll modinv(ll a,ll m){
    ll x,y;
    extGCD(a, m, x, y);
    return mod(x,m);
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << modinv(3,7) << endl;
    return 0;
}
