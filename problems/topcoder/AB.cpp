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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
const int INF = 1e9;
const ll LINF = 1e18;
class AB{
public:
    string createString(int N,int K){
        string res;
        if(K == 0) return string(N,'A');
        for(int B = 1; B <= K;B++){
            int A = K/B;
            int oneA = K - K/B*B;
            
            if(B+A+(oneA!=0) <= N){
                int left = N - (B+A+(oneA!=0));
                
                res += string(left,'A');
                if(oneA){
                    res += string(oneA,'B');
                    res += string(1,'A');
                    res += string(B-oneA,'B');
                }else{
                    res += string(B,'B');
                }
                res += string(A,'A');
                reverse(res.begin(), res.end());
                return res;
            }
        }
        return res;
    }
};
