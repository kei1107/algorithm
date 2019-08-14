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
 <url:https://atcoder.jp/contests/abc136/tasks/abc136_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 参考
 http://kmjp.hatenablog.jp/entry/2019/08/06/1000
 
 この手の問題は、単純に数え上げるよりも
 各点について条件に合致するような個数がいくつか？と考えた方がいい
 
 今回の場合は各点についてその点が長方形領域に含まれる回数を数え上げる
 ================================================================
 */

/*
 BIT 1-index
 add : x に valを加算
 sum : [1,x] の総和を出力
 */
struct BIT {
    ll N;
    vector<ll> bit;
    BIT(ll N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, ll val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    ll sum(int x){
        ll ret = 0;
        if(x == 0) return ret;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
    // [l,r]
    ll sum(int l,int r){
        return sum(r) - sum(l-1);
    }
};

const ll MOD = 998244353;
template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<int> x(N),y(N);
    for(int i = 0; i < N;i++){
        cin >> x[i] >> y[i];
    }
    auto cx = x,cy = y;
    sort(cx.begin(),cx.end());
    sort(cy.begin(),cy.end());
    
    for(auto& v:x){
        v = (int)(lower_bound(cx.begin(),cx.end(),v) - cx.begin()) + 1;
    }
    for(auto& v:y){
        v = (int)(lower_bound(cy.begin(),cy.end(),v) - cy.begin()) + 1;
    }
    BIT bitl(N+1),bitr(N+1);
    vector<pii> ps(N);
    for(int i = 0; i < N;i++){
        ps[i] = {x[i],y[i]};
        bitr.add(y[i],1);
    }
    sort(ps.begin(),ps.end());
    
    vector<ll> pow2(N+1);
    pow2[0] = 1;
    for(int i = 1; i <= N;i++){
        pow2[i] = pow2[i-1] * 2 % MOD;
    }
    
    
    for(auto p:ps){
        int x,y; tie(x,y) = p;
        
        bitr.add(y,-1);
        
        for(int b = 0; b < (1<<4);b++){
            bool twice = ((b&5)==5)||((b&10)==10);
            
            ll val = 1;
            
            for(int i = 0; i < 4;i++){
                ll cnt = 1;
                if((b>>i)&1){
                    switch (i) {
                        case 0:
                            cnt = bitr.sum(y+1,N);
                            break;
                        case 1:
                            cnt = bitl.sum(y+1,N);
                            break;
                        case 2:
                            cnt = bitl.sum(y-1);
                            break;
                        case 3:
                            cnt = bitr.sum(y-1);
                            break;
                        default:
                            break;
                    }
                }
                (val *= (pow2[cnt]-1))%=MOD;
            }
            if(twice) (val *= 2)%=MOD;
            (res += val)%=MOD;
        }
        bitl.add(y,1);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);

    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
