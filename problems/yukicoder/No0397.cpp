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

/*
 <url:https://yukicoder.me/problems/no/397>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 制約小さいのでバブルソートすればいい
 ================================================================
 */
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> A(N); for(auto& in:A) cin >> in;
    
    vector<pii> q;
    for(int i = 0; i < N;i++){
        for(int j = 1; j < N-i;j++){
            if(A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                q.push_back(pii(j-1,j));
            }
        }
    }

    cout << q.size() << endl;
    for(auto p:q){
        cout << p.first << " " << p.second << endl;
    }
    
    int dummy; cin >> dummy;
    return 0;
}
