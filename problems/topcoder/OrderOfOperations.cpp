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
class OrderOfOperations {
public:
    int minTime(vector <string> s) {
        int res = 0;
        int n = (int)s.size(),m = (int)s[0].size();
        vector<int> bit(n);
        
        int B = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++) bit[i] += (s[i][j]=='1')<<j;
            B |= bit[i];
        }
        vector<int> dp(1<<m,INF);
        dp[0] = 0;
        for(int i = 0; i < (1<<m);i++){
            if(dp[i]==INF) continue;
            for(int j = 0; j < n;j++){
                int cnt = 0;
                for(int k = 0; k < m;k++){
                    if(!((i>>k)&1) && ((bit[j]>>k)&1)){
                        cnt++;
                    }
                }
                dp[i|bit[j]] = min(dp[i|bit[j]],dp[i]+cnt*cnt);
            }
        }
        res = dp[B];
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {
        "111",
        "001",
        "010"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minTime(Arg0)); }
    void test_case_1() { string Arr0[] = {
        "11101",
        "00111",
        "10101",
        "00000",
        "11000"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, minTime(Arg0)); }
    void test_case_2() { string Arr0[] = {
        "11111111111111111111"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 400; verify_case(2, Arg1, minTime(Arg0)); }
    void test_case_3() { string Arr0[] = {
        "1000",
        "1100",
        "1110"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minTime(Arg0)); }
    void test_case_4() { string Arr0[] = {
        "111",
        "111",
        "110",
        "100"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, minTime(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    OrderOfOperations ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
