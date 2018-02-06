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
 <url:http://poj.org/problem?id=1930>
 問題文============================================================
 小数が与えられる．循環小数と見たとき，分母が最も小さくなる分数表示を求める．
 =================================================================
 
 解説=============================================================
 
 数学
 
 循環する区間を仮定して分数に直すという操作を繰り返す
 n桁の循環する小数は，"循環する部分/(10^n-1)"で得られる．
 
 ================================================================
 */

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string s;
    while(cin >> s){
        if(s == "0")break;
        s = s.substr(2,s.size() - 5);
        
        ll p,q,v,w,g;
        p = q = LINF;
        v = w = 1;
        for(int i = 0; i < s.size(); i++) w*=10;
        for(int i = 0; i < s.size(); i++){
            ll a,b,c,d;
            if(i == 0) a = 0;
            else sscanf(s.substr(0,i).c_str(),"%lld",&a);
            b = v;
            sscanf(s.substr(i).c_str(),"%lld",&c);
            d = w - 1;
            
            g = gcd(a,b); a /= g; b /= g;
            g = gcd(c,d); c /= g; d /= g;
            g = gcd(c,v); c /= g; d *= v/g;
            g = gcd(b,d); a = a*(d/g) + c*(b/g); b = b/g*d;
            g = gcd(a,b); a/= g; b/= g;
            if(b < q){ p = a; q = b;}
            
            v*=10; w/=10;
        }
        cout << p << "/" << q << endl;
    }
    return 0;
}
