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


ll dp[41][41];
class BracketSequenceDiv1 {
public:
    ll rec(int l,int r,const string& s){
        if(l >= r) return 1;
        ll& ret = dp[l][r];
        if(~ret) return ret;
        
        ret = rec(l+1,r,s);
        for(int i = l+1; i <= r;i++){
            if((s[l]=='(' && s[i]==')') || (s[l]=='[' && s[i]==']')){
                ret += rec(l+1,i-1,s)*rec(i+1,r,s);
            }
        }
        return ret;
    }
    long long count(string s) {
        fill(*dp,*dp+41*41,-1);
        int n = (int)s.length();
        return rec(0,n-1,s) - 1;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "()[]"; long long Arg1 = 3LL; verify_case(0, Arg1, count(Arg0)); }
    void test_case_1() { string Arg0 = "())"; long long Arg1 = 2LL; verify_case(1, Arg1, count(Arg0)); }
    void test_case_2() { string Arg0 = "()()"; long long Arg1 = 4LL; verify_case(2, Arg1, count(Arg0)); }
    void test_case_3() { string Arg0 = "([)]"; long long Arg1 = 2LL; verify_case(3, Arg1, count(Arg0)); }
    void test_case_4() { string Arg0 = "())[]][]([]()]]()]]]"; long long Arg1 = 3854LL; verify_case(4, Arg1, count(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    BracketSequenceDiv1 ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
