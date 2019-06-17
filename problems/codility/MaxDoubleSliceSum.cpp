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
    int ret = -INF;
    int N = (int)A.size();
    
    // cusum[i] = cumsum of [0,i]
    vector<int> cusum(N);
    cusum[0] = A.front();
    for(int i = 1; i <= N-1;i++) cusum[i] = cusum[i-1]  + A[i];
    
    // L[i] = min(cusum[0],...cusum[i-1])
    vector<int> L(N,INF);
    for(int i = 1; i < N;i++) L[i] = min(L[i-1],cusum[i-1]);
    
    // R[i] = max(cusum[i+1],...,cusum[N-2])
    vector<int> R(N,-INF);
    for(int i = N-3; i >= 0; i--) R[i] = max(R[i+1],cusum[i+1]);
    
    for(int i = 1; i < N-1; i++){
        int ladd = max(0,cusum[i-1] - L[i]);
        int radd = max(0,R[i] - cusum[i]);
        ret = max(ret,ladd+radd);
    }
    return ret;
}
