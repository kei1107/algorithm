
/*
 1-index
 
 add : x に valを加算
 sum : [1,x] の総和を出力
 */
struct BIT {
    int N;
    vector<ll> bit;
    BIT(int N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, int val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    int sum(int x){
        int ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
};
