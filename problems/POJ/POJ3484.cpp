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
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:>
 問題文============================================================
 
 =================================================================
 
 解説=============================================================
 ある値 mに注目した時m以下の個数が偶数かどうかでにぶたんできる
 ================================================================
 */
char buf[1025];
int N;
vector<ll> X,Y,Z;

bool init(){
    int f = 0;
    N = 0;
    while((f = ((gets(buf)!=NULL))) && strlen(buf) > 2){
        ll x,y,z;
        sscanf(buf, "%lld%lld%lldx", &x, &y, &z);
        N++;
        X.push_back(x); Y.push_back(y); Z.push_back(z);
    }
    return f || N > 0;
}

bool ok(ll m){
    ll cnt = 0;
    for(int i = 0; i < N;i++){
        if(X[i] > m) continue;
        cnt += (min(Y[i],m) - X[i])/Z[i] + 1;
    }
    return (cnt%2 == 0);
}

void solve(){
    if(N == 0) return;
    ll l = 0, r = LINF;
    if(ok(r)){
        cout << "no corruption" << endl;
        return ;
    }
    
    while(r - l > 1){
       // cout << l << " " << r << endl;
        ll m = (l+r)/2;
        if(ok(m)){
            l = m;
        }else{
            r = m;
        }
    }
    int cnt = 0;
    for(int i = 0; i < N;i++){
        if(X[i] > r || r > Y[i]) continue;
        if((r-X[i])%Z[i] == 0) cnt++;
    }
    cout << r << " " << cnt << endl;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    while(init()){
        solve();
        X.clear(); Y.clear(); Z.clear();
    }
    return 0;
}
