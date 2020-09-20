/**
 * Smalest number m such that m(m+1)/2 is divisible by n.
 * https://oeis.org/A011772
 *
 * Func : fix
 *  INPUT : N (<= 10^15)
 *  OUTPOT : Smalest number m such that m(m+1)/2 is divisible by N.
 * O(√N log N)
 */
class FindSmallestNumber_Sum_is_divisible_by_N{
private:
    ll LatestSmallestNumber;
    vector<ll> divisors;
public:
    FindSmallestNumber_Sum_is_divisible_by_N():LatestSmallestNumber(-1){}
    FindSmallestNumber_Sum_is_divisible_by_N(ll N){
        fix(N);
    }
    ll fix(ll N){
        LatestSmallestNumber = numeric_limits<ll>::max();
        calcdivisor(2*N);
        for(auto x:divisors){
            ll y = 2*N/x;
            
            ll cand = CRT(vector<ll>{0,-1},vector<ll>{x,y}).first;
            if(cand == 0) continue;
            LatestSmallestNumber = min(LatestSmallestNumber,cand);
        }
        assert(LatestSmallestNumber != numeric_limits<ll>::max());
        return LatestSmallestNumber;
    }
    ll getSmallestNumber(){ return LatestSmallestNumber; }
private:
    void calcdivisor(ll n){
        divisors.clear();
        for(ll i = 1; i*i <= n;i++){
            if(n%i == 0) {
                divisors.push_back(i);
                if(n/i != i) divisors.push_back(n/i);
            }
        }
        sort(divisors.begin(),divisors.end());
    }
    
    inline ll mod(ll a,ll m){ return (a%m + m)%m;}
    /* 拡張ユークリッドの互除法 extgcd */
    static ll extgcd(ll a, ll b, ll& x, ll& y){
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

};


// verified : https://atcoder.jp/contests/acl1/tasks/acl1_b
// submit : https://atcoder.jp/contests/acl1/submissions/16922689
// 375 ms
template<class Type>
Type solve(Type res = Type()){
    res = numeric_limits<ll>::max();
    ll N; cin >> N;
    FindSmallestNumber_Sum_is_divisible_by_N Searcher(N);
    res = Searcher.getSmallestNumber();
    return res;
}
