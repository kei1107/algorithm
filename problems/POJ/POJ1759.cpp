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
#include <iomanip>
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
もっとも低い位置のランプの探索は式変形が面倒
 
 どこか一箇所のランプの高さを決め打ちして求められないか？
 Hi = (H i-1 + H i+1)/2 - 1, for all 1 < i < N
 
 から ある一箇所の高さが高くなると　自然とBも高くなる。
 連鎖的に場所を求めることができるのはH2
 
 H2の高さでにぶたんしていく
================================================================
*/

ll N;
double A;
double B = -1;
bool ok(double m){
    double preH = A;
    double H = m;
    for(int i = 2; i < N;i++){
        double next = 2*(H+1) - preH;
        if(next < 0) return false;
        preH = H;
        H = next;
    }
    B = H;
    return true;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> A;
    
    double l = 0, r = INF;
    for(int i = 0; i < 100;i++){
      //  cout << l << " " << r << endl;
        double m = (l+r)/2;
        if(ok(m)){
            r = m;
        }else{
            l = m;
        }
    }
    ok(r);
    cout << fixed << setprecision(2) << B << endl;
	return 0;
}
