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
 <url:https://atcoder.jp/contests/abc150/tasks/abc150_f>
 問題文============================================================
 F - Xor Shift
 =================================================================
 解説=============================================================
 b[j]==a[i]^xとなるようなxは1パターンしかないので
 そもそもN=2*10^5のような場合では、a'とbが等しくなるようなペアはほとんど無い
 問題なのは、a'とbが等しくなるような単独ペアが入力の中にたくさん埋め込まれたいるとき。
 
 という感じで考えると、bについて巡回する配列の任意位置からN個分取り出した配列について
 一致する者が他にどこにあるのかを高速に求めたくなる。
 
 これは、ローリングハッシュなどを用いることによってO(N)で求まる。
 
 判定部分については、Nが大きい時にN個全ての数値を比較しなければならない場合は滅多に無いので、矛盾を見つけたらすぐ処理を打ち切るようにして判定を行なっていけばいい。
 
 https://atcoder.jp/contests/abc150/submissions/9505232
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
    void init(const string& s) {
        q=1;
        n=(int)s.size();
        p.resize(n+1);hash.resize(n+1);p[0]=q;hash[0]=0;
        for(int i=0;i<n;i++){
            if(m == 0){p[i+1]=p[i]*base; hash[i+1]=s[i]+hash[i]*base;}
            else {p[i+1]=p[i]*base%m; hash[i+1]=(s[i]+hash[i]*base)%m;}
        }
    }
    void init(const vector<ll>& s) {
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
    int N; cin >> N;
    vector<ll> a(N),b(N);
    for(auto& in:a) cin >> in;
    for(auto& in:b) cin >> in;
    
    vector<ll> tb(2*N);
    for(int i = 0; i < 2*N;i++){
        tb[i] = b[i%N];
    }
    RH rhb;
    rhb.init(tb);
    
    map<ull,vector<int>> mp;
    for(int k = 0; k < N;k++){
        ull hash_b = rhb.h(k,k+N);
        mp[hash_b].push_back(k);
    }
    
    vector<pll> ans;
    for(auto p:mp){
        vector<int>& ks = p.second;
        
        bool ok = true;
        ll x = a[0]^b[ks[0]];
        for(int i = 1; i < N;i++){
            if(x == (a[i]^b[(i+ks[0])%N])) continue;
            ok = false;
            break;
        }
        
        if(ok){
            for(auto k:ks){
                ans.emplace_back((N-k)%N,x);
            }
        }
    }
    
    // cout << mp << endl;
    sort(ans.begin(),ans.end());
    for(auto p:ans){
        cout << p.first << " " << p.second << endl;
    }
    
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
