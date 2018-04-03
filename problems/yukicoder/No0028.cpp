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
 <url:https://yukicoder.me/problems/no/28>
 問題文============================================================
 X0=seed
 Xn=1+((X_n−1)^2+X_n−1×12345) % 100000009    (1≤n≤N)
 ただし % は剰余演算とする
 
 上の定義から作られる N+1 個の要素を持つ数列 X の中から K 個数字を選びそれらを掛け合わせ T とおく。
 T を B 進数に変換した時末尾の0の数が最小となる T では末尾の0の数はいくつになるか答えよ。
 
 例えば
 B=18、T が10進数で「612」なら T は18進数で「1g0」なので末尾の0の数は1個
 B=3、T が10進数で「36」なら T は3進数で「1100」なので末尾の0の数は2個
 =================================================================
 解説=============================================================
 えー最初、最小を最大と勘違いしてて　間に合わなくね？ってずっと思ってた。誤読辛い
 
 最小ならばBの素因数一つ一つについてどれだけ、その素因数の個数を満たさないものとなるかという
 問題に帰着できるため、
 
 Bのある素因数pについて　各X[0..N]について、どれだけpの個数が含まれているか、
 その後、その個数についてソートして、小さい方からK個でBが必要とする素因数の個数の何倍かと一つずつ見れば良い
 ================================================================
 */

/* 素因数分解 */
vector<ll> PrimeFact(ll n){
    vector<ll> res;
    while(n!=1){
        if(n == 2 || n == 3){
            res.emplace_back(n); n/=n;
            continue;
        }
        bool prime_flag = false;
        for(int i = 2;i*i <= n;i++){
            if(n%i==0){
                res.emplace_back(i); n/=i;
                prime_flag = true;
                break;
            }
        }
        if(!prime_flag){res.emplace_back(n); n/= n;}
    }
    return res;
}

const ll MOD = 100000009;
ll solve(){
    ll res = 0;
    ll seed,N,K,B; cin >> seed >> N >> K >> B;
    auto primeB = PrimeFact(B);
    map<ll,int> mp;
    for(auto v:primeB) mp[v]++;
    sort(primeB.begin(),primeB.end());
    primeB.erase(unique(primeB.begin(),primeB.end()),primeB.end());
    
    vector<vector<int>> primenum(primeB.size(),vector<int>(N+1,0));
    
    vector<ll> X(N+1);
    X[0] = seed;
    for(int i = 1; i <= N; i++){ X[i] = 1 + (X[i-1]*X[i-1]+X[i-1]*12345)%MOD; }
    for(int i = 0; i <= N;i++){
        for(int j = 0; j < primeB.size();j++){
            while(X[i]%primeB[j] == 0){
                primenum[j][i]++;
                X[i]/=primeB[j];
            }
        }
    }
    
    res = LINF;
    for(int i = 0; i < primeB.size();i++){
        sort(primenum[i].begin(),primenum[i].end());
        ll T = 0;
        for(int j = 0; j < K; j++) T += primenum[i][j];
        res = min(res,T/mp[primeB[i]]);
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll Q; cin >> Q;
    while(Q--) cout << solve() << endl;
    return 0;
}
