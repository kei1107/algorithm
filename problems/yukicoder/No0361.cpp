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
 <url:https://yukicoder.me/problems/no/361>
 問題文============================================================
 =================================================================
 解説=============================================================
 grundy数の典型問題。
 
 次状態のgrundy数の計算は愚直にやっても間に合う
 ================================================================
 */

string solve(){
    int L,D; cin >> L >> D;
    vector<int> grundy(L+1);
    set<int> st;
    for(int l = 0; l <= L; l++){
        st.clear();
        for(int i = 1; i < l;i++){
            for(int j = 1; i+j < l;j++){
                if(i == j) continue;
                int k = l-(i+j);
                if(i == k || j == k) continue;
                if(max({i,j,k})-min({i,j,k}) > D) continue;
                st.insert(grundy[i] ^ grundy[j] ^ grundy[k]);
            }
        }
        for(int i = 0; i <= 1000;i++){
            if(st.find(i)!=st.end()) continue;
            grundy[l] = i;
            break;
        }
    }
    if(grundy[L]) return "kado";
    else return "matsu";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
