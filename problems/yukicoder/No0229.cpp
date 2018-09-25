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
 <url:https://yukicoder.me/problems/no/229>
 問題文============================================================
 =================================================================
 解説=============================================================
 数学ゴリゴリ
 ================================================================
 */

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
string solve(){
    string res;
    ll t1,t2,t3; cin >> t1 >> t2 >> t3;
    ll X = t1*t2*t3;
    vector<ll> Y1 = {(t3-t1)*t2,(t3-t1)*t2,(t3+t1)*t2,(t3+t1)*t2};
    vector<ll> Y2 = {(t3-t2)*t1,(t3+t2)*t1,(t3-t2)*t1,(t3+t2)*t1};
    ll maxbunbo = 0;
    for(int i = 0; i < Y1.size();i++){
        ll bunbo = gcd(Y1[i],Y2[i]);
        maxbunbo = max(bunbo,maxbunbo);
    }
    ll waru = gcd(X,maxbunbo);
    X /= waru;
    maxbunbo /= waru;
    res = to_string(X) + "/" + to_string(maxbunbo);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
