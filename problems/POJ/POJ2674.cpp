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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF (1<<30)
#define LINF (1LL<<60)

/*
<url:http://poj.org/problem?id=2674>
問題文============================================================
 線分の上を物体がある方向に向かって動く．2つの物体が衝突すると反対に動く．
 一番最後に落ちる物体の名前とその時間を求める．
=================================================================

解説=============================================================
ある物体が他の物体と衝突してそれぞれ反対を向いても、
 互いに区別しなければ、互いにその場所を通り過ぎたとみなすことができるため
 最長時間についてはO(N)で求まる
 
 また、誰が、最後になるかについては、最長時間の位置からシュミレーションすればよい
 
 最長時間を要する位置にいる人の向きが右向きの時、最後に落ちる人は
 その人よりもみぎにいる人かつ左を向いている人の分だけずらした人となる
================================================================
*/

int dir[32005];
double pos[32005];
char name[32005][300];

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n;
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        double L,V;
        scanf("%lf%lf",&L,&V);
        for(int i = 0; i < n;i++){
            char buf[10];
            scanf("%s%lf%s",buf,&pos[i],name[i]);
            buf[0] = tolower(buf[0]);
            if(buf[0] == 'p') dir[i] = 1;
            else dir[i] = -1;
        }
        double Max = -1;
        int MaxIdx = -1;
        for(int i = 0; i < n;i++){
            if(dir[i] == 1){
                double t = (L - pos[i])/V;
                if(t > Max){
                    Max = t;
                    MaxIdx = i;
                }
            }else{
                double t = pos[i]/V;
                if(t > Max){
                    Max = t;
                    MaxIdx = i;
                }
            }
        }
        if(dir[MaxIdx] == 1){
            for(int i = MaxIdx + 1; i < n;i++){
                if(dir[i] == -1) MaxIdx++;
            }
        }else{
            for(int i = MaxIdx -1 ; i>= 0;i--){
                if(dir[i] == 1) MaxIdx--;
            }
        }
        printf("%13.2f %s\n",(int)(Max*100)/100.0,name[MaxIdx]);
    }
	return 0;
}
