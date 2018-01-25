#include "bits/stdc++.h"
using namespace std;
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444&lang=jp
typedef long long ll;
typedef unsigned long long ull;
const ull B = 100000007;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<ull> H(n + 1,0), b(n + 1, 1);
    set<ull> Ans;
    /*
     rolling-hash algorithm
     initialize
     b[n] := B^n
     H[n] := s[0]*b^(n-1) + s[1]*b^(n-2) +... +s[n-1]*b^0
     */
    for (int i = 0; i < n;i++) {
        b[i + 1] = b[i] * B;
        H[i + 1] = H[i] * B + s[i];
    }
    
    int l, r; l = r = 0;
    for (int k = 0; k < m;k++) {
        string q; cin >> q;
        if (q == "L++") l++;
        else if (q == "L--") l--;
        else if (q == "R++") r++;
        else r--;
        ull _hash = H[r + 1] - H[l] * b[r - l + 1];
        Ans.insert(_hash);
    }
    cout << Ans.size() << endl;
    return 0;
}
