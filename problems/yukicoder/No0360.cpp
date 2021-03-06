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
 <url:https://yukicoder.me/problems/no/360>
 問題文============================================================
 =================================================================
 解説=============================================================
 7!通りを愚直全探索
 ================================================================
 */

bool incKadomatsu(int a,int b,int c){
    if(a == b || b == c || c == a) return false;
    if(a > c) return false;
    if(a > b && c > b) return true;
    if(a < b && c < b) return true;
    return false;
}
string solve(){
    vector<int> D(7); for(auto& in:D) cin >> in;
    vector<int> order(7); iota(order.begin(),order.end(),0);
    do{
        bool ok = true;
        for(int i = 2; i < 7;i++){
            ok &= incKadomatsu(D[order[i-2]], D[order[i-1]], D[order[i]]);
        }
        if(ok) return "YES";
    }while(next_permutation(order.begin(),order.end()));
    return "NO";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
