// return (a * b) % m
ll mul_mod(ll a,ll b,ll m){
    ll res = 0;
    ll exp = a%m;
    while(b){
        if(b&1){
            res += exp;
            if(res > m) res -= m;
        }
        exp <<= 1;
        if(exp > m) exp -= m;
        b >>= 1;
    }
    return res;
}
