// ==================================================================================================== //
// Rolling hash No. 1 基本はこれを使う。衝突もhackも滅多にないと思う....
/*
 * Rolling hash
 * codeforcesでは GNU C++17 (64) にしないと動かないので注意
 */
// reference : https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
class RH{
public:
    using u64 = uint_fast64_t;
    using size_type = uint_fast32_t;
    using i128 = __int128_t;

    static constexpr u64 MOD = (1ull << 61) - 1;
    static constexpr u64 base = 20200819; // random

    string S;
    vector<u64> hash_,pow;

private:
    static constexpr u64 mask30 = (1ull << 30) - 1;
    static constexpr u64 mask31 = (1ull << 31) - 1;

    u64 mul(i128 a, i128 b) const{
        i128 t = a * b;
        t = (t >> 61) + (t & MOD);

        if(t >= MOD) return t - MOD;
        return t;
    }
    size_type xorshift(size_type x) const{
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        return x;
    }
public:
    RH(const RH &) = default;
    RH(RH&&) = default;

    RH():S(){}
    RH(const string& S) : S(S){
        size_type SL = (size_type)S.length();

        hash_.resize(SL+1,0);
        pow.resize(SL+1,1);
        for(size_type i = 0; i < SL; i++){
            hash_[i+1] = mul(hash_[i],base) + xorshift(S[i]+1);
            pow[i+1] = mul(pow[i],base);
            if(hash_[i+1] >= MOD) hash_[i+1] -= MOD;
        }
    }

    void apply(const char c){
        S.push_back(c);
        hash_.emplace_back(mul(hash_.back(),base) + xorshift(c+1));
        pow.emplace_back(mul(pow.back(),base));
        if(hash_.back() >= MOD) hash_.back() -= MOD;
    }
    u64 hash() const { return hash_.back(); }
    u64 hash(size_type r) const{
        return hash(0,r);
    }
    u64 hash(size_type l, size_type r) const{
        u64 ret = MOD + hash_[r] - mul(hash_[l],pow[r-l]);
        return ret < MOD ? ret : ret - MOD;
    }
    u64 back_hash(size_type i) const{
        size_type SL = (size_type)S.length();
        return hash(SL-i,SL);
    }

    // LCP : 最長共通接頭辞
    /*
     * 自身の部分文字列[l1,r1)とRH bの部分文字列[l2,r2)との最長共通接頭辞の右端を求める
     * 自身の部分文字列[l1,l1+戻り値)が最長共通接頭辞 (戻り値文の文字)
     */
    size_type LCP(const RH& b,size_type l1, size_type r1,size_type l2,size_type r2){
        size_type len = min(r1-l1,r2-l2);

        size_type l = 0, r = len+1;
        while(r-l>1){
            size_type m = (l+r)/2;
            if(this->hash(l1,l1+m) == b.hash(l2,l2+m)){
                l = m;
            }else{
                r = m;
            }
        }
        return l;
    }
    size_type LCP(const RH& b){
        return LCP(b,0,this->S.length(),0,b.S.length());
    }
    size_type size() const { return S.length(); }
};

void test(){
    RH rh1("abcdedfg");
    RH rh2("abcde");
    RH rh3("eeeeeefg");

    assert(rh1.hash() != rh2.hash());
    assert(rh1.hash(5) == rh2.hash());
    assert(rh1.back_hash(2) == rh3.back_hash(2));

    rh2.apply('d'); 
    assert(rh1.hash(6) == rh2.hash());
    rh2.apply('f'); 
    assert(rh1.hash(7) == rh2.hash());
    rh2.apply('g');
    assert(rh1.hash() == rh2.hash());

    assert(rh1.LCP(rh2) == rh1.S.length());

    // dfg x efg  -> 0 ()
    assert(rh1.LCP(rh3,5,8,5,8) == 0);
    // fg x fg -> 2 (fg)
    assert(rh1.LCP(rh3,6,8,6,8) == 2);

    RH rh4("abceeeee");
    RH rh5("abeeee");

    // abceeeee x abeeee -> 2 (ab)
    assert(rh4.LCP(rh5) == 2);
    // eeeee x eeee -> 4 (eeee)
    assert(rh4.LCP(rh5,3,8,2,6) == 4);
    // ee x eeee -> 2 (ee)
    assert(rh4.LCP(rh5,3,5,2,6) == 2);
}

