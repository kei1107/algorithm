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
 <url:https://yukicoder.me/problems/no/356>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 T1>T2>T3とすると (考察容姿ではこの大小関係で式変形しちゃった)
 
 ある時間tに動点が一致するには
 (L/T2 - L/T1)t = L*n
 (L/T3 - L/T1)t = L*m
 となる
 ここで式変形すると
 (T1-T2)t = T1*T2*n
 (T1-T3)t = T1*T3*m
 から
 上の式にT3をしたの式にT2をかけて整理すると
 
 (T1-T2)T3*m = (T1-T3)T2*n
 ここでこのような式を満たす最小のm,nは lcmを取る事で求めることができる、
 
 あとは
 
 (T1-T2)*T3 t = T1*T2*T3*n
 より、既約分数の形に直せばいい
 ================================================================
 */

string solve(){
    string res;
    ll T1,T2,T3; cin >> T3 >> T2 >> T1;
    ll L = (T1-T2)*T3;
    ll R = (T1-T3)*T2;
    ll LCM = lcm(L,R);
    ll n = LCM/R;
    ll m = LCM/L;
    
    ll bunsi = T1*T2*T3*n;
    ll bunbo = L;
    ll GCD = gcd(bunbo,bunsi);
    bunsi /= GCD; bunbo /= GCD;
    res = to_string(bunsi) + "/" + to_string(bunbo);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
