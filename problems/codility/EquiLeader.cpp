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
    int res = 0;
    int N = (int)A.size();
    vector<int> L(N,INT_MAX),rL(N,INT_MAX);
    
    int maxcnt = 0;
    int leader_cand = INT_MAX;
    map<int,int> mp;
    for(int i = 0; i < N;i++){
        mp[A[i]]++;
        if(maxcnt < mp[A[i]]){
            maxcnt = mp[A[i]];
            leader_cand = A[i];
        }
        
        if((i+1)/2 < maxcnt){
            L[i] = leader_cand;
        }
    }

    maxcnt = 0;
    leader_cand = INT_MAX;
    mp.clear();
    reverse(A.begin(),A.end());
    for(int i = 0; i < N;i++){
        mp[A[i]]++;
        if(maxcnt < mp[A[i]]){
            maxcnt = mp[A[i]];
            leader_cand = A[i];
        }
        
        if((i+1)/2 < maxcnt){
            rL[i] = leader_cand;
        }
    }
    reverse(rL.begin(),rL.end());

    for(int i = 0; i < N-1;i++){
        if(L[i] == INT_MAX || rL[i+1] == INT_MAX) continue;
        res += L[i] == rL[i+1];
    }
    return res;
}
