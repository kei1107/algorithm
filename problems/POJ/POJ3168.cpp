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

struct line{
    int v;
    int l,r;
    int id;
    line(){}
    line(int v,int l,int r,int id):v(v),l(l),r(r),id(id){}
    
    bool operator < (const line& o) const{
        return (v != o.v)? v < o.v : l <= o.l;
    }
};

#define MAX_N 25000
line X[MAX_N*2],Y[MAX_N*2];
bool F[MAX_N];

int main(void) {
//	cin.tie(0); ios::sync_with_stdio(false);
    int N; scanf("%d",&N);
    
    for(int i = 0; i < N;i++){
        int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        X[2*i] = line(x1,y1,y2,i); X[2*i + 1] = line(x2,y1,y2,i);
        Y[2*i] = line(y1,x1,x2,i); Y[2*i + 1] = line(y2,x1,x2,i);
    }
    sort(X,X + 2*N);
    sort(Y,Y + 2*N);
    
    for(int i = 0; i < 2*N-1;){
        int v = X[i].v;
        int id = X[i].id;
        int maxr = X[i].r;
        for(i++; i < 2*N && X[i].v == v && X[i].l <= maxr;i++){
            F[id] = F[X[i].id] = true; maxr = max(maxr,X[i].r);
        }
    }
    for(int i = 0; i < 2*N-1;){
        int v = Y[i].v;
        int id = Y[i].id;
        int maxr = Y[i].r;
        for(i++; i < 2*N && Y[i].v == v && Y[i].l <= maxr;i++){
            F[id] = F[Y[i].id] = true; maxr = max(maxr,Y[i].r);
        }
    }
    int ans = 0;
    for(int i = 0; i < N;i++){
        if(F[i] == false){
            ans++;
        }
    }
    cout << ans << endl;
	return 0;
}
