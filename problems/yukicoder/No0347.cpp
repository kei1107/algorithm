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
 <url:https://yukicoder.me/problems/no/347>
 問題文============================================================
 =================================================================
 解説=============================================================
 微分・積分するだけ
 ================================================================
 */

void solve(){
    int N; cin >> N;
    ll B; cin >> B;
    vector<double> a(N); for(auto& in:a) cin >> in;
    double A1 = 0;
    double A2 = 0;
    for(int i = 0; i < N;i++){
        A1 += a[i]*pow(B,a[i]-1);
        if(a[i] == -1.0){
            A2 += log(B);
        }else{
            A2 += pow(B,a[i]+1)/(a[i]+1);
        }
    }
    cout << fixed << setprecision(12);
    cout << A1 << endl;
    cout << A2 << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
