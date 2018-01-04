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
#define INF (1<<30)
#define LINF (1LL<<60)

/*
 <url:>
 問題文============================================================
 
 =================================================================
 
 解説=============================================================
 長方形の選び方は最大でもnC2
 先に全ての選び方をリストアップしておき
 dp[i][S] := i番目の長方形をみたとき、点Sが含まれている時の総数
 でdpすれば良い(配列は使いまわせる)
 ================================================================
 */

struct rect{
    int S;
    int Area;
    rect(){}
    rect(int S,int Area):S(S),Area(Area){}
};

bool ok(pii& p,int minx,int miny,int maxx,int maxy){
    return (p.first <= maxx && p.first >= minx) && (p.second <= maxy && p.second >= miny);
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector<pii> ps(n);
        for(int i = 0; i < n;i++) cin >> ps[i].first >> ps[i].second;
        vector<rect> Rect;
        for(int i = 0; i < n;i++){
            for(int j = i+1; j < n;j++){
                int minx = min(ps[i].first,ps[j].first),maxx = max(ps[i].first,ps[j].first);
                int miny = min(ps[i].second,ps[j].second),maxy = max(ps[i].second,ps[j].second);
                int S = 0;
                for(int k = 0; k < n;k++){
                    if(ok(ps[k],minx,miny,maxx,maxy)){
                        S |= (1<<k);
                    }
                }
                Rect.push_back(rect(S,max(1,(maxx-minx))*max(1,(maxy-miny))));
            }
        }
        
        vector<ll> dp(1<<n,LINF);
        dp[0] = 0;
        for(int i = 0; i < (int)Rect.size();i++){
            for(int j = 0; j < (1<<n);j++){
                if(dp[j] == LINF) continue;
                dp[j|Rect[i].S] = min(dp[j|Rect[i].S],dp[j] + Rect[i].Area);
            }
        }
        cout << dp[(1<<n)-1] << endl;
    }
    return 0;
}
