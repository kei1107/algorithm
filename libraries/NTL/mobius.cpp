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


/* メビウスの反転公式
 f(n) = Σg(d) (dはnの約数)
 f(n) := 周期がnの約数であるものの個数　は g(d) := 周期がちょうどdであるものの総和であり
 
 次の公式と等価
 
 g(n) = Σμ(n/d)f(d) = Σμ(k)f(n/k)   (d = n/k)
 このとき μはメビウス関数
 
 メビウス関数
 ・nが1出ない平方数で割り切れるとき = 0
 ・そうで無いときnの素因数の個数をkとすると μ(n) = (-1)^k
 */
// nの約数におけるメビウス関数の値のmapを返す O(√n)
map<ll,ll> mobius(ll n){
    map<ll,ll> res;
    vector<ll> primes;
    
    for(int i = 2; i*i <= n;i++){
        if(n%i == 0){
            primes.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n != 1) primes.push_back(n);
    
    int m = (int)primes.size();
    for(int i = 0; i < (1<<m);i++){
        int mu = 1,d = 1;
        for(int j = 0; j < m;j++){
            if(i>>j&1){
                mu *= -1;
                d *= primes[j];
            }
        }
        res[d] = mu;
    }
    return res;
}



// ==================== //
// test 蟻本 p265

const ll MOD = 10009;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    
    ll res = 0;
    int n; cin >> n;
    auto mu = mobius(n);
    for(auto it = mu.begin();it!=mu.end();it++){
        (res += it->second * powmod(26,n/it->first))%=MOD;
    }
    cout << res << endl;
    return 0;
}
