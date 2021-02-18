#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template <class S, class T>
ostream &operator<<(ostream &out, const pair<S, T> &o) {
    out << "(" << o.first << "," << o.second << ")";
    return out;
}
template <class T> ostream &operator<<(ostream &out, const vector<T> &V) {
    for(int i = 0; i < V.size(); i++) {
        out << V[i];
        if(i != V.size() - 1)
            out << " ";
    }
    return out;
}
template <class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &Mat) {
    for(int i = 0; i < Mat.size(); i++) {
        if(i != 0)
            out << endl;
        out << Mat[i];
    }
    return out;
}
template <class S, class T>
ostream &operator<<(ostream &out, const map<S, T> &mp) {
    out << "{ ";
    for(auto it = mp.begin(); it != mp.end(); it++) {
        out << it->first << ":" << it->second;
        if(mp.size() - 1 != distance(mp.begin(), it))
            out << ", ";
    }
    out << " }";
    return out;
}
template <typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) {
    for(auto &e : t)
        fill_v(e, v);
}
/*
 <url:https://atcoder.jp/contests/abc189/tasks/abc189_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template <class Type> Type solve(Type res = Type()) {
    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    int M; cin >> M;

    auto R = make_v<ll>(M, 3, 3);
    for(int i = 0; i < M; i++) {
        int t; ll p;
        cin >> t;
        switch(t) {
            case 1:
                R[i] = vector<vector<ll>>{
                        { 0, 1, 0},
                        {-1, 0, 0},
                        { 0, 0, 1} 
                        };
                break;
            case 2:
                R[i] = vector<vector<ll>>{
                        { 0,-1, 0},
                        { 1, 0, 0},
                        { 0, 0, 1} 
                        };
                break;
            case 3:
                cin >> p;
                R[i] = vector<vector<ll>>{
                        {-1, 0, 2*p},
                        { 0, 1, 0},
                        { 0, 0, 1} 
                        };
                break;
            case 4:
                cin >> p;
                R[i] = vector<vector<ll>>{
                        { 1, 0, 0},
                        { 0,-1, 2*p},
                        { 0, 0, 1} 
                        };
                break;
            default:
                assert(false);
        }
    }
    int Q; cin >> Q;
    vector<vector<pll>> Bs(M+1);
    for(int q = 0; q < Q;q++){
        ll A,B; cin >> A >> B;
        B--;
        Bs[A].emplace_back(B,q);
    }

    auto NR = vector<vector<ll>>{
        { 1, 0, 0},
        { 0, 1, 0},
        { 0, 0, 1}
    };
    vector<pll> ans(Q,pll(LINF,LINF)); 
    for(int m = 0; m <= M; m++){
        for(auto [b,id]:Bs[m]){
            ans[id].first   = NR[0][0] * X[b] + NR[0][1] * Y[b] + NR[0][2];
            ans[id].second  = NR[1][0] * X[b] + NR[1][1] * Y[b] + NR[1][2];
        }
        
        if(m != M){
            auto T = make_v<ll>(3,3);
            for(int i = 0; i < 3;i++){
                for(int j = 0; j < 3;j++){
                    for(int k = 0; k < 3;k++){
                        T[i][k] += R[m][i][j] * NR[j][k];
                    }
                }
            }
            NR = T;
        }
    }

    for(auto A:ans)cout << A.first << " " << A.second << endl;

    return res;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}