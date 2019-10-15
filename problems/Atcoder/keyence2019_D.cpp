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
 <url:https://atcoder.jp/contests/keyence2019/tasks/keyence2019_d>
 問題文============================================================
 =================================================================
 解説=============================================================

 >> https://img.atcoder.jp/keyence2019/editorial.pdf
 ================================================================
 */


const ll MOD = 1e9+7;

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

template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    vector<ll> A(N),B(M);
    vector<ll> cntA(N*M+1),cntB(N*M+1);
    for(auto& in:A){ cin >> in; cntA[in]++;}
    for(auto& in:B){ cin >> in; cntB[in]++;}
    
    BIT bitA(N*M),bitB(N*M);
    for(int i = 1; i <= N*M;i++){
        if(cntA[i] >= 2 || cntB[i] >= 2) return 0;
        bitA.add(i,cntA[i]);
        bitB.add(i,cntB[i]);
    }

    res = 1;
    for(int x = N*M; x >= 1;x--){
        if(cntA[x] >= 2 || cntB[x] >= 2) res = 0;
        
        ll L = 1,R = 1;
        if(cntA[x] == 0) L = bitA.sum(x,N*M);
        if(cntB[x] == 0) R = bitB.sum(x,N*M);
        
        if(cntA[x] == 0 && cntB[x] == 0) (res *= L*R-(N*M-x))%=MOD;
        else (res *= L*R)%=MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
