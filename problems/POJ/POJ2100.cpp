#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF (1<<30)
#define LINF (1LL<<60)

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ull n; cin >> n;
    ull l = 0,r = 0,Sum = 0;
    vector<vector<ull> > Ans;
    while(true){
        while(r*r <= n && Sum < n){
            r++;
            Sum += r*r;
        }
        if(Sum < n) break;
        if(Sum == n){
            Ans.push_back(vector<ull>(r-l,0));
            for(int i = l+1; i <= r;i++){
                Ans[Ans.size()-1][i-(l+1)] = i;
            }
        }
        ++l;
        Sum -= l*l;
    }
    
    cout << Ans.size() << endl;
    for(int i = 0; i < (int)Ans.size();i++){
        cout << Ans[i].size();
        for(int j = 0; j < (int)Ans[i].size();j++){
            cout << " " << Ans[i][j];
        }
        cout << endl;
    }
	return 0;
}
