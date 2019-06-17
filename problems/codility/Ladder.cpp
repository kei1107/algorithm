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


int fib[31][50010];
vector<int> solution(vector<int> &A, vector<int> &B) {
    for(int i = 1; i <= 30;i++){
        fib[i][0] = 0;
        fib[i][1] = 1;
        for(int j = 2; j <= 50005; j++){
            fib[i][j] = (fib[i][j-1] + fib[i][j-2])%(1<<i);
        }
    }
    
    vector<int> ret;
    int L = (int)A.size();
    ret.resize(L);
    for(int i = 0; i < L;i++){
        ret[i] = fib[B[i]][A[i]+1];
    }
    return ret;
}
