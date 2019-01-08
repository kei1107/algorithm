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
const int INF = 1e9;
const ll LINF = 1e18;

const ll MOD = 1e9+7;
ll dp[201][201][201];
class BearCries {
public:
    int count(string message) {
        fill(**dp,**dp+201*201*201,0);
        int res = 0;
        int n = (int)message.length();
        
        dp[0][0][0] = 1;
        for(int i = 0; i < n;i++){
            for(int j = 0; j <= n;j++){
                for(int k = 0; k <= n;k++){
                    if(dp[i][j][k]==0) continue;
                    if(message[i] == '_'){
                        if(j) (dp[i+1][j-1][k+1] += j*dp[i][j][k])%=MOD;
                        if(k) (dp[i+1][j][k] += k*dp[i][j][k])%=MOD;
                    }else{
                        (dp[i+1][j+1][k] += dp[i][j][k])%=MOD;
                        if(k)(dp[i+1][j][k-1] += k*dp[i][j][k])%=MOD;
                    }
                }
            }
        }
        res = (int)dp[n][0][0];
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = ";_;;_____;"; int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
    void test_case_1() { string Arg0 = ";;;___;;;"; int Arg1 = 36; verify_case(1, Arg1, count(Arg0)); }
    void test_case_2() { string Arg0 = "_;__;"; int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
    void test_case_3() { string Arg0 = ";_____________________________________;"; int Arg1 = 1; verify_case(3, Arg1, count(Arg0)); }
    void test_case_4() { string Arg0 = ";__;____;"; int Arg1 = 0; verify_case(4, Arg1, count(Arg0)); }
    void test_case_5() { string Arg0 = ";_;;__;_;;"; int Arg1 = 52; verify_case(5, Arg1, count(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    BearCries ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
