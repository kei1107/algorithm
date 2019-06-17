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

bool ok(int m,int K,vector<int>& A){
    int sum = 0;
    int N = (int)A.size();
    
    int C = 0;
    for(int i = 0; i < N;i++){
        if(sum+A[i]>m){
            C++;
            sum = A[i];
        }else{
            sum += A[i];
        }
    }
    return K >= (C+1);
}
int solution(int K, int M, vector<int> &A) {
    int ret = INF;
    int l = *max_element(A.begin(), A.end())-1, r = INF;
    while(r-l>1){
        int m = (l+r)/2;
        if(ok(m,K,A)) r = m;
        else l = m;
    }
    ret = r;
    return ret;
}
