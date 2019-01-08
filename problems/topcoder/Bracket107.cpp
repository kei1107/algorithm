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


class Bracket107 {
public:
    int yetanother(string s) {
        int res = 0;
        int n = (int)s.length();
        set<string> st;
        
        for(int i = 0; i < n;i++){
            string t = s;
            
            char c = t[i];
            t.erase(t.begin()+i);
            
            for(int j = 0; j < t.length();j++){
                string tt = t;
                tt.insert(j,string(1,c));
                
                bool ok = true;
                stack<char> stk;
                for(int k = 0; k < t.length();k++){
                    if(tt[k]=='(') stk.push(tt[k]);
                    else{
                        if(stk.empty()){
                            ok = false;
                            break;
                        }
                        stk.pop();
                    }
                }
                if(ok) st.insert(tt);
            }
        }
        
        st.erase(s);
        res = (int)st.size();
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "(())"; int Arg1 = 1; verify_case(0, Arg1, yetanother(Arg0)); }
    void test_case_1() { string Arg0 = "(())()"; int Arg1 = 3; verify_case(1, Arg1, yetanother(Arg0)); }
    void test_case_2() { string Arg0 = "()()()"; int Arg1 = 3; verify_case(2, Arg1, yetanother(Arg0)); }
    void test_case_3() { string Arg0 = "(((())))"; int Arg1 = 5; verify_case(3, Arg1, yetanother(Arg0)); }
    void test_case_4() { string Arg0 = "((())())"; int Arg1 = 9; verify_case(4, Arg1, yetanother(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    Bracket107 ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
