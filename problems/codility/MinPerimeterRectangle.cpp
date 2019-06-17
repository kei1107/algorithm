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

// nの約数を列挙する
vector<ll> getdivisor(ll n){
    vector<ll> res;
    for(ll i = 1; i*i <= n;i++){
        if(n%i == 0) {
            res.push_back(i);
            if(n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
int solution(int N) {
    auto divisors = getdivisor(N);
    int ret = INF;
    for(auto divisor:divisors){
        ret = min(ret,2*(int)(divisor+N/divisor));
    }
    return ret;
}
