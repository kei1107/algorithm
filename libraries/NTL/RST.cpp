// ref : https://qiita.com/drken/items/ae02240cd1f8edfc86fd
// ================================================= //

/*
 中国剰余定理 (Chinese Remainder Theorem)
 x ≡ b1 (mod. m1)
 x ≡ b2 (mod. m2)
 ...
 x ≡ bk (mod. mk)
 を満たす x ≡ r (mod. lcm(m1,m2,...,mk)) を求める
 
 答えを x ≡ r (mod. M) として、{r, M} をリターン, 存在しない場合は {0, -1} をリターン
 */
inline ll mod(ll a,ll m){ return (a%m + m)%m;}
/* 拡張ユークリッドの互除法 extgcd */
ll extgcd(ll a, ll b, ll& x, ll& y){
    ll g = a; x = 1; y = 0;
    if(b!=0) { g = extgcd(b, a%b, y, x); y -= (a/b)*x;}
    return g;
}
pll CRT(const vector<ll>& b,const vector<ll>& m){
    ll r = 0, M = 1;
    for(int i = 0; i < (int)b.size();i++){
        ll p,q;
        ll d = extgcd(M,m[i],p,q);
        if((b[i]-r)%d != 0) return make_pair(0,-1);
        ll tmp = (b[i]-r)/d*p%(m[i]/d);
        r += M*tmp;
        M *= m[i]/d;
    }
    return make_pair(mod(r,M), M);
}

// ================================================= //


// https://yukicoder.me/problems/no/186
ll solve(){
    vector<ll> b(3),m(3);
    for(int i = 0; i < 3;i++) cin >> b[i] >> m[i];
    pll res = CRT(b,m);
    if(res.second == -1) return -1;
    if(count(b.begin(),b.end(),0)==3) return res.second; // lcm(m1,m2,m3)
    return res.first;
}


// ============================================== //
// 巨大な数字を扱う場合

const ll MOD = 1e9+7;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

/*
 Garner のアルゴリズムの前処理
 
 Garnerのアルゴリズムを適応するには m1...mkが互いに素でなければならない
 => b ≡ m が互いに素になるような前処理
 */
ll PreGarner(vector<ll> &b, vector<ll> &m, ll MOD) {
    ll res = 1;
    for (int i = 0; i < (int)b.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            ll g = gcd(m[i], m[j]);
            if ((b[i] - b[j]) % g != 0) return -1;
            m[i] /= g;
            m[j] /= g;
            ll gi = gcd(m[i], g), gj = g/gi;
            do { g = gcd(gi, gj); gi *= g; gj /= g; } while (g != 1);
            m[i] *= gi; m[j] *= gj;
            b[i] %= m[i]; b[j] %= m[j];
        }
    }
    for (int i = 0; i < (int)b.size(); ++i) (res *= m[i]) %= MOD;
    return res;
}


inline ll mod(ll a,ll m){ return (a%m + m)%m;}
/* 拡張ユークリッドの互除法 extgcd */
ll extgcd(ll a, ll b, ll& x, ll& y){
    ll g = a; x = 1; y = 0;
    if(b!=0) { g = extgcd(b, a%b, y, x); y -= (a/b)*x;}
    return g;
}
// 逆元計算 (a,mが違いに素)
ll modinv(ll a,ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return mod(x,m);
}


// Garner のアルゴリズム, x%MOD, LCM%MOD を求める (m は互いに素でなければならない)
//
// 巨大な数字に適応可能
//
// for each step, we solve "coeffs[k] * t[k] + constants[k] = b[k] (mod. m[k])"
//      coeffs[k] = m[0]m[1]...m[k-1]
//      constants[k] = t[0] + t[1]m[0] + ... + t[k-1]m[0]m[1]...m[k-2]
ll Garner(vector<ll> b, vector<ll> m, ll MOD) {
    m.push_back(MOD);
    vector<ll> coeffs((int)m.size(), 1);
    vector<ll> constants((int)m.size(), 0);
    for (int k = 0; k < (int)b.size(); k++) {
        ll t = mod((b[k] - constants[k]) * modinv(coeffs[k], m[k]), m[k]);
        for (int i = k+1; i < (int)m.size(); ++i) {
            (constants[i] += t * coeffs[i]) %= m[i];
            (coeffs[i] *= m[k]) %= m[i];
        }
    }
    return constants.back();
}
// ============================================== //
// https://qiita.com/drken/items/ae02240cd1f8edfc86fd

ll solve(){
    ll N; cin >> N;
    vector<ll> b(N),m(N);
    for(int i = 0; i < N;i++) cin >> b[i] >> m[i];
    ll LCM = PreGarner(b, m, MOD);
    if(LCM == -1) return -1;
    if(count(b.begin(),b.end(),0)==N) return LCM;
    return Garner(b, m, MOD);
}
// ============================================== //


