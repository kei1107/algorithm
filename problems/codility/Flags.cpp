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


bool check(int K,vector<int>& dists){
    int cnt = 1;
    int sum = 0;
    for(int i = 0; i < (int)dists.size();i++){
        sum += dists[i];
        if(sum >= K){
            sum = 0;
            cnt++;
        }
    }
    return cnt>=K;
}
int solution(vector<int> &A) {
    int ret = 0;
    int N = (int)A.size();
    vector<int> peaks;
    for(int i = 1; i < N-1;i++) if(A[i-1]<A[i] && A[i]>A[i+1]) peaks.push_back(i);
    if(peaks.size() < 2) return ret = (int)peaks.size();
    vector<int> dists(peaks.size()-1);
    for(int i = 1; i < (int)peaks.size();i++){
        dists[i-1] = peaks[i]-peaks[i-1];
    }
    int l = 0, r = INF;
    while(r-l>1){
        int K = (l+r)/2;
        if(check(K,dists)) l = K;
        else r = K;
    }
    ret = l;
    return ret;
}
