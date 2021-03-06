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
ostream& operator<<(ostream& out, const vector<vector<T> >& Mat) {
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
 <url:https://codeforces.com/problemset/problem/1358/D>
 問題文============================================================
 D. The Best Vacation
 =================================================================
 解説=============================================================
 ================================================================
 */

template <class Type>
Type solve(Type res = Type()) {
  ll n, x;
  cin >> n >> x;
  vector<ll> d(n);
  for (auto& in : d) cin >> in;
  for(int i = 0; i < n;i++) d.emplace_back(d[i]);

  ll sz = d.size();
  ll l = 0, r = 0;
  ll sum = 0;
  ll sumd = 0;
  // [l,r) := rは末尾まで含み、lを一部含むとした時
  while (true) {
    while (r < sz && sumd + d[r] < x) {
      sumd += d[r];
      sum += d[r] * (d[r] + 1) / 2;
      r++;
    }
    if (r < sz) {
      sumd += d[r];
      sum += d[r] * (d[r] + 1) / 2;
      r++;
    }
    if (sumd < x) break;
    while (sumd - d[l] > x) {
      sumd -= d[l];
      sum -= d[l] * (d[l] + 1) / 2;
      l++;
    }
    ll val = sum - (sumd - x) * (sumd - x + 1) / 2;
    res = max(res, val);
    // cout << l << " " << r << " : " << val << endl;

    sumd -= d[l];
    sum -= d[l] * (d[l] + 1) / 2;
    l++;
  }

  return res;
}
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // solve<ll>(0);
  cout << fixed << setprecision(12) << solve<ll>() << endl;
  return 0;
}