// verified : https://atcoder.jp/contests/agc047/submissions/16040087
// verified : https://codeforces.com/contest/1016/submission/90378217
// verified : https://judge.yosupo.jp/submission/19404

// ================================================================================================================================= //
/*
 Rolling hash No. 2 蟻本仕様。高速だがhackの危険有
 */
struct RH {
public:
    vector<unsigned long long> p,hash;
    unsigned long long m,q;
    int n;
    void init(const string s) {
        // m=1000000007;
        m = 67280421310721;
        q=1;
        n=(int)s.size();
        p.resize(n+1);hash.resize(n+1);p[0]=q;hash[0]=0;
        for(int i=0;i<n;i++){p[i+1]=p[i]*m;hash[i+1]=s[i]+hash[i]*m;}
    }
    void apply(const char c){
        p.push_back(p[n]*m);
        hash.push_back(c+hash[n]*m);
        n++;
    }
    unsigned long long h(int i)const{return hash[i];}
    unsigned long long h(int i,int j)const{return h(j)-h(i)*p[j-i];}
    unsigned long long back_h(int i)const { return h(n) - h(n-i)*p[n-(n-i)]; }
};

// ================================================================================================================================= //
/*
 Rolling hash No. 3 ランダムbase　hackの危険性低　遅い　（場合によってはbaseを大きくしたほうがいいかもしれない）
 */
typedef unsigned long long ull;
const ull bases[64] = {259, 261, 264, 269, 270, 280, 281, 284, 285, 286, 288, 295, 298, 304, 307, 309, 310, 311, 312, 316, 318, 319, 322, 323, 328, 330, 348, 350, 352, 353, 355, 359, 360, 367, 378, 380, 381, 382, 384, 390, 393, 394, 395, 397, 398, 399, 402, 410, 412, 413, 414, 416, 417, 424, 434, 435, 438, 440, 442, 449, 450, 462, 463, 464};
struct RH {
public:
    vector<ull> p,hash;
    int n;
    const static ull base;
    ull m,q;
    RH(){
        // m : 1000000007, 1000000009, 1000000021...
        m=1000000007;
    }
    void init(const string s) {
        q=1;
        n=(int)s.size();
        p.resize(n+1);hash.resize(n+1);p[0]=q;hash[0]=0;
        for(int i=0;i<n;i++){
            if(m == 0){p[i+1]=p[i]*base; hash[i+1]=s[i]+hash[i]*base;}
            else {p[i+1]=p[i]*base%m; hash[i+1]=(s[i]+hash[i]*base)%m;}
        }
    }
    void apply(const char& c){
        if(m == 0){
            p.push_back(p[n]*base);
            hash.push_back(c+hash[n]*base);
        }else{
            p.push_back(p[n]*base%m);
            hash.push_back((c+hash[n]*base)%m);
        }
        n++;
    }
    ull h(int i)const{return hash[i];}
    ull h(int i,int j)const{
        if(m==0) return h(j)-h(i)*p[j-i];
        else return (h(j)-h(i)*p[j-i]%m+m)%m;
    }
    ull back_h(int i)const { return h(n-i,n); }
    int LCP(const RH &b,int l1,int r1,int l2,int r2){
        int len = min(r1-l1,r2-l2);
        int l = -1,r = len+1;
        while(r-l>1){
            int m = (l+r)/2;
            if(this->h(l1,l1+m) == b.h(l2,l2+m)){
                l = m;
            }else{
                r = m;
            }
        }
        return l;
    }
};
const ull RH::base = bases[chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count() & 63];

