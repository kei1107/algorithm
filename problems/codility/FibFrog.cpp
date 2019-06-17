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
    vector<int> fib;
    fib.push_back(0); fib.push_back(1);
    while(fib.back() < 100005){
        fib.push_back(fib[fib.size()-1]+fib[fib.size()-2]);
    }
    int N = (int)A.size();
    vector<int> canvisit(N+2,INF);
    canvisit[0] = 0;
    for(int i = 0; i <= N;i++){
        if(canvisit[i] == INF) continue;
        if(i==0 || A[i-1]){
            for(int j = 0; j < (int)fib.size();j++){
                if(i+fib[j] >= N+2) continue;
                canvisit[i+fib[j]] = min(canvisit[i+fib[j]],canvisit[i]+1);
            }
        }
    }
    if(canvisit[N+1] == INF) return -1;
    return canvisit[N+1];
}
