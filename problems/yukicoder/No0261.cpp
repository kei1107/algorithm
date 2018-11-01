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
 <url:https://yukicoder.me/problems/no/261>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ある値iがjになるのに必要なあみだの数をxi、またそのときたどる巡回路の周期をdiとすると
 
 全ての値がAと一致するには
 X = x1 (mod d1)
 X = x2 (mod d2)
 ...
 X = xN (mod dN)
 
 となるような最小のXを見つけ出せばいいことがわかる
 これは、中国剰余定理の形そのままなので　はい
 ================================================================
 */
inline ll mod(ll a,ll m){ return (a%m + m)%m;}
/* 拡張ユークリッドの互除法 extgcd */
ll extgcd(ll a, ll b, ll& x, ll& y){
    ll g = a; x = 1; y = 0;
    if(b!=0) { g = extgcd(b, a%b, y, x); y -= (a/b)*x;}
    return g;
}

/*
 中国剰余定理 (Chinese Remainder Theorem)
 x ≡ b1 (mod. m1)
 x ≡ b2 (mod. m2)
 ...
 x ≡ bk (mod. mk)
 を満たす x ≡ r (mod. lcm(m1,m2,...,mk)) を求める
 
 答えを x ≡ r (mod. M) として、{r, M} をリターン, 存在しない場合は {0, -1} をリターン
 */
pll CRT(const vector<ll>& b,const vector<ll>& m){
    ll r = 0, M = 1;
    for(int i = 0; i < (int)b.size();i++){
        ll p,q;
        ll d = extgcd(M,m[i],p,q);
        if((b[i]-r)%d != 0) return make_pair(0,-1);
        ll tmp = (b[i]-r)/d*p%(m[i]/d);
        r += M*tmp;
        M *= m[i]/d;
    }
    return make_pair(mod(r,M), M);
}

void solve(){
    int N; cin >> N;
    int K; cin >> K;
    vector<int> amida(N); iota(amida.begin(),amida.end(),0);
    vector<int> X(K),Y(K);
    for(int i = 0; i < K;i++){
        cin >> X[i] >> Y[i];
        X[i]--; Y[i]--;
    }
    reverse(X.begin(),X.end()); reverse(Y.begin(),Y.end());
    for(int i = 0; i < K;i++){
        swap(amida[X[i]],amida[Y[i]]);
    }
    
    vector<vector<int>> ito(N,vector<int>(N,-1));
    vector<int> D(N);
    for(int i = 0; i < N;i++){
        vector<int> f(N,0);
        int now = i;
        int cnt = 0;
        while(f[now]==0){
            f[now] = 1;
            ito[i][now] = cnt++;
            now = amida[now];
        }
        D[i] = cnt;
    }
    int Q; cin >> Q;
    while(Q--){
        vector<int> A(N); for(auto& in:A){ cin >> in; in--; }

        vector<ll> b(N),m(N);
        bool fail = false;
        for(int i = 0; i < N;i++){
            b[i] = ito[i][A[i]];
            m[i] = D[i];
            if(b[i]==-1) fail = true;
        }
        if(fail){
            cout << -1 << endl;
            continue;
        }
        auto p = CRT(b,m);
        if(p.second==-1){
            cout << -1 << endl;
            continue;
        }
        cout << p.second - p.first << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
