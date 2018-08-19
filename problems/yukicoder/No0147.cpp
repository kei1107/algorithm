#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/147>
 問題文============================================================
 =================================================================
 解説=============================================================
 下にあるtest関数を実行して、椅子の数に対する座れる場合の数を数えると
 フィボナッチ数となっていることがわかる
 
 よってフィボナッチ数は行列べき乗を行うことで任意のFnを求めることができるため、
 計算を行うことが可能
 
 Dは巨大な値なので文字列からmodをとって計算するが、指数部分に相当する値になるため、
 mod-1 をとっていく
 ================================================================
 */

const ll MOD = 1e9+7;
void test(){
    for(int i = 1; i <= 10;i++){
        int cnt = 0;
        for(int j = 0; j < (1<<i);j++){
            cnt++;
            for(int k = 0; k < i;k++){
                if(((j>>k)&1)&((j>>(k+1))&1)){
                    cnt--;
                    break;
                }
            }
        }
        cout << i << " " << cnt << endl;
    }
    
}

ll mod(string& S){
    ll ret = 0;
    for(auto& c:S){
        ret = (ret*10 + c - '0')%(MOD-1);
    }
    return ret;
}

typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat&A,mat&B,const ll M){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0; i < (int)A.size();i++){
        for(int k = 0; k < (int)B.size();k++){
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
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

ll solve(){
    ll res = 1;
    ll N; cin >> N;
    while(N--){
        ll C; string D; cin >> C >> D;
        mat A = {{1,1},{1,0}};
        ll n = C+2;
        auto F = pow(A,n,MOD);
        if(F[0][1]%MOD == 0) res = 0;
        (res *=  powmod(F[0][1]%MOD,mod(D)))%=MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    //test();
    cout << solve() << endl;
    return 0;
}
