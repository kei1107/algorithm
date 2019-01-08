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
class RepeatString {
public:
    
    int leven(const string s1,const string s2){
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, INF));
        
        /* dp[i][j] := 文字列s1[0..(i-1)] から 文字列s2[0..(j-1)]の編集距離 ( 添え字0はヌル ) */
        dp[0][0] = 0;
        for (int i = 1; i <= s1.length();i++) dp[i][0] = i;
        for (int j = 1; j <= s2.length(); j++) dp[0][j] = j;
        
        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                dp[i][j] = min({
                    dp[i][j - 1] + 1,
                    dp[i - 1][j] + 1,
                    dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])
                });
            }
        }
        return dp[s1.length()][s2.length()];
    }
    int minimalModify(string s) {
        int n = (int)s.length();
        int res = n;
        for(int i = 0; i < n;i++){
            string s1 = s.substr(0,i);
            string s2 = s.substr(i);
            
            res = min(res,leven(s1,s2));
        }
        
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "aba"; int Arg1 = 1; verify_case(0, Arg1, minimalModify(Arg0)); }
    void test_case_1() { string Arg0 = "adam"; int Arg1 = 1; verify_case(1, Arg1, minimalModify(Arg0)); }
    void test_case_2() { string Arg0 = "x"; int Arg1 = 1; verify_case(2, Arg1, minimalModify(Arg0)); }
    void test_case_3() { string Arg0 = "aaabbbaaaccc"; int Arg1 = 3; verify_case(3, Arg1, minimalModify(Arg0)); }
    void test_case_4() { string Arg0 = "repeatstring"; int Arg1 = 6; verify_case(4, Arg1, minimalModify(Arg0)); }
    void test_case_5() { string Arg0 = "aaaaaaaaaaaaaaaaaaaa"; int Arg1 = 0; verify_case(5, Arg1, minimalModify(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    RepeatString ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
