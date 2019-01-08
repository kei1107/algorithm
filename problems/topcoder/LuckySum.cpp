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


ll dp[15][2][3];
class LuckySum {
public:
    long long construct(string note) {
        fill(**dp,**dp+15*2*3,LINF);
        ll res = 0;
        reverse(note.begin(),note.end());
        int  n = (int)note.size();
        vector<ll> pow10(n+1);
        pow10[0] = 1; for(int i = 1; i <= n;i++) pow10[i] = pow10[i-1]*10;
        
        dp[0][0][2] = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < 2;j++){
                for(int k = 0; k < 3;k++){
                    if(dp[i][j][k]==LINF) continue;
                    
                    char c = note[i];
                    if(isdigit(c)) c -= '0';
                    if(k==2){
                        if(c=='?'||c==j+4+4) dp[i+1][0][2]=min(dp[i+1][0][2],dp[i][j][k]+8*pow10[i]);
                        if(c=='?'||c==(j+4+7)%10) dp[i+1][1][2]=min(dp[i+1][1][2],dp[i][j][k]+11*pow10[i]);
                        if(c=='?'||c==(j+7+7)%10) dp[i+1][1][2]=min(dp[i+1][1][2],dp[i][j][k]+14*pow10[i]);
                        
                    }
                    if(i!=0){
                        if(k>=1){
                            if(c=='?'||c==j+4) dp[i+1][0][1]=min(dp[i+1][0][1],dp[i][j][k]+4*pow10[i]);
                            if(c=='?'||c==j+7) dp[i+1][0][1]=min(dp[i+1][0][1],dp[i][j][k]+7*pow10[i]);
                        }
                        if(i==n-1 && j!=0){
                            if(c=='?'||c==j) dp[i+1][0][0]=min(dp[i+1][0][0],dp[i][j][k]);
                        }
                    }
                }
            }
        }
        
        res = min({dp[n][0][0],dp[n][0][1],dp[n][0][2]});
        if(res == LINF) res=  -1;
        return  res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "?"; long long Arg1 = 8LL; verify_case(0, Arg1, construct(Arg0)); }
    void test_case_1() { string Arg0 = "?1"; long long Arg1 = 11LL; verify_case(1, Arg1, construct(Arg0)); }
    void test_case_2() { string Arg0 = "4?8"; long long Arg1 = 448LL; verify_case(2, Arg1, construct(Arg0)); }
    void test_case_3() { string Arg0 = "2??"; long long Arg1 = -1LL; verify_case(3, Arg1, construct(Arg0)); }
    void test_case_4() { string Arg0 = "??????????????"; long long Arg1 = 11888888888888LL; verify_case(4, Arg1, construct(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    LuckySum ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
