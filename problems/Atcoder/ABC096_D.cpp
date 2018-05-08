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
 <url:https://beta.atcoder.jp/contests/abc096/tasks/abc096_d>
 問題文============================================================
 日本語なので略
 =================================================================
 解説=============================================================
 下一桁が1であるもののみで数列を構成すれば、5個選んだ時の合計は必ず5の倍数になる
 (55555以下で下一桁が1になる素数は1408個あるので十分)
 ================================================================
 */

const ll MAX_PRIME = 55555;
vector<int> primes;
vector<int> is_prime(MAX_PRIME + 1,true);
void init_primes(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= MAX_PRIME;i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j = i*2; j <= MAX_PRIME; j+=i) is_prime[j] = false;
        }
    }
}

vector<int> ans;
void solve(){
    ll N; cin >> N;
    for(auto p:primes){
        if(ans.size() == N) break;
        if(p%10 == 1){
            ans.push_back(p);
        }
    }
//    cout << ans.size() << endl;
    cout << ans << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    init_primes();
    solve();
    return 0;
}
