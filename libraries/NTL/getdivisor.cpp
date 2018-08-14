// nの約数を列挙する
vector<ll> getdivisor(ll n){
    vector<ll> res;
    for(ll i = 1; i*i <= n;i++){
        if(n%i == 0) {
            res.push_back(i);
            if(n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
