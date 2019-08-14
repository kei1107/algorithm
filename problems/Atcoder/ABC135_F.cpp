#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc135/tasks/abc135_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 事前に十分にsを連結しておく
 （自分はtの長さの5倍以上ぐらい）
 
 この状態でsにtが連続して最大でいくつ含まれるかを求めたい
 これはローリングハッシュとdpで簡単に求まる
 
 その後、最大値+1 >= tの長さ/sの長さ
 であればどれだけtを連結させてもsの部分列になるため-1とすればいい
 ================================================================
 */

/*
 Rolling hash
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
    ull bach_h(int i)const { return h(n-i,n); }
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


template<class Type>
Type solve(Type res = Type()){
    string s,t; cin >> s >> t;
    int tlen = (int)t.length();
    while(s.length() <= 5*tlen) s += s;
    s += s;
    
    int slen = (int)s.length();
    RH rhs,rht;
    rhs.init(s); rht.init(t);
    vector<ll> dp(s.length()+1);
    
    for(int i = 0; i <= slen-tlen;i++){
        if(rhs.h(i,i+tlen) == rht.h(tlen)){
            dp[i+tlen] = dp[i] + 1;
        }
    }
    res = *max_element(dp.begin(), dp.end());
    
    if(res+1 >= s.length()/t.length()){
        return -1;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
