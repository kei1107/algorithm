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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_cc>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

// ==================== //
/* BIT2D
 rangeUpdate 閉区間
 rangeSum 閉区間
 */
class BIT2D {
private:
    int N, M;
    vector<vector<vector<ll> > > bit;
    void updateTillEnd(int x, int y, ll v);
    ll queryTillEnd(int x, int y);
public:
    BIT2D(vector<vector<ll> > A);
    void rangeUpdate(int x1, int y1, int x2, int y2, ll val);
    ll rangeQuery(int x1, int y1, int x2, int y2);
};

BIT2D::BIT2D(vector<vector<ll> > A) {
    N = A.size();
    M = A[0].size();
    bit = vector<vector<vector<ll> > > (4, vector<vector<ll> > (N + 1, vector<ll> (M + 1, 0)));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            rangeUpdate(i, j, i, j, A[i - 1][j - 1]);
        }
    }
}

void BIT2D::updateTillEnd(int x, int y, ll v) {
    if (x < 0 || y < 0 || x > N || y > M) {
        return;
    }
    for (int i = x, c = x - 1, d = y - 1; i <= N; i += i & -i) {
        for (int j = y; j <= M; j += j & -j) {
            bit[0][i][j] += v;
            bit[1][i][j] += v * d;
            bit[2][i][j] += v * c;
            bit[3][i][j] += v * c * d;
        }
    }
}

ll BIT2D::queryTillEnd(int x, int y) {
    ll p, q, r, m, n;
    p = q = r = 0;
    for (int i = x; i > 0; i -= i & -i) {
        m = n = 0;
        for (int j = y; j > 0; j -= j & -j) {
            m += bit[0][i][j];
            n += bit[1][i][j];
            q += bit[2][i][j];
            r += bit[3][i][j];
        }
        p += (m * y) - n;
    }
    return (p * x) - (q * y) + r;
}

void BIT2D::rangeUpdate(int x1, int y1, int x2, int y2, ll val) {
    updateTillEnd(x1, y1, val);
    updateTillEnd(x2 + 1, y1, -val);
    updateTillEnd(x1, y2 + 1, -val);
    updateTillEnd(x2 + 1, y2 + 1, val);
}

ll BIT2D::rangeQuery(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) {
        return 0;
    }
    return queryTillEnd(x2, y2) - queryTillEnd(x1 - 1, y2) - queryTillEnd(x2, y1 - 1) + queryTillEnd(x1 - 1, y1 - 1);
}


template<class Type>
Type solve(Type res = Type()){
    int N,K; cin >> N >> K;
    vector<int> A(N),B(N);

    int LIM = 5000;
    auto T = make_v<ll>(LIM+1,LIM+1);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        T[A[i]][B[i]]++;
    }

    for(int i = 1; i <= LIM; i++) T[0][i] += T[0][i-1];
    for(int i = 1; i <= LIM; i++) T[i][0] += T[i-1][0];

    for(int i = 1; i <= LIM;i++){
        for(int j = 1; j <= LIM; j++){
            T[i][j] += T[i-1][j] + T[i][j-1] - T[i-1][j-1];
        }
    }

    // cout << T << endl;

    for(int lx = 1; lx <= LIM; lx++){
        for(int ly = 1; ly <= LIM; ly++){
            int rx = min(lx+K,LIM);
            int ry = min(ly+K,LIM);

            ll S = T[rx][ry] - T[lx-1][ry] - T[rx][ly-1] + T[lx-1][ly-1];

            res = max(res,S);
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