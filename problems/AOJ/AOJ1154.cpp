#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1154&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 先にエクストラネスの節の要領で月曜土曜素数を列挙し調べれば良い
 ================================================================
 */

#define MAXN 300005
vector<int> primes;
bool isprime[MAXN];
void init(){
    for(int i = 2; i < MAXN;i++){
        if(isprime[i]) continue;
        if(i%7 == 1 || i%7 == 6){
            primes.push_back(i);
            for(int j = 2;i*j < MAXN;j++){
                isprime[i*j] = true;
            }
        }else{
            isprime[i] = true;
        }
    }
}
int n;
void solve(){
    vector<int> ans;
    cout << n << ": ";
    for(auto p:primes){
        if(n%p == 0){
            assert(p%7 == 1 || p%7 == 6);
            ans.push_back(p);
        }
    }
    cout << ans << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    init();
    while(cin >> n, n!=1){
        solve();
    }
    return 0;
}
