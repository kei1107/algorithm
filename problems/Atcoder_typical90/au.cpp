#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_au>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

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

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    string S,T; cin >> S >> T;

    string baseR = T,baseG = T,baseB = T;
    {
        replace(baseR.begin(),baseR.end(),'B','@');
        replace(baseR.begin(),baseR.end(),'G','B');
        replace(baseR.begin(),baseR.end(),'@','G');
    }
    {
        replace(baseG.begin(),baseG.end(),'B','@');
        replace(baseG.begin(),baseG.end(),'R','B');
        replace(baseG.begin(),baseG.end(),'@','R');
    }
    {
        replace(baseB.begin(),baseB.end(),'G','@');
        replace(baseB.begin(),baseB.end(),'R','G');
        replace(baseB.begin(),baseB.end(),'@','R');
    }

    RH rhs(S),rhr(baseR),rhg(baseG),rhb(baseB);

    for(int i = 1; i <= N;i++){
        res += (rhs.hash(i)==rhr.back_hash(i)) + (rhs.hash(i)==rhg.back_hash(i)) + (rhs.hash(i)==rhb.back_hash(i));

        if(i != N){
            res += (rhs.back_hash(i)==rhr.hash(i)) + (rhs.back_hash(i)==rhg.hash(i)) + (rhs.back_hash(i)==rhb.hash(i));
        }
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}