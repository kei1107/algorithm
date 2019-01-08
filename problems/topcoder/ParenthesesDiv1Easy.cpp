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


class ParenthesesDiv1Easy {
public:
    vector <int> correct(string s) {
        if(s.length()%2==1) return vector<int>{-1};
        vector<int> res;
        
        int n = (int)s.length();
        vector<pair<char,int>> si;
        for(int i = 0; i < n;i++){
            if(si.size() && si.back().first=='(' && s[i]==')') si.pop_back();
            else si.push_back({s[i],i});
        }
        
        if(si.empty()) return res;
        int m = 0; for(; m < si.size();m++) if(si[m].first=='(') break;
        if(m){
            res.push_back(si.front().second); res.push_back(si[m-1].second);
            int l = si.front().second,r = si[m-1].second;
            for(int i = 0; i < m;i++) si[i].second = r -(si[i].second-l);
            reverse(si.begin(), si.begin()+m);
        }
        res.push_back(si[si.size()/2].second);
        res.push_back(si.back().second);
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { string Arg0 = ")("; int Arr1[] = {0, 0, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, correct(Arg0)); }
    void test_case_1() { string Arg0 = "))))))(((((("; int Arr1[] = {0, 5, 6, 11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, correct(Arg0)); }
    void test_case_2() { string Arg0 = "))()())()"; int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, correct(Arg0)); }
    void test_case_3() { string Arg0 = ")()((("; int Arr1[] = {0, 0, 3, 3, 5, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, correct(Arg0)); }
    void test_case_4() { string Arg0 = "()"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, correct(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    ParenthesesDiv1Easy ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
