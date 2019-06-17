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

int solution(vector<int> &A, vector<int> &B) {
    int res = 0;
    stack<pii> st;
    int N = (int)A.size();
    for(int i = 0; i < N;i++){
        if(st.empty()) st.push({A[i],B[i]});
        else {
            if(st.top().second == 0) st.push({A[i],B[i]});
            else{
                if(B[i] == 1) st.push({A[i],B[i]});
                else{
                    bool nochange = false;
                    while(!st.empty() && st.top().second == 1){
                        if(st.top().first > A[i]) {
                            nochange = true;
                            break;
                        }
                        st.pop();
                    }
                    if(!nochange) st.push({A[i],B[i]});
                }
            }
        }
    }
    res = (int)st.size();
    return res;
}
