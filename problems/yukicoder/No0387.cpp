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
 <url:https://yukicoder.me/problems/no/387>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 a[i]毎に順番に見ていくのではなく、
 bをスタンプとみなして、色毎に推していけばいい
 
 この時bitsetを使うことでO(N^2/32) で通る
 ================================================================
 */

void solve(){
    int N; cin >> N;
    vector<ll> a(N),b(N);
    for(auto& in:a) cin >> in;
    for(auto& in:b) cin >> in;
    
    const int LIM = 200001;
    vector<vector<int>> G(LIM);
    vector<int> B;
    for(int i = 0; i < N;i++) G[a[i]].push_back(i);
    for(int i = 0; i < N;i++) if(b[i]) B.push_back(i);
    
    
    bitset<LIM> bit;
    bitset<LIM> stamp;
    for(int i = 0; i < N;i++) if(b[i]) stamp.set(i);
    for(int i = 0; i < LIM;i++){
        bitset<LIM> tmpstamp;
        for(auto n:G[i]){
            tmpstamp |= (stamp<<n);
        }
        bit ^= tmpstamp;
    }
    for(int i = 0; i < 2*N-1;i++){
        if(bit[i]) cout << "ODD" << endl;
        else cout << "EVEN" << endl;
    }
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
