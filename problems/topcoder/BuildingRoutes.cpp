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
class BuildingRoutes {
public:
    int build(vector <string> dist, int T) {
        int res = 0;
        int n = (int)dist.size();
        vector<vector<int>> sdist(n,vector<int>(n));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(i == j) sdist[i][j] = 0;
                else sdist[i][j] = dist[i][j]-'0';
            }
        }
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                for(int k = 0; k < n;k++){
                    sdist[j][k] = min(sdist[j][k],sdist[j][i] + sdist[i][k]);
                }
            }
        }
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(i == j) continue;
                
                int C = 0;
                for(int k = 0; k < n;k++){
                    for(int l = 0; l < n;l++){
                        if(k == l) continue;
                        
                        if(sdist[k][i] + (dist[i][j] - '0') + sdist[j][l] == sdist[k][l]) C++;
                    }
                }
                if(C >= T) res += dist[i][j] - '0';
            }
        }
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"011",
        "101",
        "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(0, Arg2, build(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"033",
        "309",
        "390"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 12; verify_case(1, Arg2, build(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"0123",
        "1023",
        "1203",
        "1230"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; verify_case(2, Arg2, build(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"05789654",
        "10347583",
        "65085479",
        "55602398",
        "76590934",
        "57939045",
        "12345608",
        "68647640"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 40; verify_case(3, Arg2, build(Arg0, Arg1)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    BuildingRoutes ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
