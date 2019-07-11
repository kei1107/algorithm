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


// example
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<ll> > A(N, vector<ll>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    BIT2D B(A);
    int Q;
    cin >> Q;
    for (;Q--;) {
        int op, x1, y1, x2, y2;
        cin >> op >> x1 >> y1 >> x2 >> y2;
        if (op == 1) {
            ll v;
            cin >> v;
            B.rangeUpdate(x1, y1, x2, y2, v);
        } else {
            cout << B.rangeQuery(x1, y1, x2, y2) << "\n";
        }
    }
    return 0;
}
