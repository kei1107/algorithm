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
 priority-queueでの貪欲
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int C,L; cin >> C >> L;
    vector<pii> SPF(C);
    vector<pii> SPF_c(L);
    for(int i = 0; i < C;i++) cin >> SPF[i].first >> SPF[i].second;
    for(int i = 0; i <L;i++) cin >> SPF_c[i].first >> SPF_c[i].second;
    sort(SPF.begin(),SPF.end());
    sort(SPF_c.begin(),SPF_c.end());
    
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    
    int id = 0;
    int ans = 0;
    for(int i = 0; i < L;i++){
        for(; id < C;id++){
            if(SPF_c[i].first >= SPF[id].first){
                pq.push(make_pair(SPF[id].second, SPF[id].first));
            }else{
                break;
            }
        }
        while(SPF_c[i].second!=0 && !pq.empty()){
            pii tp = pq.top(); pq.pop();
            if(tp.first < SPF_c[i].first)continue;
            ans++;
            SPF_c[i].second--;
        }
    }
    cout << ans << endl;
    return 0;
}
