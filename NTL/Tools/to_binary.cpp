inline string to_bin_str(ll n){
    string str;
    while(n>0){
        str.push_back('0' + (n&1));
        n>>=1;
    }
    reverse(str.begin(), str.end());
    return str;
}
