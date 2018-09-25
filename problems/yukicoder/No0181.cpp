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
 <url:https://yukicoder.me/problems/no/181>
 問題文============================================================
 =================================================================
 解説=============================================================
 難しい。。。。諸々の解説を読んだ
 https://yukicoder.me/problems/no/181/editorial
 http://kmjp.hatenablog.jp/entry/2015/04/06/0930
 http://mayokoex.hatenablog.com/entry/2015/04/06/205955
 ================================================================
 */


ll powmod(ll a,ll b,ll m) {ll res=1;a%=m;for(;b;b>>=1){if(b&1)res=res*a%m;a=a*a%m;}return res;}
ll Euler_Phi(ll m) {
    if(m==0)return 0;
    ll res = m;
    for (ll i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            res = res / i * (i - 1); while(m % i == 0) m/=i;
        }
    }
    if (m != 1) res = res / m * (m - 1);
    return res;
}

vector<ll> Phi;
void initPhi(ll MAXM){
    Phi.clear(); Phi.resize(MAXM);
    for(int i = 1; i < MAXM;i++) Phi[i] = Euler_Phi(i);
}

ll greedy_test(ll a,ll n,ll m){
    if(a == 1) return 1;
    ll ret = 1;
    for(int i = 0; i < n;i++){
        ll t = ret; ret = 1;
        for(int j = 0; j < t;j++){
            ret *= a;
            if(ret>=m) return m;
        }
    }
    return ret;
}
// a↑↑b mod m
ll tetration(ll a,ll b,ll m){
    if(m == 1) return 0;
    if(a == 1 || b == 0) return 1;
    ll t = greedy_test(a,b-1,m+1);
    if(t <= m) return powmod(a,t,m);
    return powmod(a,m+(tetration(a, b-1,Phi[m])-m)%Phi[m],m);
}

ll solve(){
    ll res = 0;
    ll A,N,M; cin >> A >> N >> M;
    
    initPhi(M+1);
    res = tetration(A, N, M);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
