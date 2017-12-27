
ll comb[MAX_N+1][MAX_N+1];
for (int i = 0; i <= MAX_N; i++) {
    for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i)
            comb[i][j] = 1;
        else
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
}

＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝


単一の逆元は、
Int inv[1000010];
inv[1] = 1;
for (int i = 2; i <= N; ++i)
inv[i] = P - (P / i) * inv[P % i] % P;　(mod P)

として求めることができる。これを用いて階乗とその逆元は
Int fac[1000010], facInv[1000010];
fac[0] = facInv[0] = 1;
for (int i = 1; i <= N; ++i) {
  fac[i] = (fac[i - 1] * i) % P;
  facInv[i] = (facInv[i - 1] * inv[i]) % P;
}


ll fact[MAX], rfact[MAX];

ll mod_pow(ll x, ll p, ll mod) {
    ll a = 1;
    while (p) {
        if (p % 2) a = a * x % mod;
        x = x * x % mod;
        p /= 2;
    }
    return a;
}

//逆元
ll mod_inverse(ll a, ll m) {
    return mod_pow(a, m - 2, m);
}

ll nCr(int n, int r) {
    return fact[n] * rfact[r] % MOD * rfact[n - r] % MOD;
}

============================================================
C(n,m) = C(n,m-1) * (n-m+1) / m.
C(n,m) = C(n,n-m)

ll C(int n,int m){
    m = m<(n-m) ? m : (n-m);
    if(m == 0) return 1;
    ll ans = 1;
    for(int i=1;i<=m;i++){
        ans = ans *(n-i+1)/i;
    }
    return ans;
}
