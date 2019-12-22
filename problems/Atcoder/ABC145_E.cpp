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
 <url:https://atcoder.jp/contests/abc145/tasks/abc145_e>
 問題文============================================================
 E - All-you-can-eat
 =================================================================
 解説=============================================================

 この問題は最後の制約「時間T-1以内に注文したものであれば時間を超えても食べることができる」
 によって、食べる食品の選択の順番を考えなければならずナップサック問題に当てはまらない。
 しかし、時間T-1以内に限定してしまえばナップサック問題に落とし込める。
 そこで、i番目の料理の除いたN-1個について制限時間T-1のナップサック問題を解き、
 最後にi番目の料理の美味しさを足せばいい。

 この時、貪欲に計算するとO(N^2T)となり間に合わないので

 dp1[i][j] := 1〜i番目の料理をj分以内に食べるときの最大値
 dp2[i][j] := i〜N番目の料理をj分以内に食べるときの最大値

 を事前に計算することで
 i番目の料理を除いたN-1個についてのナップサック問題の解を
 dp1[i-1][j] + dp2[i+1][T-1-j]
 として求めることができ、計算量をO(NT)まで削減できる。

 https://atcoder.jp/contests/abc145/submissions/9043449
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,T; cin >> N >> T;
    vector<ll> A(N),B(N);
    for(int i = 0; i < N;i++){
        cin >> A[i] >> B[i];
    }

    vector<vector<ll>> dp1(N+1,vector<ll>(T));
    vector<vector<ll>> dp2(N+1,vector<ll>(T));

    auto chmax = [](ll& l,const ll r){
        l = max(l,r);
    };
    // 右から
    for(int i = 0; i < N;i++){
        for(int j = 0; j < T;j++){
            chmax(dp1[i+1][j],dp1[i][j]);
            if(j+A[i]<T) chmax(dp1[i+1][j+A[i]],dp1[i][j]+B[i]);
        }
    }
    // 左から
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < T;j++){
            chmax(dp2[i][j],dp2[i+1][j]);
            if(j+A[i]<T) chmax(dp2[i][j+A[i]],dp2[i+1][j]+B[i]);
        }
    }

    for(int i = 0; i < N;i++){
        for(int j = 0; j <= T-1;j++){
            res = max(res,dp1[i][j]+dp2[i+1][T-1-j]+B[i]);
        }
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
