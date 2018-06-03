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
 <url:https://yukicoder.me/problems/no/109>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 色々な考えの掛け合わせ。
 
 まず、N>=Mの時は明らかに0
 M <= 200000 ぐらいの時は愚直に計算
 それ以外の時で　Mが素数ならばウィルソンの定理を使う。
                合成数ならば必ずMの素因数がN以下で存在するので0
 
 ================================================================
 */


ll MOD =0;
// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}

bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

ll solve(ll N,ll M){
    ll res = 0;
    MOD = M;
    if(N >= M) return res;
    if(M <= 200000){
        res = 1%M;
        while(N){ (res *= N--)%=M; }
        return res;
    }
    if(IsPrime(M)){
        res = M-1;
        for(ll X = N+1; X < M;X++){
            res = (res * inversemod(X))%MOD;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll T; cin >> T;
    while(T--){
        ll N,M; cin >> N >> M;
        cout << solve(N,M) << endl;
    }
    return 0;
}
