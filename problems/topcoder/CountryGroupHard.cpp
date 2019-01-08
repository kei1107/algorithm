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

int memo[101][101];
class CountryGroupHard {
public:
    int rec(int l,int r,const int n,const vector<int>& a){
        int &ret = memo[l][r];
        if(l>=r) return 1;
        if(~ret) return ret;
        
        int target = l;
        for(; target < r;target++){ if(a[target]) break; }
        if(target == r) return ret = min(2,r-l);
        
        ret = 0;
        for(int i = target-a[target]+1; i <= target; i++){
            bool ok = true;
            for(int j = i; j < i+a[target];j++){
                if(j < l || j >= r) ok = false;
                else{
                    if(a[j]==0) continue;
                    if(a[j]==a[target]) continue;
                    ok = false;
                }
            }
            if(ok){
                ret += min(2,rec(l,i,n,a)*rec(i+a[target],r,n,a));
            }
        }
        return ret;
    }
    string solve(vector <int> a) {
        fill(*memo,*memo+101*101,-1);
        int n = (int)a.size();
        if(rec(0,n,n,a)==1) return "Sufficient";
        else return "Insufficient";
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {0,2,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(0, Arg1, solve(Arg0)); }
    void test_case_1() { int Arr0[] = {0,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(1, Arg1, solve(Arg0)); }
    void test_case_2() { int Arr0[] = {0,3,0,0,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(2, Arg1, solve(Arg0)); }
    void test_case_3() { int Arr0[] = {0,0,3,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(3, Arg1, solve(Arg0)); }
    void test_case_4() { int Arr0[] = {2,2,0,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(4, Arg1, solve(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    CountryGroupHard ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
