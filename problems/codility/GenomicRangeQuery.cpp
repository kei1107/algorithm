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

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    vector<vector<int>> ACGT(S.length()+1,vector<int>(4));

    map<char,int> G2I;
    G2I['A'] = 0; G2I['C'] = 1; G2I['G'] = 2; G2I['T'] = 3;
    
    for(int i = 1; i <= (int)S.length();i++){
        for(int j = 0; j < 4;j++){
            ACGT[i][j] = ACGT[i-1][j];
        }
        ACGT[i][G2I[S[i-1]]]++;
    }
    int M = (int)P.size();
    vector<int> res(M);
    for(int i = 0; i < M;i++){
        for(int j = 0; j < 4;j++){
            if(ACGT[Q[i]+1][j]-ACGT[P[i]][j]){
                res[i] = j+1;
                break;
            }
        }
    }
    return res;
}
