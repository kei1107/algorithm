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

bool ok(int m,vector<int> &A, vector<int> &B, vector<int> &C){
    int N = (int)A.size();
    int M = (int)C.size();
    
    vector<int> cusum(2*M+1);
    for(int i = 0; i < m;i++) cusum[C[i]]++;
    for(int i = 1; i <= 2*M;i++) cusum[i] += cusum[i-1];
    
    for(int i = 0; i < N;i++){
        if(cusum[A[i]-1] == cusum[B[i]]) return false;
    }
    return true;
}
int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int l = 0, r = (int)C.size();
    while(r-l>1){
        int m = (l+r)/2;
        if(ok(m,A,B,C)) r = m;
        else l = m;
    }
    if(r==1 && !ok((int)C.size(),A,B,C)) return -1;
    return r;
}
