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

int solution(vector<int> &A) {
    int ret = 0;
    int N = (int)A.size();
    vector<pll> secs(N);
    for(ll i = 0; i < N;i++){
        secs[i] = {i-A[i],i+A[i]};
    }
    sort(secs.begin(),secs.end());
    for(int i = 0; i < N;i++){
        int R = (int)(upper_bound(secs.begin(),secs.end(),pll(secs[i].second,LINF)) - secs.begin());
        ret += max(0,R-(i+1));
        if(ret > 10000000){
            ret = -1;
            break;
        }
    }
    return ret;
}
