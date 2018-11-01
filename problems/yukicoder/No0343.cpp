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
 <url:https://yukicoder.me/problems/no/343>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 重心確認して境界チェック
 ================================================================
 */

ll solve(){
    ll res = 0;
    int N; cin >> N;
    double L; cin >> L;
    vector<double> X(N);
    for(int i = 1; i < N;i++) cin >> X[i];
    for(int i = 0; i < N-1;i++){ if(abs(X[i]-X[i+1])>=L) return -1; }
    
    double Gsum = X.back();
    for(int i = N-2; i >= 0; i--){
        ll n = N-i-1;
        bool ok = true;

        if(n*(X[i+1]-L/2) >= Gsum || n*(X[i+1]+L/2) <= Gsum) ok = false;
        if(n*(X[i]-L/2) >= Gsum || n*(X[i]+L/2) <= Gsum) ok = false;

        Gsum += X[i];
        res += !ok;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
