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
ostream& operator<<(ostream& out, const pair<S, T>& o) {
    out << "(" << o.first << "," << o.second << ")";
    return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& V) {
    for (int i = 0; i < V.size(); i++) {
        out << V[i];
        if (i != V.size() - 1) out << " ";
    }
    return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<vector<T>>& Mat) {
    for (int i = 0; i < Mat.size(); i++) {
        if (i != 0) out << endl;
        out << Mat[i];
    }
    return out;
}
template <class S, class T>
ostream& operator<<(ostream& out, const map<S, T>& mp) {
    out << "{ ";
    for (auto it = mp.begin(); it != mp.end(); it++) {
        out << it->first << ":" << it->second;
        if (mp.size() - 1 != distance(mp.begin(), it)) out << ", ";
    }
    out << " }";
    return out;
}
template <typename T>
vector<T> make_v(size_t a) {
    return vector<T>(a);
}
template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T& t, const V& v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T& t, const V& v) {
    for (auto& e : t) fill_v(e, v);
}
/*
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template <class Type>
Type solve(Type res = Type()) {
    int H, W;
    cin >> H >> W;
    int Ch, Cw, Dh, Dw;
    cin >> Ch >> Cw >> Dh >> Dw;
    Ch--;
    Cw--;
    Dh--;
    Dw--;

    vector<vector<char>> S(H, vector<char>(W));
    for (auto& vec : S)
        for (auto& in : vec) cin >> in;

    auto dist = make_v<int>(H, W);
    fill_v(dist, INF);

    using Item = tuple<int, int, int>;
    priority_queue<Item, vector<Item>, greater<Item>> pq;

    pq.emplace(0, Ch, Cw);
    dist[Ch][Cw] = 0;

    int dir[4] = {1, 0, -1, 0};

    while (pq.size()) {
        int cost, h, w;
        tie(cost, h, w) = pq.top();
        pq.pop();
        if (dist[h][w] < cost) continue;

        for (int k = 0; k < 4; k++) {
            int nh = h + dir[k];
            int nw = w + dir[k ^ 1];

            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if(S[nh][nw] == '#') continue;
            if (dist[nh][nw] > dist[h][w]) {
                dist[nh][nw] = dist[h][w];
                pq.emplace(dist[nh][nw], nh, nw);
            }
        }

        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                int nh = h + i;
                int nw = w + j;

                if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
                if(S[nh][nw] == '#') continue;
                if (dist[nh][nw] > dist[h][w] + 1) {
                    dist[nh][nw] = dist[h][w] + 1;
                    pq.emplace(dist[nh][nw], nh, nw);
                }
            }
        }
    }

    // cout << dist << endl;

    res = dist[Dh][Dw];

    if(res == INF) res = -1;
    return res;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}