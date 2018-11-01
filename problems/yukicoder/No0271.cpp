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
 <url:https://yukicoder.me/problems/no/271>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 https://yukicoder.me/problems/no/271/editorial
 解説を見た
 
 階乗進数で順列を表現できるということは良い、知見になった
 ================================================================
 */

struct BIT {
    ll N;
    vector<ll> bit;
    BIT(ll N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(ll x, ll val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    ll sum(ll x){
        ll ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
};

const ll MOD = 1e9+7;
struct FNS{
    vector<ll> F;
    vector<ll> fact;
    ll Inv[5]; // 2の逆元
    FNS(vector<ll> permutation):F(permutation.size()),fact(permutation.size()+5){
        BIT bit(permutation.size());
        fact[0] = 1;
        for(ll i = 1; i < fact.size();i++) fact[i] = i*fact[i-1]%MOD;
        Inv[0] = 0; Inv[1] = 1;
        for(int i = 2; i < 5;i++) Inv[i] = Inv[MOD%i] * (MOD - MOD/i) % MOD;
        for(int i = (int)permutation.size()-1; i >= 0; i--){
            F[i] = bit.sum(permutation[i]);
            bit.add(permutation[i],1);
        }
    }
    // 返却　繰り上がり回数
    ll add(ll K){
        for(ll i = 0; i < F.size();i++){
            ll T = K+F[F.size()-1-i];
            F[F.size()-1-i]=T%(i+1); K=T/(i+1);
        }
        return K;
    }
    // 初期状態からFの状態になるまでの転倒数の総和
    ll invsum(){
        ll ret = 0;
        ll t1 = 0,t2 = 1;
        for(ll i = F.size()-1; i >= 0; i--){
            ll n = F.size()-1-i;
            (ret+=F[i]*fact[n]%MOD*n%MOD*(n-1+MOD)%MOD*Inv[4]%MOD)%=MOD;
            (ret+=t2*F[i]%MOD*(F[i]-1+MOD)%MOD*Inv[2]%MOD)%=MOD;
            (ret+=F[i]*t1%MOD)%=MOD;
            (t1+=F[i]*t2%MOD)%=MOD;
            (t2*=(F.size()-i+MOD)%MOD)%=MOD;
        }
        return ret;
    }
};

ll solve(){
    ll N,K; cin >> N >> K;
    vector<ll> p(N);
    for(auto& in:p) cin >> in;
    FNS fns(p);
    ll linv = fns.invsum();
    ll mul = fns.add(K);
    ll rinv = fns.invsum();
    ll res = 0;
    res = mul*fns.fact[N]%MOD*N%MOD*(N-1+MOD)%MOD*fns.Inv[4]%MOD + (rinv - linv + MOD)%MOD;
    res %= MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
