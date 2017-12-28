#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/
vector<int> prime;

void Prime() {
    prime.emplace_back(2);
    for (int i = 3; i <= 999999; i += 2) {
        bool f = false;
        for (int j = 3; j <= sqrt(i); j += 2) {
            if (i%j == 0) {
                f = true;
                break;
            }
        }
        if (!f) prime.emplace_back(i);
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    Prime();
    int n;
    while (cin >> n) {
        cout << upper_bound(prime.begin(), prime.end(), n) - prime.begin() << endl;
    }
}
