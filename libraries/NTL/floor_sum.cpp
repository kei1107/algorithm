/*
 * Σ_{i=0}^{n-1} floor((a*i + b)/m) を計算する
 * 0 <= n <= 1e9
 * 1 <= m <= 1e9
 * 0 <= a,b < m
 * O(log(n+m+a+b))
 */
ll floor_sum(ll n, ll m, ll a, ll b) {
    ll ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    ll y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}




// verified : https://atcoder.jp/contests/practice2/tasks/practice2_c
template <class Type>
Type solve(Type res = Type()) {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    return res = floor_sum(n, m, a, b);
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // solve<ll>(0);
    int t;
    cin >> t;
    while (t--) cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}
