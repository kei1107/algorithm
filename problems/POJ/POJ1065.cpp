#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/
#define MAX_N 5000

pii lw[MAX_N];
bool f[MAX_N];

int main(void) {
    int kassa;
    scanf("%d",&kassa);
    for(int kinogassa = 0; kinogassa < kassa; kinogassa++){
        fill(f,f+MAX_N,false);
        int N; scanf("%d",&N);
        for(int i = 0; i < N;i++){
            scanf("%d%d",&lw[i].first,&lw[i].second);
        }
        sort(lw,lw+N);
        
        int ans = 0;
        for(int i = 0; i < N;i++){
            if(f[i]) continue;
            f[i] = true;
            ans++;
            int idx = i;
            for(int j = i+1;j < N;j++){
                if(f[j]) continue;
                if(lw[idx].second <= lw[j].second){
                    f[j] = true;
                    idx = j;
                }
            }
        }
        cout << ans << endl;
    }
	return 0;
}
