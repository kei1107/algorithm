// Tetration a↑↑b mod m
ll powmod(ll a,ll b,ll m) {ll res=1;a%=m;for(;b;b>>=1){if(b&1)res=res*a%m;a=a*a%m;}return res;}
ll Euler_Phi(ll m) {
    if(m==0)return 0;
    ll res = m;
    for (ll i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            res = res / i * (i - 1); while(m % i == 0) m/=i;
        }
    }
    if (m != 1) res = res / m * (m - 1);
    return res;
}

vector<ll> Phi;
void initPhi(ll MAXM){
    Phi.clear(); Phi.resize(MAXM);
    for(int i = 1; i < MAXM;i++) Phi[i] = Euler_Phi(i);
}

ll greedy_test(ll a,ll n,ll m){
    if(a == 1) return 1;
    ll ret = 1;
    for(int i = 0; i < n;i++){
        ll t = ret; ret = 1;
        for(int j = 0; j < t;j++){
            ret *= a;
            if(ret>=m) return m;
        }
    }
    return ret;
}
// a↑↑b mod m
ll tetration(ll a,ll b,ll m){
    if(m == 1) return 0;
    if(a == 1 || b == 0) return 1;
    ll t = greedy_test(a,b-1,m+1);
    if(t <= m) return powmod(a,t,m);
    return powmod(a,m+(tetration(a, b-1,Phi[m])-m)%Phi[m],m);
}

ll solve(){
    ll res = 0;
    ll A,N,M; cin >> A >> N >> M;
    initPhi(M+1);
    res = tetration(A, N, M);
    return res;
}
