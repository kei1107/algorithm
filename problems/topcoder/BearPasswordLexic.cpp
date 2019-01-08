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
class BearPasswordLexic {
public:
    string findPassword(vector <int> x) {
        string res;
        int n = (int)x.size();
        vector<int> sec;
        for(int i = n-1;i>=0;){
            if(x[i]==0) { i--; continue; }
            if(x[i]<0) return "";
            sec.push_back(i+1);
            for(int j = 0; j <= i;j++){
                x[j] -= i-j+1;
            }
        }
        sort(sec.rbegin(),sec.rend());
        deque<int> dq(sec.begin(),sec.end());
        int cnt = 0;
        while(dq.size()){
            int v = cnt%2==0?dq.front():dq.back();
            if(cnt%2==0) dq.pop_front();
            else dq.pop_back();
            res += string(v,cnt%2==0?'a':'b');
            cnt++;
        }
        if(res.length()!=n) return "";
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {5,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ababa"; verify_case(0, Arg1, findPassword(Arg0)); }
    void test_case_1() { int Arr0[] = {4,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaab"; verify_case(1, Arg1, findPassword(Arg0)); }
    void test_case_2() { int Arr0[] = {3,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(2, Arg1, findPassword(Arg0)); }
    void test_case_3() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaa"; verify_case(3, Arg1, findPassword(Arg0)); }
    void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(4, Arg1, findPassword(Arg0)); }
    void test_case_5() { int Arr0[] = {4,0,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(5, Arg1, findPassword(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    BearPasswordLexic ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
