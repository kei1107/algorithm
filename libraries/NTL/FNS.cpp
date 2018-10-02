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


// ============= //
/*
 階乗進数
 順列を階乗進数で表す事ができる。
 このとき、その順列の転倒数は階乗進数の各桁の和に等しくなる
*/
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


// verify: yukicoder271
// https://yukicoder.me/problems/no/271
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
