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
class ChocolateDividingEasy {
public:
    int calc(int ly,int lx,int uy,int ux,vector<vector<int>>& cusum){
        return cusum[uy][ux] - cusum[uy][lx-1] - cusum[ly-1][ux] + cusum[ly-1][lx-1];
    }
    int findBest(vector <string> chocolate) {
        int res = 0;
        int h = (int)chocolate.size(),w = (int)chocolate[0].size();
        vector<vector<int>> cusum(h+1,vector<int>(w+1,0));
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w;j++){
                cusum[i][j] = cusum[i-1][j] + cusum[i][j-1] - cusum[i-1][j-1] + (chocolate[i-1][j-1] - '0');
            }
        }
        
        for(int y1 = 1; y1 <= h; y1++){
            for(int x1 = 1; x1 <= w; x1++){
                
                for(int y2 = y1+1; y2 <= h; y2++){
                    for(int x2 = x1+1; x2 <= w; x2++){
                        
                        res = max(res,min({
                            calc(1,1,y1,x1,cusum),
                            calc(1,x1+1,y1,x2,cusum),
                            calc(1,x2+1,y1,w,cusum),
                            calc(y1+1,1,y2,x1,cusum),
                            calc(y1+1,x1+1,y2,x2,cusum),
                            calc(y1+1,x2+1,y2,w,cusum),
                            calc(y2+1,1,h,x1,cusum),
                            calc(y2+1,x1+1,h,x2,cusum),
                            calc(y2+1,x2+1,h,w,cusum)
                        }));
                    }
                }
            }
        }
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {
        "9768",
        "6767",
        "5313"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findBest(Arg0)); }
    void test_case_1() { string Arr0[] = {
        "36753562",
        "91270936",
        "06261879",
        "20237592",
        "28973612",
        "93194784"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(1, Arg1, findBest(Arg0)); }
    void test_case_2() { string Arr0[] = {
        "012",
        "345",
        "678"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, findBest(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    ChocolateDividingEasy ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
