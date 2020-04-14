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
 <url:https://atcoder.jp/contests/abc161/tasks/abc161_f>
 問題文============================================================
 F - Division or Subtraction
 =================================================================
 解説=============================================================
 
 N = n*K + m (0<= m < K)として、数式的に考える。
 
 この時、各処理は
 if m == 0
    N <- n
 else
    N <- (n-1)*K + m  (この処理は最終的にN <- N%Kと等しい)
 として表すことができる。
 
 ここで
 m = 0の時
    N = n*Kとなり、Kの候補はNの約数となる。
 m != 0の時
    上で示した後者の処理は最終的に N%K = mとなるので
    候補になるKはm = 1の時となる。
    よって m = 1として (N-1) = n*Kとなり Kの候補は(N-1)の約数となる
 
 約数はO(√N)で求めることができ、各約数に対する判定処理もO(logN)で判定可能となるため
 すべての該当する約数に対する処理を行えばこの問題は解ける。
    
 https://atcoder.jp/contests/abc161/submissions/11918441
 
 ================================================================
 */

void test(){
    for(ll N = 2; N <= 20; N++){
        ll cnt = 0;
        for(ll K = 2; K <= N; K++){
            ll T = N;
            while(T>1){
                if(T%K==0) T /= K;
                else T -= K;
            }
            if(T == 1) cnt++;
        }
        cout << N << " : " << cnt << endl;
    }
}

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

template<class Type>
Type solve(Type res = Type()){
    // test(); return res;
    ll N; cin >> N;
    /**
     * N = n*K + m ( 0<= m < K)
     * if m == 0
     *  N <-- n
     * else
     *  N <-- (n-1)*K + m
     *
     *
     * m => 1
     * N = n * K + 1
     * (N-1) = n * K // N-1の約数個可能
     * m => 0
     * N = n*K // Nの約数
     */
    
    set<ll> st;
    auto divisor1 = getdivisor(N);
    for(auto divisor:divisor1){
        if(divisor == 1) continue;
        ll T = N;
        ll K = divisor;
        
        while(T > 1){
            if(T%K == 0){
                T /= K;
            }else{
                if(T < K) break;
                T %= K;
            }
        }
        if(T == 1) st.insert(divisor);
    }
    auto divisor2 = getdivisor(N-1);
    for(auto divisor:divisor2){
        if(divisor == 1) continue;
        ll T = N;
        ll K = divisor;
        
        while(T > 1){
            if(T%K == 0){
                T /= K;
            }else{
                if(T < K) break;
                T %= K;
            }
        }
        
        if(T == 1) st.insert(divisor);
    }
    
    res = st.size();
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
