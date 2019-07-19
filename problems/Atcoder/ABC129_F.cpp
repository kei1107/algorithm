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
 <url:https://atcoder.jp/contests/abc129/tasks/abc129_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 行列累乗
 
 これは解説が分かりやすい -> https://img.atcoder.jp/abc129/editorial.pdf
 
 ある値Xの末尾にsを追加すると考えた時|s|がX桁とすれば
 
 (X,s,1) (10^d,0,0;1,1,0;0,0,1) ＝（X x 10^d + s,s+B,1)
 
 の形で表すことができる。
 これは行列として行列累乗で高速に計算できる。
 ================================================================
 */

typedef vector<ll> vec;
typedef vector<vec> mat;

/*
 行列累乗
 X = A^M*B
 A ( N*N行列)
 
 O(N^3 logM)
 */
mat mul(mat&A,mat&B,const ll M){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0; i < (int)A.size();i++){
        for(int k = 0; k < (int)B.size();k++){
            if(A[i][k] == 0) continue;
            for(int j = 0; j < B[0].size();j++){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j])%M;
            }
        }
    }
    return C;
}

mat pow(mat A,ll n,const ll M){
    mat B(A.size(),vec(A.size()));
    for(int i = 0; i < A.size();i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n&1) B= mul(B,A,M);
        A = mul(A,A,M);
        n>>=1;
    }
    return B;
}

ll pow10(ll n){
    ll ret = 1;
    while(n--) ret *= 10;
    return ret;
}
template<class Type>
Type solve(Type res = Type()){
    ll L,A,B,M; cin >> L >> A >> B >> M;
    ll cnt[19] = {};
    ll sum = 0;
    for(ll d = 1; d < 19; d++){
        ll p10 = pow10(d) - 1;
        if(A > p10) continue;
        ll p = (p10 - A)/B;
        ll q = (p+1) - sum;
        cnt[d] = q;
        
        if(cnt[d] > L - sum){
            cnt[d] = L - sum;
            break;
        }
        sum += q;
    }
    
    mat R = {
        {0},
        {A},
        {1},
    };
    for(ll d = 1; d < 19; d++){
        mat A = {
            {pow10(d)%M,1,0},
            {0,1,B},
            {0,0,1},
        };
        mat B = pow(A,cnt[d],M);
        
        R = mul(B,R,M);
    }
    res = R[0][0];
    return res;
}

void test(){
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
